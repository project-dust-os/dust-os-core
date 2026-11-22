# DUST-OS

![Status](https://img.shields.io/badge/status-pre--alpha-orange)
![Architecture](https://img.shields.io/badge/arch-x86__64-blue)
![License](https://img.shields.io/badge/license-proprietary-lightgrey)
![Visibility](https://img.shields.io/badge/repository-private-black)

An operating system written from scratch for x86-64, aiming at a hybrid kernel
architecture: a compact monolithic core today, with message-passing interfaces
designed so that components can move into user space later without a rewrite.

DUST-OS is a private, proprietary project. It is not a fork of an existing
operating system, and it is not derived from Linux, Windows, or any other kernel.
It targets real x86-64 hardware and QEMU, and it is loaded by a boot path built in
this repository.

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

## Project model

DUST-OS is developed in a private repository and is intended to become a
commercial product. Its source code is not published, and it is **not open source
and not source-available**.

| Item | Policy |
| --- | --- |
| Repository | Private; access by named Authorised Persons only |
| Source code | Proprietary and confidential |
| Customer delivery | Binary artifacts and documentation under a commercial agreement |
| Third-party code | Allow-list only, recorded in [NOTICE](NOTICE) |
| Business model | Commercial licensing, support, and integration; see [DOCUMENTS/IP_POLICY.md](DOCUMENTS/IP_POLICY.md) |

Nothing in this repository grants a license to anyone. The binding terms are in
[LICENSE](LICENSE).

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
LEGAL/         Contract templates; not legal advice
```

The repository is being reorganised, so tracked paths may lag behind the working
tree during a move. Commits that move files should contain nothing else.

## Boot path

DUST-OS ships its own UEFI boot application, located in `boot/bootmgrc/`. That
application is the only supported boot path. It is currently a stub: it prints a
string and halts, and it does not load a kernel.

Because the boot path is in-house, **the boot contract is part of the project and
must be documented**: the CPU mode on entry, the location and contents of the
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

## Working on DUST-OS

The repository is private and every team member works under a signed IP
assignment and NDA. Start with:

- [CONTRIBUTING.md](CONTRIBUTING.md) — engineering handbook, branch rules, review,
  testing evidence;
- [DOCUMENTS/ARCHITECTURE.md](DOCUMENTS/ARCHITECTURE.md) — what the system is meant
  to be and what is currently broken;
- [DOCUMENTS/TEAM.md](DOCUMENTS/TEAM.md) — roles, onboarding, and hiring
  readiness;
- [DOCUMENTS/IP_POLICY.md](DOCUMENTS/IP_POLICY.md) — ownership, confidentiality,
  third-party code, and customer licensing.

## Security

Do not report security issues in an issue or pull request. See
[SECURITY.md](SECURITY.md) for the private channel and response targets.

## Documentation

| Document | Purpose |
| --- | --- |
| [DOCUMENTS/ARCHITECTURE.md](DOCUMENTS/ARCHITECTURE.md) | System design, technical debt, decisions D-1 to D-7 |
| [DOCUMENTS/IP_POLICY.md](DOCUMENTS/IP_POLICY.md) | Ownership, confidentiality, third-party code, licensing, decisions D-8 to D-18 |
| [DOCUMENTS/RELEASE_PROCESS.md](DOCUMENTS/RELEASE_PROCESS.md) | Versioning, quality gates, signing, distribution, rollback |
| [DOCUMENTS/TEAM.md](DOCUMENTS/TEAM.md) | Roles, team size, onboarding, hiring readiness |
| [DOCUMENTS/BRAND.md](DOCUMENTS/BRAND.md) | Brand usage, claims policy, public communication |
| [DOCUMENTS/README.md](DOCUMENTS/README.md) | Documentation index and decision index |
| [LEGAL/README.md](LEGAL/README.md) | Contract templates and execution rules |

## License

DUST-OS is **proprietary and confidential**. It is **not** open source and it is
**not** source-available.

| Action | Permitted |
| --- | --- |
| Access without a written agreement | No |
| Read, build, or run outside an agreement | No |
| Copy code into another project | No |
| Modify, fork, or publish derivative works | No |
| Distribute the source or binaries | No |
| Commercial use without a license | No |
| Use as training data for AI models | No, without written permission |

Access is granted only to Authorised Persons under a signed agreement. See
[LICENSE](LICENSE) for the binding notice, [COPYRIGHT.md](COPYRIGHT.md) for
ownership, and [NOTICE](NOTICE) for third-party components and code of unresolved
provenance.

## Acknowledgements

- The [OSDev Wiki](https://wiki.osdev.org) and the Intel SDM, for the reference
  material this project is learned from.
- The UEFI and ACPI specifications, for the interfaces implemented here.

DUST-OS is not affiliated with, endorsed by, or sponsored by any of the above.
