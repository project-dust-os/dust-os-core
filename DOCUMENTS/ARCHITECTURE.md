# Architecture

This document records what DUST-OS is meant to be, what it currently is, and
which decisions are still open. It is a living document: a decision that is
recorded here should not be silently contradicted by the code.

Status: **pre-alpha**. Nothing in this document describes working code unless it
says so explicitly.

---

## 1. What "hybrid" means in this project

A hybrid kernel keeps a monolithic core — scheduling, memory management, and IPC
live in kernel space and can call each other directly — but structures those
components behind interfaces that are narrow enough to be moved into user space
later without redesigning the system.

Concretely, DUST-OS commits to:

- **Monolithic first.** Components run in kernel space; no premature
  user-space servers.
- **Message-shaped interfaces.** Cross-component calls are designed as requests
  and replies with explicit ownership of buffers, so a component can later be
  placed behind an IPC channel.
- **No shared mutable state across component boundaries.** State is owned by one
  component and reached through its interface.

Hybrid is an architectural direction, not a feature. It does **not** mean mixing
Windows and Unix vocabulary in the source tree, and it is unrelated to
multithreading; threading is a scheduling concern.

Non-goals: microkernel purity, multi-server design, and binary compatibility
with other systems.

## 2. Boot chain

DUST-OS ships its own UEFI boot application, located in `boot/bootmgrc/`. That
application is the only supported boot path. It is currently a stub: it prints a
string and halts, and it does not load a kernel.

Because the boot path is in-house, the boot contract belongs to this project. It
must define, and eventually document precisely:

- the CPU mode and control-register state on entry to the kernel;
- the initial stack, and who owns it after handoff;
- the location and layout of the boot information structure (memory map,
  framebuffer, firmware tables);
- the ownership and lifetime of every memory region handed to the kernel.

That contract is the kernel's first ABI. Until it is written down, every change to
the boot application can silently break the kernel.

No third-party bootloader is bundled, required, or supported by this repository.
Early bring-up work may use tooling kept outside the repository; that tooling
creates no dependency on it and is not described here.

