# Engineering Handbook

This is the internal engineering handbook for DUST-OS. It applies to the Owner,
employees, contractors, interns, and any other person with repository access —
collectively, "team members".

This repository is private and the software is proprietary. Read
[LICENSE](LICENSE), [DOCUMENTS/IP_POLICY.md](DOCUMENTS/IP_POLICY.md), and
[DOCUMENTS/ARCHITECTURE.md](DOCUMENTS/ARCHITECTURE.md) before your first change.

---

## 1. Before you write code

1. **Have a task.** Work starts from an issue or a written task with a defined
   outcome. Unrequested large changes are not merged, even when they are good.
2. **Read the architecture.** A change that contradicts a recorded decision (D-1
   to D-7 in ARCHITECTURE.md) requires reopening that decision first.
3. **Check the IP policy.** No third-party code, no copied snippet, and no
   AI-generated code of unknown provenance enters the repository without
   approval. See Section 8.
4. **Sign the paperwork.** Your IP assignment must be on file before your first
   commit is merged. See Section 9.

## 2. Access and branch rules

| Rule | Requirement |
| --- | --- |
| Authentication | Multi-factor authentication is mandatory |
| Default branch | `main`, protected; no direct pushes, including by the Owner |
| Change path | Every change lands through a pull request |
| Review | At least one approving review; the Owner approves protected areas |
| Commits | Signed off (`git commit -s`); signed commits where configured |
| Force push | Not allowed on `main`; avoid on shared branches |
| Secrets | Never committed; see Section 8 |
| Access removal | On the day an engagement ends |

Branch names:

```
feat/<short-name>      new capability
fix/<short-name>       defect fix
docs/<short-name>      documentation only
chore/<short-name>     build, tooling, cleanup
release/<version>      release preparation
```

One logical change per pull request. File moves, formatting, and behaviour changes
go in separate commits.

## 3. What is accepted

Accepted:

- fixes for defects in existing code, with a clear explanation of the root cause;
- implementations of items on the roadmap, at the stage they are listed;
- documentation corrections, including factual errors;
- improvements to build reproducibility and test coverage.

Not accepted:

- code you cannot explain line by line — if you cannot maintain it, it does not
  belong here;
- code copied from another project without an approved license and full
  attribution;
- GPL, LGPL, AGPL, or SSPL code under any circumstances;
- large rewrites without prior discussion;
- generated code that has not been reviewed and understood by the author;
- changes to [LICENSE](LICENSE), [COPYRIGHT.md](COPYRIGHT.md), [NOTICE](NOTICE),
  `LEGAL/`, or this document's policy sections — these are Owner-only files.

## 4. Code style

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

Kernel constraints, which are correctness requirements rather than preferences:

- **Freestanding only.** No libc. No hosted headers beyond the freestanding set
  (`stdint.h`, `stddef.h`, `stdbool.h`, `stdatomic.h`, `stdalign.h`,
  `stdnoreturn.h`).
- **No floating point and no SIMD** in kernel code. The build disables SSE, MMX,
  and AVX; reintroducing them breaks interrupt handling.
- **No dynamic relocation.** Position-independent code is disabled.
- **Every allocation has one documented owner.** State in the pull request who
  allocates and who frees.

## 5. Commit messages

- Subject line: imperative mood, at most 72 characters, no trailing period.
  Example: `kern: fix list_head prev pointer type`
- Body: explain *why* the change is needed, not *what* the diff already shows.
- Reference the issue number when one exists.
- Sign off every commit (`git commit -s`) to certify that you wrote the code or
  have the right to submit it.

## 6. Testing and evidence

A pull request must state:

1. **What you tested**, and how: QEMU command, hardware model, boot method.
2. **What you did not test**, and why.
3. **Known defects or limitations** in your change.

Rules:

- A change that affects boot must include serial output from a successful boot.
- A change that affects memory management must state how you checked for leaks,
  double frees, and use-after-free.
- A change that affects the boot contract must update the contract document and
  the shared header in the same pull request.
- "Works on my machine" is not evidence. Include the command and the output.
- Undisclosed known defects are treated as a breach of trust, not as an oversight.

## 7. Review

- Reviews focus first on correctness, safety, and the boot contract, then on
  style.
- Reviewers may reject, request changes, or revert a change at any time.
- The author resolves comments; the reviewer resolves the thread.
- A review is not a guarantee. The author remains responsible for the change.
- Protected paths require the Owner's approval; see `.github/CODEOWNERS`.

## 8. IP, confidentiality, and dependencies

- **Your work is assigned to the Owner.** See Section 9.
- **No third-party code without approval.** Ask before you paste. A snippet from
  a blog, a forum, or another repository is third-party code.
- **Permitted licenses** are listed in
  [DOCUMENTS/IP_POLICY.md](DOCUMENTS/IP_POLICY.md), Section 6. Copyleft is
  prohibited.
- **No secrets in the repository.** Never commit credentials, keys, tokens,
  customer data, or personal data. Use the approved secret store.
- **No personal cloud or paste services.** Source, logs, screenshots, and
  crash dumps stay in approved systems.
- **No AI training.** Do not upload the repository to a service that trains on
  it. AI assistants may be used only under the policy in IP_POLICY.md, Section 9.
- **Report a leak immediately.** If you suspect that confidential material was
  exposed, tell the Owner at once; do not try to clean it up silently.

## 9. Paperwork for team members

Before your first merged commit you must have:

1. a signed IP assignment — [LEGAL/IP_ASSIGNMENT.md](LEGAL/IP_ASSIGNMENT.md);
2. a signed NDA, if you will see Restricted material —
   [LEGAL/NDA.md](LEGAL/NDA.md);
3. if you are a minor, a parent or legal guardian's signature on both;
4. a named access level and the systems you are allowed to use.

No exceptions. A commit without paperwork is removed from the history.

## 10. Reporting bugs

Include:

- the exact commit hash or release tag;
- toolchain versions (`clang --version`, `cmake --version`);
- the QEMU invocation or the hardware used;
- the full serial or console output, not a paraphrase;
- steps to reproduce, and what you expected instead.

Security issues do not go in the issue tracker. See [SECURITY.md](SECURITY.md).

## 11. Conduct

All participation is governed by [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md). The
project is a professional workplace, including when it is remote and informal.

## 12. When in doubt

Ask before you act on anything involving:

- a new dependency;
- a license or copyright question;
- customer data;
- a public statement about the project;
- a change to the boot contract.

The cost of a question is minutes. The cost of an unlicensed dependency in a
shipped product is the product.
