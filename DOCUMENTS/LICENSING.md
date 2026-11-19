# Licensing and Publication Policy

Status: **draft 2**, with the plan of record below and open decisions recorded in
Section 12. This document is published so that the publication scope is
verifiable. It is not a license; the binding terms are in [LICENSE](../LICENSE)
and [CLA.md](../CLA.md).

---

## 0. Plan of record

This is the Owner's stated plan, and it is not changed without an explicit
decision in Section 12.

**Published (source-available):**

- the kernel (`kernel/`)
- the GUI (`gui/`)
- the hardware abstraction layer (`hal/`)
- the boot path (`boot/`)
- filesystems (`fs/`)
- the security model (`security/`)
- non-vendor drivers (`drivers/`, excluding `drivers/vendor/`)
- the community and policy documents needed to review and contribute to the above

**Not published (private):**

- the compatibility layer (`compat/`)
- cryptographic implementations (`crypto/`)
- firmware and blobs (`firmware/`)
- vendor-specific drivers (`drivers/vendor/`)
- the test harness and hardware lab notes (`test/`)
- binaries (`bin/`)
- future commercial services, tooling, and products

The public release is a snapshot of the allow-listed paths. The authoritative,
machine-readable list is [PUBLIC_PATHS.txt](../PUBLIC_PATHS.txt); this document is
the human-readable rationale.

## 1. Two trees

| Tree | Content | Visibility |
| --- | --- | --- |
| **Private development tree** | Everything, including commercial components | Private repository |
| **Public source release** | The allow-listed subset, published as a snapshot | Public repository, source-available |

The private tree is canonical. Publication is a deliberate export, described in
[PUBLISHING.md](PUBLISHING.md). Never publish by changing the visibility of the
private repository.

## 2. Publication scope

Decided scope, with conditions where they apply.

| Path | Published | Note |
| --- | --- | --- |
| `kernel/` | Yes | Core of the project; highest learning and review value |
| `hal/` | Yes | Needed to understand and port the kernel |
| `gui/` | Yes | Visible, self-contained, good for contributors |
| `boot/` | Yes, **blocked** | Provenance of `boot/bootmgrc/include/*` is unresolved; see Section 8 |
| `fs/` | Yes | Includes `wfs` for now; see D-10 |
| `security/` | Yes | Public review is the point of a security model |
| `drivers/` | Yes, except `drivers/vendor/` | Boundary is a directory convention; see D-13 |
| `DOCUMENTS/` | Yes | Architecture, licensing, publishing |
| `README.md`, `LICENSE`, `COPYRIGHT.md`, `NOTICE`, `CLA.md` | Yes | Required for any release |
| `CONTRIBUTING.md`, `CODE_OF_CONDUCT.md`, `SECURITY.md`, `AUTHORS.md` | Yes | Community documents |
| `.github/`, `.clang-format`, `.editorconfig`, `.gitattributes`, `.gitignore` | Yes | Needed to contribute and build |
| `compat/` | No | Candidate commercial differentiator |
| `crypto/` | No | See D-9 |
| `firmware/` | No | Redistribution rights unclear per blob |
| `drivers/vendor/` | No | Vendor-specific drivers; see D-13 |
| `test/` | No | Internal harness and hardware lab notes |
| `bin/` | No | Purpose undecided |
| Future commercial services, tooling, products | No | Commercial |

### Blocking condition

No file may be published while its provenance is unresolved. The unattributed
UEFI headers listed in [NOTICE](../NOTICE) currently **block publication of
`boot/`**. This must be resolved before the first release; see
[PUBLISHING.md](PUBLISHING.md), step 2.

## 3. License of each tree

| Tree | License |
| --- | --- |
| Public release | `LicenseRef-Dust-OS-1.0` ([LICENSE](../LICENSE)) — source-available, proprietary |
| Private tree | All rights reserved; no license granted to anyone |

The public release is **not open source**. It does not meet the OSI definition and
must not be described as open source anywhere. Whether that changes is D-8.

## 4. Why source-available, and what it costs

Source-available gives the Owner:

- full control over redistribution and derivative works;
- an exclusive commercial path;
- freedom to relicense future versions.

It costs the project:

- **most potential contributors.** Many developers will not contribute to code
  they cannot reuse. Expect bug reports and review, not a stream of pull requests.
- **some community goodwill**, because source-available is often perceived as
  "open enough to attract free labour, closed enough to keep the business". That
  is a reputation cost, not a legal one.

If contributions become the priority, the alternative is an open-core model: the
public core under a genuine open source license (for example BSD-2-Clause), the
private components proprietary. That is D-8 and it is **not** in effect.

## 5. Contributions

All contributions to the public release require [CLA.md](../CLA.md):

- the contributor assigns economic copyright in the contribution to the Owner;
- the contributor keeps moral rights, which cannot be waived under Indonesian law;
- the contributor warrants originality and discloses known defects;
- the contributor accepts responsibility for defects in their own contribution,
  as described in Section 5.4 of [LICENSE](../LICENSE);
- a contributor who is a minor must have a parent or guardian accept the CLA.

