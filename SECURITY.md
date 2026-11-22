# Security Policy

DUST-OS is proprietary software. Security reports are handled privately and are
covered by confidentiality until a fix is released.

## 1. Supported versions

DUST-OS is pre-alpha and has no customer release. Only the current state of the
default branch is considered. No version is supported for production use, and
none should be deployed anywhere that matters.

When customer releases exist, this section will list the supported versions and
their support windows. Until then, the answer is: none.

## 2. Reporting a vulnerability

**Do not open a public issue, pull request, discussion, or social-media post for
a security issue.**

Report privately to:

- **Email:** dvennote65@gmail.com
- **Subject line:** `[DUST-OS SECURITY]` followed by a short summary

If you are a customer or an Authorised Person, use the private channel named in
your agreement and also copy the address above.

Please include:

- a description of the issue and its impact;
- the commit hash, release tag, toolchain versions, and environment (QEMU or
  hardware);
- reproduction steps or a proof of concept;
- any suggested mitigation;
- whether you intend to disclose publicly, and on what timeline.

## 3. What to expect

The project is maintained by a very small team, so the following are best-effort
targets, not contractual commitments:

| Stage | Target |
| --- | --- |
| Acknowledgement of report | 7 days |
| Initial assessment and severity | 30 days |
| Fix or documented mitigation | Depends on severity and available time |
| Customer notification, if affected | With the fix or earlier if exploitation is likely |

If a fix is not possible, the maintainer will say so and agree on a disclosure
date with the reporter. Do not disclose before that date.

## 4. Severity

| Severity | Meaning | Target |
| --- | --- | --- |
| Critical | Boot-chain or kernel compromise, or silent memory corruption | Immediate triage, fix before any release |
| High | Privilege boundary break, data loss, or remote denial of service | Fix before the next release |
| Medium | Local denial of service, information leak with limited impact | Next planned release |
| Low | Hardening gap, defence-in-depth issue | Backlog |

## 5. Scope

In scope:

- kernel memory-safety defects: buffer overflows, use-after-free, integer
  truncation leading to memory corruption;
- defects in the boot path that allow code execution before the kernel starts;
- privilege-boundary defects between kernel and user space, once user space
  exists;
- build-system defects that silently produce a kernel different from the source;
- supply-chain defects: a dependency, artifact, or signature that does not match
  its recorded digest.

Out of scope:

- vulnerabilities in platform firmware or external tooling that is not part of
  this repository — report those to their maintainers; see [NOTICE](NOTICE);
- issues that require physical access or an already-compromised boot chain;
- missing hardening features in a project that does not boot yet;
- denial of service from deliberately malformed input to an unfinished driver;
- reports about the absence of a feature.

## 6. Rules for researchers

- Test only on systems you own or have written permission to test.
- Do not access, modify, or exfiltrate data that is not yours.
- Do not run scans against infrastructure you do not control.
- Give the project a reasonable window to fix the issue before disclosure.

## 7. Incident response

For a confirmed incident the project will:

1. contain the issue and preserve evidence;
2. assess affected versions and customers;
3. prepare and test a fix;
4. notify affected customers under their agreement;
5. publish a private advisory to Authorised Persons;
6. record the incident and the lessons learned.

A public advisory is published only after the fix is available and affected
customers have been notified, or when disclosure is required by law.

## 8. No bug bounty

There is no bug bounty and no payment for reports. Credit is given in the commit
message and release notes unless the reporter asks to remain anonymous.

## 9. Contact

Security contact: **dvennote65@gmail.com**

This policy is not legal advice. Customer notification obligations are set by
each customer agreement.
