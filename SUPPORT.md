# Support Policy

DUST-OS is pre-alpha. There is no supported release, no service-level agreement,
and no public support channel. This document defines what support will exist and
how it is requested. Customer agreements override it.

---

## 1. Current status

| Item | State |
| --- | --- |
| Supported versions | None |
| Customer releases | None |
| Public support | None |
| Response commitment | None |
| Bug bounty | None |

Do not deploy DUST-OS anywhere that matters. See [SECURITY.md](SECURITY.md).

## 2. Support channels

| Audience | Channel | Use |
| --- | --- | --- |
| Team | Internal issue tracker | Defects, tasks, design questions |
| Evaluation customer | Named contact in the NDA or evaluation agreement | Installation and evaluation questions |
| Paying customer | Channel named in the support agreement | Incidents, defects, upgrades |
| Security reporter | dvennote65@gmail.com | Vulnerabilities only |
| Everyone else | None | No public support is offered |

Never send credentials, customer data, or Restricted material through an
unapproved channel.

## 3. Severity and targets

Targets apply only when a support agreement is in force. Before that, all
responses are best effort.

| Severity | Definition | First response | Workaround target |
| --- | --- | --- | --- |
| S1 — Critical | Device will not boot; data loss; security compromise | 1 business day | 3 business days |
| S2 — High | Major function unavailable; no workaround | 2 business days | 10 business days |
| S3 — Medium | Function impaired; workaround exists | 5 business days | Next release |
| S4 — Low | Question, cosmetic issue, documentation | 10 business days | Best effort |

Targets are for acknowledgement and triage, not for a fix. A fix depends on
severity, reproducibility, and the release schedule.

## 4. What support covers

- installation, boot, and recovery of a supported release;
- diagnosis of defects in unmodified DUST-OS;
- known issues and workarounds;
- upgrade guidance between supported versions;
- security advisories affecting the customer.

## 5. What support does not cover

- custom development, porting, or driver work outside an agreement;
- modified builds, unsupported hardware, or unsupported firmware;
- third-party software, firmware, or tooling — contact its maintainer;
- problems caused by unsupported configuration;
- training, except as agreed separately;
- hardware repair.

## 6. What to include in a request

- customer name and contract reference, if applicable;
- DUST-OS version and build identifier;
- hardware model, firmware version, and configuration;
- exact steps to reproduce;
- full serial or console output, not a summary;
- what changed before the problem appeared;
- business impact and urgency.

Incomplete reports are returned, not guessed at.

## 7. Defect handling

1. Acknowledge and assign a severity.
2. Reproduce on a recorded environment.
3. Identify whether the cause is DUST-OS, configuration, or third-party.
4. Provide a workaround if one exists.
5. Fix through the release process; see
   [DOCUMENTS/RELEASE_PROCESS.md](DOCUMENTS/RELEASE_PROCESS.md).
6. Notify affected customers if the defect is security-relevant.

## 8. End of life

Before the first customer release, every version is end of life on the day it is
replaced. After that, support windows are defined per customer agreement.

## 9. Contact

Support contact for customers: the channel named in the agreement.

Project contact: **dvennote65@gmail.com**

Security issues: see [SECURITY.md](SECURITY.md). Do not use the support channel
for vulnerabilities.

This policy is not legal advice, and it creates no obligation by itself. Only a
signed agreement does.