Because contribution requires assignment, contributions come from people who are
comfortable with that. Many are not. This is an accepted trade-off, recorded as
D-14, not a bug to be fixed by quietly changing terms later.

No GPL, LGPL, or AGPL code is accepted.

Attribution is preserved in commit metadata and, with the contributor's consent,
in [AUTHORS.md](../AUTHORS.md).

## 6. Relicensing, closing, and published history

| Action | Permitted |
| --- | --- |
| Change the license of future versions | Yes, if the Owner holds all rights in the code concerned |
| Stop publishing new versions | Yes, at any time |
| Withdraw a published release | No; a granted license cannot be revoked |
| Relicense code contributed without a CLA | No, unless every contributor agrees or the code is removed |
| Relicense code contributed under CLA.md | Yes |

Publication rules:

- Each release states its license explicitly.
- A license change applies to future releases only. Previous releases remain under
  the license they were published with.
- A decision to stop publishing is announced with a reason and a date. The last
  published release stays available and stays under its license.
- Published history is never rewritten to hide a previous license.

## 7. Business model

The intended model is open-core: the published subset demonstrates and documents
the system; private components and services are the commercial layer.

Realistic commercial layers for an operating system are support, integration,
certification, proprietary drivers for specific hardware, and hosted services. The
kernel itself is rarely the sellable part, which is why publishing it does not
automatically leave "nothing to sell".

Nothing here commits the project to ship a product. Technical decisions must not be
distorted to protect a business that does not exist yet. The governance question —
single owner or a foundation — is D-15 and is deliberately unresolved.

## 8. Third-party code

- Third-party components are identified in [NOTICE](../NOTICE) and are never
  relicensed.
- A file with unresolved provenance is not published.
- A public release must be distributable as a whole. One unattributed copyleft file
  makes the entire release undistributable.

## 9. Trademark

The licenses grant rights to code, not to the project's identity. "DUST-OS",
"Dust OS", and any logo remain the Owner's. A fork or derivative distribution must
not present itself as DUST-OS. See Section 12.6 of [LICENSE](../LICENSE).

## 10. Security

The public release is readable by attackers as well as reviewers. That is accepted:
the security model benefits more from review than it loses from disclosure.
Vulnerability reports are handled privately under [SECURITY.md](../SECURITY.md)
until a fix is available.

## 11. Review and revisit triggers

This policy is reviewed when:

- a component is proposed for publication;
- a component moves between the public and private trees;
- the license of either tree changes;
- contribution volume makes the assignment requirement a practical obstacle;
- the project gains a legal entity, revenue, or a second maintainer.

D-8 is revisited specifically when **any** of these becomes true:

1. the kernel boots and prints to the screen;
2. an external contributor asks to reuse published code in another project;
3. the project receives its first contribution of non-trivial size;
4. any commercial revenue exists.

## 12. Decisions

Status legend: **Decided** — settled; **Provisional** — default in effect, expected
to be revisited; **Pending** — not decided, do not treat as settled.

Technical decisions D-1 to D-7 live in
[ARCHITECTURE.md](ARCHITECTURE.md#10-open-decisions).

**D-8. Public license.** *Pending.* Keep `LicenseRef-Dust-OS-1.0`
(source-available) or move the public core to a genuine open source license and
keep only the commercial layer proprietary. Currently in effect:
source-available, because that matches the plan of record and is reversible only
in the sense described in Section 6.

**D-9. `crypto/` publication.** *Decided (provisional).* Private for now.
Rationale: export-control considerations in some jurisdictions, and cryptographic
code is a plausible commercial component. Revisit if review value outweighs both.

**D-10. `wfs` publication.** *Decided (provisional).* Published with `fs/`,
because filesystems are in the approved scope. If `wfs` becomes the commercial
filesystem, move it to a private path in a future release and leave earlier
releases under their original license.

**D-11. Public build.** *Decided.* A public snapshot must build on its own from a
clean clone. If the private build description references private paths, the export
carries a build description that references only published paths. A snapshot that
does not build may still be released, but the release notes must say so.

**D-12. Sync direction.** *Decided (provisional).* Snapshot: the private tree is
canonical, and public contributions are applied to the private tree manually. This
is the simplest safe option for a single maintainer. Revisit when there is a
second regular contributor.

**D-13. Driver boundary.** *Decided.* Vendor-specific drivers live under
`drivers/vendor/` and are private. Everything else under `drivers/` is publishable.
The boundary is a directory convention so that it is mechanically checkable.

**D-14. Contribution terms.** *Decided.* Copyright assignment under
[CLA.md](../CLA.md). It is the strongest option for relicensing and closing, and
it is stated openly so that no contributor can claim surprise.

**D-15. Governance.** *Pending.* Single owner or a foundation. A foundation
requires a legal entity, a board, bylaws, and transfer of copyright and trademark;
none of that exists. Until it does, the single-owner model applies, and this
document plus [LICENSE](../LICENSE) is the governance.

**D-16. Release cadence.** *Decided.* Milestone snapshots tagged `v0.x.y`, not a
per-commit mirror. Each release has notes listing what is included, what is
excluded, and what is known broken.
