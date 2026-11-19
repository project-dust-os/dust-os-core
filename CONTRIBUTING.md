# Contributing to DUST-OS

Thanks for your interest. DUST-OS is a proprietary, source-available project
maintained by one person. Contributions are accepted selectively.

Please read this document, [CLA.md](CLA.md), and Section 5 of [LICENSE](LICENSE)
before you start. Submitting a pull request means you accept all three.

All contributions are made under [CLA.md](CLA.md), which assigns economic
copyright in the contribution to the maintainer. Contributors keep their moral
rights. If you are a minor, a parent or guardian must consent (CLA 3.5).

---

## 1. Before you write code

1. **Check the publication scope.** Only the subset listed in
   [DOCUMENTS/LICENSING.md](DOCUMENTS/LICENSING.md) is public. A change outside
   that scope will be redirected or declined, even if it is good work.
2. **Open an issue first** for anything larger than a typo. Describe the problem
   and your proposed approach. This avoids wasted work on a design the maintainer
   will not accept.
3. **Read [DOCUMENTS/ARCHITECTURE.md](DOCUMENTS/ARCHITECTURE.md).** It records the current
   state, the design decisions, and the open questions. A change that contradicts
   a recorded decision needs that decision reopened first.
4. **One logical change per pull request.** File moves, formatting, and behaviour
   changes go in separate commits.

## 2. What is accepted

Accepted:

- Fixes for defects in existing code, with a clear explanation of the root cause.
- Implementations of items listed in the roadmap, at the stage they are listed.
- Documentation corrections, including spelling and factual errors.
- Improvements to build reproducibility.

Not accepted:

- Code you cannot explain line by line. This project is a learning exercise; a
  contributor who cannot explain their code cannot maintain it.
- Code copied from another project without a compatible license and full
  attribution. **GPL, LGPL, and AGPL code is incompatible with this project and
  must not be submitted.**
- Large rewrites submitted without prior discussion.
- Generated code that the submitter has not reviewed.
- Changes to [LICENSE](LICENSE), [COPYRIGHT.md](COPYRIGHT.md), or [NOTICE](NOTICE)
  — these are maintainer-only files.

## 3. Code style

The project follows a Linux-kernel-like C style, enforced by `.clang-format` and
`.editorconfig`:

| Rule | Value |
| --- | --- |
| Indentation | Hard tabs, 8 columns |
| Line length | 80 columns |
| Pointer alignment | Right (`char *p`, not `char* p`) |
| Braces | Function braces on their own line |
| Naming | `snake_case` for functions and variables, `_t` suffix for typedefs |
| Prefixes | Subsystem prefix on public symbols (`ke_`, `shm_`, …) |

Run `clang-format -i` on every file you touch before committing.

Kernel constraints, which are not style preferences:

- **Freestanding only.** No libc. No hosted headers beyond the freestanding set
  (`stdint.h`, `stddef.h`, `stdbool.h`, `stdatomic.h`, `stdalign.h`,
  `stdnoreturn.h`).
- **No floating point and no SIMD** in kernel code. The build disables SSE, MMX,
  and AVX; a contributor who reintroduces them breaks interrupt handling.
- **No dynamic relocation.** Position-independent code is disabled.
- **Every allocation has one documented owner.** State in the commit message who
  allocates and who frees.

## 4. Commit messages

- Subject line: imperative mood, at most 72 characters, no trailing period.
  Example: `kern: fix list_head prev pointer type`
- Body: explain *why* the change is needed, not *what* the diff already shows.
- Reference the issue number when one exists.
- Sign off every commit (`git commit -s`) to certify that you wrote the code or
  have the right to submit it.

## 5. Testing and disclosure

A pull request must state:

1. **What you tested**, and how: QEMU command, hardware model, boot method.
2. **What you did not test**, and why.
3. **Known defects or limitations** in your change.

A contributor is responsible for the correctness of what they submit, as set out
in Section 5.4 of [LICENSE](LICENSE). Undisclosed known defects are a breach of
that section.

## 6. Review process

- The maintainer reviews on a best-effort basis. There is no service-level
  commitment.
- Reviews focus first on correctness and safety, then on style.
- The maintainer may reject, request changes, or revert a contribution at any
  time, as described in Section 5.6 of [LICENSE](LICENSE).

## 7. Reporting bugs

Include:

- The exact commit hash.
- Toolchain versions (`clang --version`, `cmake --version`).
- The QEMU invocation or the hardware used.
- The full serial or console output, not a paraphrase.
- Steps to reproduce, and what you expected instead.

## 8. Code of conduct

All participation is governed by [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md).