See [Open decisions](#10-open-decisions), D-1.

## 3. Component map (planned)

| Component | Location | Responsibility | State |
| --- | --- | --- | --- |
| Kernel executive (`ke`) | `kernel/ke/` | Threads, scheduling, locks, timers | Empty |
| Memory management | `kernel/mm/` | Physical frames, page tables, direct map | Empty; an unrelated draft sits under `boot/bootmgrc/src/mm/` |
| IPC | `kernel/ipc/` | Shared memory, message channels | Header-level design |
| Hardware abstraction (`hal`) | `hal/` | CPU, interrupt controller, timers | Empty |
| Drivers | `drivers/` | Block, input, display | Empty |
| Filesystems | `fs/` | On-disk formats and the VFS | Empty |
| Security | `security/` | Credentials, capabilities, policy | Empty |
| Compatibility | `compat/` | Syscall ABI, POSIX shims | Empty |
| Graphics | `gui/` | Framebuffer console, compositor | Empty |

The physical memory manager currently lives under the boot manager directory,
which is temporary; it belongs in the kernel once the boot path is settled.

## 4. Memory model (intended)

- **Higher-half kernel.** The kernel is linked into the upper canonical half of
  the address space; user space occupies the lower half.
- **Direct map.** All physical memory is mapped at a fixed offset so the kernel
  can reach any frame without changing page tables. The offset comes from the
  bootloader's HHDM (higher-half direct map) information, not from a hardcoded
  constant.
- **Physical allocator.** Frame bitmap or free-list, seeded from the bootloader
  memory map, with reserved regions marked for the kernel image, modules,
  framebuffer, and firmware tables.
- **Virtual allocator.** Per-address-space page tables, with a kernel half shared
  by all address spaces.

## 5. Execution model (intended)

- Ring 0 for the kernel, ring 3 for user space.
- Interrupts: IDT with exception handlers first, then a timer, then device IRQs.
  Legacy PIC while bringing the system up; local APIC later.
- Preemptive scheduling driven by the timer; no cooperative-only design.
- One kernel stack per thread; the x86-64 red zone is disabled globally, so
  interrupt entry does not need to account for it.

## 6. IPC model (intended)

Two primitives, in this order:

1. **Shared memory segments** — identified by a key, attachable by multiple
   address spaces, reference counted, with explicit page-level permissions.
2. **Message channels** — a small request/reply protocol with explicit buffer
   ownership, built on top of the shared-memory primitive.

Locking and reference counting come before either primitive: shared memory
without a correct refcount and a correct lock is a use-after-free generator. The
current `kernel/ipc/` headers exist but no implementation does.

## 7. Filesystems (intended)

`fs/` names three targets: `f2fs`, `ntfs`, and `wfs`. Implementing F2FS or NTFS
is a multi-month project on its own and both carry large, evolving on-disk
formats. The recommended order is:

1. `wfs` — a project-specific format, deliberately trivial, to exercise the VFS.
2. Read-only NTFS — useful for interoperability, read path only.
3. F2FS — only if there is a concrete reason; flash-specific features are not
   relevant to a hobby kernel running in QEMU.

## 8. Kernel coding constraints

- Freestanding C17, no libc.
- No floating point, no SIMD (SSE/MMX/AVX disabled at build time).
- No position-independent code; the kernel is linked at a fixed virtual address.
- No stack protector; no red zone.
- 80-column lines, hard tabs, enforced by `.clang-format`.

These are correctness constraints, not preferences.

## 9. Known technical debt

Recorded so it is not forgotten. None of these are fixed yet.

**Build system**

- `CMakeLists.txt` defines compiler flags but declares **no targets**, so
  configuring produces no output.
- The root build does not include any subdirectory; subprojects are unreachable.
- `boot/bootmgrc/CmakeLists.txt` is misnamed (CMake requires `CMakeLists.txt`)
  and calls `cmake_request_minimum`, which is not a CMake command.
- No linker script is wired into a link step; there is no entry symbol yet.
- Compiler flags are set globally instead of per target, and the toolchain is not
  pinned, so a host compiler such as MSVC would be picked up and reject them.

**Boot**

- The boot application is a UEFI hello-world that halts; it does not load a kernel.
- The boot contract (CPU state, initial stack, boot information layout, memory
  ownership) is not written down, so the kernel-side handoff cannot be implemented
  against it.

**Kernel headers**

- `kernel/include/defs.h` defines `size_t` and `uintptr_t` by hand with guard
  macros that do not match the compiler's, which risks redefinition errors.
- `intprt_t` is a misspelling of `intptr_t`; the correct type does not exist.
- Comments describing signed ranges are wrong ("64-bit signed 32-0-31").
- `vaddr_t` and `off_t` are 32-bit on a 64-bit target; addresses and file offsets
  above 4 GiB are silently truncated.
- `struct list_head` declares `prev` as a pointer to pointer and adds an
  unrelated `first` field; it cannot implement a doubly linked list as written.
- `bool` is only defined when `BOOLEAN` is defined, yet headers use `bool`
  unconditionally.
- `uid_t`/`gid_t` are 32-bit in `defs.h` but 16-bit in `struct inode`, and
  `nlink` is 16-bit although `nlink_t` is 64-bit.

**IPC**

- `kernel/ipc/ipc_shm.h` declares functions `static` in a header, so every
  translation unit that includes it gets an unused private copy; with
  `-Wunused-function -Werror` this fails the build.
- `kernel/ipc/shm.c` is truncated mid-declaration and cannot compile.
- Segment IDs are typed inconsistently across the API (`uint_t`, `sint_t`,
  `slong_t`); an unsigned return type cannot signal an error.
- `struct shm_segment` stores a pointer to `struct ipc_namespace` in a field named
  `next`, which models the ownership relation incorrectly.

**Other**

- `boot/bootmgrc/src/mm/pmm.c` is an unfinished draft: a loop bound is
  uninitialised and a non-void function has no return path.
- Many files are zero bytes, including `kernel/ke/*`, `kernel/ipc/util.h`,
  `boot/bootmgrc/src/drivers/*`, and several linker scripts and assembly files.
- Source files still carry Windows line endings in places; `.gitattributes`
  now normalises them.
- No CI, no test harness, no reproducible build instructions.

## 10. Open decisions

Each decision should be recorded here with a date and a one-paragraph rationale
when it is made.

**D-1. Boot contract.** Define the handoff contract between the boot application
and the kernel: entry state, boot information layout, and memory ownership.
Recommendation: publish it as a versioned header shared by both sides, and treat
any change to it as a breaking change.

**D-2. Target architecture.** x86-64 only, or x86-64 plus AArch64. Only x86-64 is
testable today. Recommendation: x86-64 only; delete `aarch64` placeholders.

**D-3. Kernel naming.** `ke/` follows Windows NT terminology while `inode`,
`vfs`, and `shm` follow Unix terminology. Pick one vocabulary for the executive
layer and keep it consistent.

**D-4. Error convention.** Negative error codes returned from functions, or a
thread-local `errno`. Mixing both produces APIs where callers cannot tell which
convention applies. Recommendation: negative return values in kernel space,
`errno` translation only at the syscall boundary.

**D-5. ID width.** Choose one signed type for all IPC identifiers and use it
everywhere, so that a single negative sentinel can mean failure.

**D-6. Filesystem order.** Confirm the `wfs` → read-only NTFS → F2FS order in
Section 7, or drop targets that will not be reached.

**D-7. Repository layout.** The working tree is root-level (`kernel/`, `boot/`,
`hal/`, `DOCUMENTS/`), while the git index still records an earlier `sys/` layout.
Finish the move in one commit that contains nothing else, then treat the layout as
settled.

## 11. References

- Intel 64 and IA-32 Architectures Software Developer's Manual, Volume 3.
- UEFI Specification, current version.
- ACPI Specification, current version.
- OSDev Wiki, for introductory material on paging, IDT, and the APIC.
