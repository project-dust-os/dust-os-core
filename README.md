# DUST-OS

![Status](https://img.shields.io/badge/status-pre--alpha-orange)
![Architecture](https://img.shields.io/badge/arch-x86__64-blue)
![License](https://img.shields.io/badge/license-proprietary-lightgrey)

An operating system written from scratch for x86-64, aiming at a hybrid kernel
architecture: a compact monolithic core today, with message-passing interfaces
designed so that components can move into user space later without a rewrite.

DUST-OS is an educational, single-maintainer project. It is not a fork of an
existing operating system, and it is not derived from Linux, Windows, or any
other kernel. It targets real x86-64 hardware and QEMU, and it is loaded by a
boot path built in this repository.

---

## Status

> **Pre-alpha.** DUST-OS does not boot yet. The build system declares compiler
> flags but no build targets, and the kernel is scaffolding: most subsystems are
> headers, stubs, or empty files. See
> [DOCUMENTS/ARCHITECTURE.md](DOCUMENTS/ARCHITECTURE.md#9-known-technical-debt)
> for the current technical debt list.

| Area | State |
| --- | --- |
| Build system | Flags only; no targets, no linker script wired up |
| Boot | In-house UEFI boot application under construction; not functional |
| Kernel core | Type definitions and scaffolding |
| Memory management | Empty directories; no allocator yet |
| Interrupts / scheduling | Not started |
| IPC | Header-level design only |
| Filesystems, drivers, user space | Placeholders |

## Public release

This repository is the private development tree. A curated subset — the kernel,
HAL, GUI, boot path, filesystems, security, and non-vendor drivers — is published
separately as a source-available release. Code outside that subset is not
published. The scope is recorded in
[DOCUMENTS/LICENSING.md](DOCUMENTS/LICENSING.md), the machine-readable allow-list
is [PUBLIC_PATHS.txt](PUBLIC_PATHS.txt), and the release procedure is in
[DOCUMENTS/PUBLISHING.md](DOCUMENTS/PUBLISHING.md).

## Goals

The project advances in this order. Nothing later starts before the step before
it is stable.

- [ ] Boot through the in-house UEFI boot application into a kernel entry point
      and halt cleanly.
- [ ] Framebuffer console: print text to the screen set up during boot.
- [ ] Physical memory manager driven by the boot memory map.
- [ ] Virtual memory: kernel page tables and a direct map of physical memory.
- [ ] Interrupts: IDT, exception handlers, legacy PIC or APIC, timer tick.
- [ ] Threads and a preemptive scheduler.
- [ ] System calls and a user-space address space.
- [ ] IPC: message passing plus shared memory.
- [ ] A read-only filesystem and a minimal shell.

## Non-goals (for now)

- Architectures other than x86-64.
- POSIX or Windows compatibility.
- Symmetric multiprocessing.
- Binary compatibility with existing operating systems.
- A graphical desktop.

## Repository layout

```
boot/          Boot path
  bootmgrc/      In-house UEFI boot application (work in progress)
kernel/        Kernel core
  include/       Shared kernel types and definitions
  mm/            Memory management
  io/            Port and memory-mapped I/O helpers
  ipc/           Inter-process communication
  ke/            Kernel executive: threads, scheduling, syscalls
  debug/         Debugging support
hal/           Hardware abstraction layer (placeholder)
drivers/       Device drivers (placeholder)
fs/            Filesystems: f2fs/, ntfs/, wfs/ (placeholder)
crypto/        Cryptographic primitives (placeholder)
security/      Security policy and capability model (placeholder)
compat/        Compatibility layers such as a POSIX ABI (placeholder)
gui/           Graphics and compositing (placeholder)
firmware/      Firmware tables and blobs (placeholder)
test/          Tests and test harnesses (placeholder)
bin/           Reserved; purpose not yet decided
DOCUMENTS/     Project documentation
```

The repository is being reorganised, so tracked paths may lag behind the working
tree during a move. Commits that move files should contain nothing else.

## Boot path

DUST-OS is intended to ship its own UEFI boot application, located in
`boot/bootmgrc/`. That application is the only supported boot path. It is
currently a stub: it prints a string and halts, and it does not load a kernel.

Because the boot path is in-house, **the boot contract is part of the project and
must be documented here**: the CPU mode on entry, the location and contents of the
boot information structure, the initial stack, and the ownership of memory handed
to the kernel. That contract is the kernel's first ABI. It will be written down as
it stabilises.

No third-party bootloader is bundled, required, or supported by this repository.
Early bring-up experiments may use tooling kept outside the repository; that
tooling is not part of DUST-OS, is not distributed with it, and creates no
dependency on it.

The boot path decision is tracked in
[DOCUMENTS/ARCHITECTURE.md](DOCUMENTS/ARCHITECTURE.md#10-open-decisions).

## Building

> **Not functional yet.** There are no build targets, so configuring the project
> currently produces no output. This section describes the intended toolchain.

Intended toolchain:

| Tool | Purpose |
| --- | --- |
| Clang (target `x86_64-unknown-none`) | Compiles freestanding C and assembly |
| LLD (`ld.lld`) | Links the kernel with a custom linker script |
| CMake + Ninja | Drives the build |
| QEMU with EFI firmware | Primary test environment |
| UEFI firmware | Loads the boot application |

The compiler is used in freestanding mode with position-independent code
disabled, the x86-64 red zone disabled, and floating point/SIMD code generation
disabled. See `CMakeLists.txt` for the exact flag set.

## Contributing

Contributions are welcome, but this is a proprietary project: submitting a
contribution assigns copyright in it to the maintainer and carries a correctness
warranty. Read [CONTRIBUTING.md](CONTRIBUTING.md), [CLA.md](CLA.md), and Section 5
of [LICENSE](LICENSE) before opening a pull request.

## Security

Do not report security issues in public issues. See [SECURITY.md](SECURITY.md).

## License

DUST-OS is **source-available and proprietary**. It is **not** open source.

| Action | Permitted |
| --- | --- |
| Read and study the source | Yes |
| Build and run locally for personal study | Yes |
| Quote short excerpts with attribution | Yes |
| Copy code into another project | No |
| Modify, fork, or publish derivative works | No |
| Distribute the source or binaries | No |
| Commercial use | No |
| Use as training data for AI models | No |

See [LICENSE](LICENSE) for the binding terms, [COPYRIGHT.md](COPYRIGHT.md) for
ownership, and [NOTICE](NOTICE) for third-party components and code of unresolved
provenance.

Contributions to the public release require the Contributor License Agreement in
[CLA.md](CLA.md). The published subset uses the same license as the private tree.
See [DOCUMENTS/LICENSING.md](DOCUMENTS/LICENSING.md) for the publication scope and
[DOCUMENTS/PUBLISHING.md](DOCUMENTS/PUBLISHING.md) for how a release is produced.

## Acknowledgements

- The [OSDev Wiki](https://wiki.osdev.org) and the Intel SDM, for the reference
  material this project is learned from.
- The UEFI and ACPI specifications, for the interfaces implemented here.

DUST-OS is not affiliated with, endorsed by, or sponsored by any of the above.
