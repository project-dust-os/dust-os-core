# Licensing and Publication Policy

Status: **draft**, owner-approved, with open decisions recorded in Section 12.
This document is published so that the publication scope is verifiable. It is not
a license; the binding terms are in [LICENSE](../LICENSE) and [CLA.md](../CLA.md).

---

## 1. Two trees

DUST-OS is developed in two places:

| Tree | Content | Visibility |
| --- | --- | --- |
| **Private development tree** | Everything, including commercial components | Private repository |
| **Public source release** | A curated subset, published as a snapshot | Public repository, source-available |

The private tree is canonical. Nothing is published by pushing this repository
publicly; publication is a deliberate export of an allow-listed subset, described
in [PUBLISHING.md](PUBLISHING.md).

This split exists so that the public release can be studied and contributed to
without exposing components that are intended to remain private.

## 2. Publication scope

Proposed scope. Items marked **pending** are not decided and must not be treated
as settled.

### Published

| Path | Rationale |
| --- | --- |
| `kernel/` | Core of the project; highest learning and review value |
| `hal/` | Needed to understand and port the kernel |
| `gui/` | Visible, self-contained, good for contributors |
| `boot/` | Boot chain; must be public for the contract to be reviewable |
| `fs/` | Filesystems; review value, mostly self-contained |
| `security/` | Public review is the point of a security model |
| `drivers/` | **Selected only** — see below |
| `README.md`, `LICENSE`, `COPYRIGHT.md`, `NOTICE`, `CLA.md` | Required for any release |
| `CONTRIBUTING.md`, `CODE_OF_CONDUCT.md`, `SECURITY.md` | Community documents |
| `DOCUMENTS/ARCHITECTURE.md` | Technical documentation |

### Published, with conditions

| Path | Condition |
| --- | --- |
| `drivers/` | Generic bus and platform drivers public; vendor-specific or performance-critical drivers private. The exact list is **pending** (D-13). |
| `fs/` | `f2fs` and `ntfs` public. Whether `wfs` is public is **pending** (D-10). |
| `crypto/` | Public review is desirable, but cryptographic source can attract export-control obligations in some jurisdictions. **Pending** (D-9). |

### Not published

| Path | Reason |
| --- | --- |
| `compat/` | Compatibility layer is a candidate commercial differentiator |
| `firmware/` | Redistribution rights are unclear per blob |
| `bin/` | Purpose undecided |
| `test/` | Internal harness and hardware lab notes |
| `DOCUMENTS/` (except `ARCHITECTURE.md`) | Business notes, roadmap, this policy |
| Any future commercial service, toolchain, or product code | Commercial |

### Blocking condition

No file may be published while its provenance is unresolved. The
unattributed UEFI headers listed in [NOTICE](../NOTICE) currently **block
publication of `boot/`**, because `boot/` was approved for publication but
contains files whose license is unknown. This must be resolved first; see
[PUBLISHING.md](PUBLISHING.md), step 2.

## 3. License of each tree

| Tree | License |
| --- | --- |
| Public release | `LicenseRef-Dust-OS-1.0` ([LICENSE](../LICENSE)) — source-available, proprietary |
| Private tree | All rights reserved; no license granted to anyone |

The public release is **not open source**. It does not meet the OSI definition,
and must not be described as open source anywhere.

## 4. Why source-available, and what it costs

Source-available gives the Owner:

- full control over redistribution and derivative works;
- the ability to keep an exclusive commercial path;
- freedom to relicense future versions.

It costs the project:

- **most potential contributors.** Many developers will not contribute to a
  project whose code they cannot reuse. The expected contribution volume is
  therefore low, and the primary benefit of publishing is review and bug reports,
  not code.
- **community goodwill in some circles**, because source-available is often
  perceived as "open enough to attract free labour, closed enough to keep the
  business." This is a reputation cost, not a legal one.

If contributions become the priority, the alternative is an open-core model: the
public core under a genuine open source license (for example BSD-2-Clause), the
private components proprietary. That is a different decision with different
consequences, recorded as D-8. It is not in effect.

## 5. Contributions

All contributions to the public release require [CLA.md](../CLA.md):

