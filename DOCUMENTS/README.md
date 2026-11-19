# Documentation

| Document | Purpose | Audience |
| --- | --- | --- |
| [ARCHITECTURE.md](ARCHITECTURE.md) | What the system is meant to be, what it is now, technical debt, technical decisions D-1 to D-7 | Maintainers, contributors |
| [LICENSING.md](LICENSING.md) | Publication scope, license of each tree, contribution terms, policy decisions D-8 to D-16 | Maintainers, contributors, anyone reusing the project |
| [PUBLISHING.md](PUBLISHING.md) | How a public release is produced and verified | Maintainers |

Machine-readable publication allow-list: [../PUBLIC_PATHS.txt](../PUBLIC_PATHS.txt).

Project-wide documents live in the repository root: [LICENSE](../LICENSE),
[COPYRIGHT.md](../COPYRIGHT.md), [NOTICE](../NOTICE), [CLA.md](../CLA.md),
[CONTRIBUTING.md](../CONTRIBUTING.md), [SECURITY.md](../SECURITY.md),
[AUTHORS.md](../AUTHORS.md), [CODE_OF_CONDUCT.md](../CODE_OF_CONDUCT.md).

## Decision index

Technical decisions are recorded in ARCHITECTURE.md, policy decisions in
LICENSING.md. A decision is not settled unless it is recorded there with a status.

| Range | Location | Subject |
| --- | --- | --- |
| D-1 to D-7 | [ARCHITECTURE.md §10](ARCHITECTURE.md#10-open-decisions) | Boot contract, target architecture, naming, error convention, IPC IDs, filesystems, layout |
| D-8 to D-16 | [LICENSING.md §12](LICENSING.md#12-decisions) | Public license, publication scope, build, sync, contributions, governance, cadence |

When a decision changes, update the section that records it and the code or
document it affects in the same change.
