# Documentation

This directory holds the project's internal documentation. The repository is
private and the software is proprietary; see [LICENSE](../LICENSE) and
[IP_POLICY.md](IP_POLICY.md).

| Document | Purpose | Audience |
| --- | --- | --- |
| [ARCHITECTURE.md](ARCHITECTURE.md) | What the system is meant to be, what it is now, technical debt, technical decisions D-1 to D-7 | Maintainers, team |
| [IP_POLICY.md](IP_POLICY.md) | Ownership, confidentiality tiers, third-party code, customer licensing, brand, export control, decisions D-8 to D-18 | Owner, team, counsel |
| [RELEASE_PROCESS.md](RELEASE_PROCESS.md) | Versioning, quality gates, artifact signing, distribution, rollback, release records | Owner, release engineer |
| [TEAM.md](TEAM.md) | Roles, team size, hiring readiness, access levels, onboarding | Owner, future team |
| [BRAND.md](BRAND.md) | Name usage, claims policy, voice, visual identity, public communication | Owner, team, anyone speaking publicly |

Project-wide documents live in the repository root:

| Document | Purpose |
| --- | --- |
| [README.md](../README.md) | Project front page and status |
| [LICENSE](../LICENSE) | Proprietary and confidentiality notice |
| [COPYRIGHT.md](../COPYRIGHT.md) | Ownership, SPDX identifier, source headers, records |
| [NOTICE](../NOTICE) | Third-party notices and unresolved provenance |
| [CONTRIBUTING.md](../CONTRIBUTING.md) | Internal engineering handbook |
| [SECURITY.md](../SECURITY.md) | Private vulnerability reporting and incident response |
| [SUPPORT.md](../SUPPORT.md) | Support scope, channels, and targets |
| [PRIVACY.md](../PRIVACY.md) | Personal-data handling |
| [CHANGELOG.md](../CHANGELOG.md) | Release history |
| [AUTHORS.md](../AUTHORS.md) | Owner, team, and contributor credits |
| [CODE_OF_CONDUCT.md](../CODE_OF_CONDUCT.md) | Workplace conduct |
| [LEGAL/README.md](../LEGAL/README.md) | Contract templates and execution rules |

## Document rules

- Every document states its status and date near the top.
- A decision is not settled unless it is recorded with a status in
  ARCHITECTURE.md or IP_POLICY.md.
- A change to a decision updates the document and the affected code in the same
  change.
- Documents are classified under [IP_POLICY.md](IP_POLICY.md), Section 3. The
  default is Confidential.
- Do not paste customer data, credentials, or Restricted material into any
  document.

## Decision index

| Range | Location | Subject |
| --- | --- | --- |
| D-1 to D-7 | [ARCHITECTURE.md §10](ARCHITECTURE.md#10-open-decisions) | Boot contract, target architecture, naming, error convention, IPC IDs, filesystems, layout |
| D-8 to D-18 | [IP_POLICY.md §14](IP_POLICY.md#14-decisions) | Private release, disclosure, classification, IP assignment, third-party code, crypto/export, customer licensing, trademark, governance, release gates, access control |

## Status legend

| Status | Meaning |
| --- | --- |
| Decided | Settled; changing it requires a recorded decision |
| Provisional | Default in effect; expected to be revisited when stated |
| Pending | Not decided; do not describe it as settled |
| Blocked | Cannot proceed until a named condition is met |
