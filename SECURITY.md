# Security Policy

## Supported versions

DUST-OS is pre-alpha and has no releases. Only the current state of the default
branch is considered. No version is supported for production use, and none
should be deployed anywhere that matters.

## Reporting a vulnerability

**Do not open a public issue, pull request, or discussion for a security issue.**

Report privately to:

- **Email:** dvennote65@gmail.com
- **Subject line:** `[DUST-OS SECURITY]` followed by a short summary

Please include:

- A description of the issue and its impact.
- The commit hash, toolchain versions, and environment (QEMU or hardware).
- Reproduction steps or a proof of concept.
- Any suggested mitigation, if you have one.

## What to expect

This is a single-maintainer educational project, so the following are
best-effort targets, not commitments:

| Stage | Target |
| --- | --- |
| Acknowledgement of report | 7 days |
| Initial assessment | 30 days |
| Fix or documented mitigation | Depends on severity and available time |

Please allow a reasonable window for a fix before any public disclosure. If a
fix is not possible, the maintainer will say so and agree on a disclosure date
with you.

## Scope

In scope:

- Kernel memory-safety defects: buffer overflows, use-after-free, integer
  truncation leading to memory corruption.
- Defects in the boot path that allow code execution before the kernel starts.
- Privilege-boundary defects between kernel and user space, once user space
  exists.
- Build-system defects that silently produce a kernel different from the source.

Out of scope:

- Vulnerabilities in platform firmware or in external tooling that is not part
  of this repository. Report those to their respective maintainers; see
  [NOTICE](NOTICE).
- Issues that require physical access or an already-compromised boot chain.
- Missing hardening features in a project that does not boot yet.
- Denial of service from deliberately malformed input to an unfinished driver.

## No bug bounty

There is no bug bounty and no payment for reports. Credit will be given in the
commit message and release notes unless you ask to remain anonymous.