- the contributor assigns economic copyright in the contribution to the Owner;
- the contributor keeps moral rights, which cannot be waived under Indonesian law;
- the contributor warrants originality and discloses known defects;
- the contributor accepts responsibility for defects in their own contribution,
  as described in Section 5.4 of [LICENSE](../LICENSE);
- a contributor who is a minor must have a parent or guardian accept the CLA.

Because contribution requires assignment, contributions are accepted from people
who are comfortable with that. Many are not. This is an accepted trade-off, not a
bug to be fixed later by quietly changing the terms.

No GPL, LGPL, or AGPL code may be accepted. No code may be accepted from a project
whose license is incompatible with a proprietary release.

## 6. Relicensing, closing, and published history

| Action | Permitted |
| --- | --- |
| Change the license of future versions | Yes, if the Owner holds all rights in the code concerned |
| Stop publishing new versions | Yes, at any time |
| Withdraw a published release | No; a granted license cannot be revoked |
| Relicense code contributed without a CLA | No, unless every contributor agrees or the code is removed |
| Relicense code contributed under CLA.md | Yes |

Publication policy:

- Each release states its license explicitly.
- A license change applies to future releases only. Previous releases remain
  under the license they were published with.
- A decision to stop publishing is announced with a reason and a date. The last
  published release stays available and stays under its license.
- Commit history of the public release is never rewritten to hide a previous
  license.

## 7. Business model

The intended model is open-core: the published subset demonstrates and documents
the system; private components and services are the commercial layer.

Realistic commercial layers for an operating system are support, integration,
certification, proprietary drivers for specific hardware, and hosted services. The
kernel itself is rarely the sellable part, which is why publishing it does not
automatically leave "nothing to sell".

Nothing in this document is a commitment to ship a product. The private tree may
contain experiments that are never released commercially. Technical decisions
must not be distorted to protect a business that does not exist yet.

## 8. Third-party code

- Third-party components are identified in [NOTICE](../NOTICE) and are never
  relicensed.
- A file with unresolved provenance is not published.
- A public release must be distributable as a whole. One unattributed copyleft
  file makes the entire release undistributable.

## 9. Trademark

The licenses grant rights to code, not to the project's identity. The name
"DUST-OS", "Dust OS", and any logo remain the Owner's. A fork or derivative
distribution must not present itself as DUST-OS. See Section 12.6 of
[LICENSE](../LICENSE).

## 10. Security

The public release is readable by attackers as well as reviewers. That is
accepted: the security model benefits more from review than it loses from
disclosure. Vulnerability reports are handled privately under
[SECURITY.md](../SECURITY.md) until a fix is available.

## 11. Review

This policy is reviewed when:

- a new component is proposed for publication;
- a component moves between the public and private trees;
- the license of either tree changes;
- contribution volume makes the assignment requirement a practical obstacle.

## 12. Open decisions

**D-8. Public license.** Keep `LicenseRef-Dust-OS-1.0` (source-available) or move
the public core to a genuine open source license and keep only the commercial
layer proprietary. Current: source-available.

**D-9. `crypto/` publication.** Publish for review, or keep private for export
control and commercial reasons. Current: private, pending.

**D-10. `wfs` publication.** Publish the project's own filesystem, or keep it as
the commercial filesystem and publish only `f2fs` and `ntfs`. Current: pending.

**D-11. Public build.** Whether the public release builds from the same
`CMakeLists.txt` as the private tree (which requires that file to reference only
public paths), or ships its own build description generated at export time.
Current: undecided; the public release must build on its own before it is
published.

**D-12. Sync direction.** Whether the public repository is canonical for the
published paths (contributions land there and are pulled into the private tree),
or a read-only export snapshot (contributions arrive as patches and are applied
manually). Current: undecided; a snapshot is simpler, canonical-public is better
for contributors.

**D-13. Driver boundary.** The exact list of public and private drivers. Current:
generic buses public, vendor-specific private.

**D-14. Contribution terms.** Copyright assignment (current, strongest for
relicensing) or a broad perpetual license grant (friendlier to contributors,
weaker for closing). Current: assignment.
