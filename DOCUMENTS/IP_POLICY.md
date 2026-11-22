# Intellectual Property and Licensing Policy

Status: **in force**, 22 November 2026. This document is the internal policy of
record for ownership, confidentiality, third-party code, customer licensing, and
brand use. It is not a contract and it is not legal advice.

The binding notice for the software is [LICENSE](../LICENSE). Contract templates
are in [LEGAL/](../LEGAL/README.md). Where this policy and a signed agreement
differ, the signed agreement controls for that party.

---

## 1. Purpose and scope

This policy answers five questions:

1. Who owns what?
2. Who may see it?
3. What may be brought in from outside?
4. What may be sold, and on what terms?
5. How is the brand protected?

It applies to every file in this repository, every build artifact, every design
note, every customer deliverable, and every person with access.

## 2. Ownership

| Asset | Owner | Record |
| --- | --- | --- |
| Original source code, headers, assembly, linker scripts | Owner | [COPYRIGHT.md](../COPYRIGHT.md), git history |
| Documentation, designs, specifications | Owner | git history |
| Build scripts and release tooling | Owner | git history |
| The names "DUST-OS" and "Dust OS", and any logo | Owner | Section 8 |
| Domain names and social accounts | Owner | Owner's registrar records |
| Third-party components | Their respective owners | [NOTICE](../NOTICE) |
| Work by team members | Owner, by assignment | [LEGAL/IP_ASSIGNMENT.md](../LEGAL/IP_ASSIGNMENT.md) |

Rules:

- The project is **not** open source and **not** source-available. No license is
  granted by possession.
- Every original file carries the header in [COPYRIGHT.md](../COPYRIGHT.md).
- Third-party files keep their original headers. The project header must never be
  added to them.
- Ownership records are kept for as long as the software is distributed plus the
  period required by law.

## 3. Confidentiality classification

Every document, file, and artifact has one classification. **The default is
Confidential.**

| Tier | Label | Examples | Handling |
| --- | --- | --- | --- |
| 4 | **Restricted** | `crypto/`, boot-chain security details, signing keys, customer data, legal records, incident reports, unannounced vulnerabilities | Named persons only; encrypted at rest; no external sharing; access logged |
| 3 | **Confidential** | Kernel, drivers, filesystems, roadmap, pricing, customer names, this policy | Team members under NDA; approved systems only; no public posting |
| 2 | **Internal** | General engineering notes, meeting notes, non-sensitive tooling docs | Team members; may be shared inside the organisation |
| 1 | **Public** | Approved marketing copy, published datasheets, this repository's public-facing description | Released only with the Owner's written approval |

Rules:

- Classification is recorded in the document header where practical, and in the
  repository path where possible.
- `crypto/`, `firmware/`, `test/`, and `bin/` are **Restricted** by default.
- Moving material to a lower tier requires the Owner's approval.
- Screenshots, logs, and crash dumps inherit the classification of their source.
- A document that mixes tiers is classified at the highest tier it contains.

## 4. Repository access and change control

| Control | Requirement |
| --- | --- |
| Repository visibility | Private |
| Accounts | Named individuals only; no shared accounts |
| Authentication | Multi-factor authentication mandatory |
| Default branch | `main`, protected |
| Direct push | Prohibited, including by the Owner |
| Review | At least one approval; protected paths need the Owner |
| Signed commits | Required where configured |
| Access review | Every 6 months and on every departure |
| Access removal | Same day an engagement ends |
| Secrets | Never committed; stored only in the approved secret store |
| Backups | Encrypted, access-controlled, tested |

The technical rules for changes are in [CONTRIBUTING.md](../CONTRIBUTING.md).
Path ownership is in [.github/CODEOWNERS](../.github/CODEOWNERS).

## 5. Team work and IP assignment

The Contributor License Agreement (CLA) is **retired**. It was designed for
volunteer contributors to a public project and does not fit an employer or
contractor relationship.

Every person who writes code for the project signs
[LEGAL/IP_ASSIGNMENT.md](../LEGAL/IP_ASSIGNMENT.md) **before** their first change
is merged. The assignment must:

- assign present and future rights in the work to the Owner, or to the legal
  entity that owns the project;
- include a fallback exclusive licence where assignment is not permitted;
- include a waiver or consent for moral rights to the extent permitted by law;
- include confidentiality and further-assurances clauses;
- be countersigned by a parent or guardian if the person is a minor.

Additional rules:

- Interns, contractors, and part-time helpers sign the same assignment. There is
  no "small contribution" exception.
- A person who cannot sign cannot commit. Their work may be accepted as a
  deliverable from a company that has signed a contractor agreement.
- Authorship credit is recorded in [AUTHORS.md](../AUTHORS.md) and in git
  metadata; it does not imply ownership.
- The Owner must keep the signed originals, not copies in the repository.

## 6. Third-party code and open-source policy

### 6.1 Principle

The product must be distributable as a whole. One file of unknown provenance or
one copyleft file can make the entire product undistributable. When in doubt, do
not add it.

### 6.2 Allowed licences

| Licence | Status | Conditions |
| --- | --- | --- |
| MIT | Allowed | Preserve copyright and permission notice |
| BSD-2-Clause | Allowed | Preserve notice |
| BSD-3-Clause | Allowed | Preserve notice; no endorsement claim |
| ISC | Allowed | Preserve notice |
| Apache-2.0 | Allowed with review | Preserve NOTICE and licence; patent clause reviewed |
| Zlib | Allowed | Preserve notice |
| CC0 / public domain | Allowed with evidence | Provenance must be documented |
| Unlicense | Allowed with review | Provenance must be documented |

### 6.3 Denied licences

| Licence | Status | Reason |
| --- | --- | --- |
| GPL, LGPL, AGPL | Denied | Copyleft conflicts with proprietary distribution |
| SSPL | Denied | Service restrictions |
| BSL / BUSL | Denied without approval | Time-delayed source-available terms |
| MPL-2.0, EPL-2.0 | Review required | File-level copyleft; may be acceptable only in isolated tools |
| No licence / unknown provenance | Denied | Not distributable |

### 6.4 Process for adding a dependency

1. Open a dependency request with the upstream URL, version, licence, and why the
   code cannot be written in-house.
2. Record the licence text and copyright line in [NOTICE](../NOTICE).
3. Confirm that the licence is allowed, or obtain the Owner's written approval.
4. Add the component to the SBOM and to the release record.
5. Never vendor a dependency by copying files without the licence text.

### 6.5 Unresolved provenance

Files in [NOTICE](../NOTICE), Section 1 are treated as third-party until proven
otherwise. They block commercial distribution. They must be attributed,
rewritten, or removed before any customer release.

## 7. Customer licensing and commercial model

### 7.1 What is sold

The intended commercial layers are:

- commercial licences to the operating system for OEM, embedded, and appliance
  use;
- support and maintenance agreements;
- integration and porting work;
- proprietary drivers and firmware for specific hardware;
- tools and services built around the system.

The kernel alone is rarely the sellable object. The business is expected to sell
outcomes — a device that boots, a port that works, a support line that answers —
not a source tarball.

### 7.2 How it is licensed

| Deal type | Instrument | Notes |
| --- | --- | --- |
| Evaluation | Evaluation licence, short term | No production use; no redistribution |
| Commercial product | Commercial agreement + [EULA template](../LEGAL/EULA.md) | Per customer, per product, per volume |
| OEM / embedded | Commercial agreement + hardware schedule | Defines devices, volumes, support |
| Source escrow | Escrow agreement | Only if a customer requires it; counsel drafts it |
| Support | Support agreement | Scope and targets in [SUPPORT.md](../SUPPORT.md) |

Rules:

- No licence is implied by delivering a binary, a demo, or a repository link.
- Every customer deliverable is accompanied by the applicable licence terms and
  the third-party notices.
- Pricing, discounts, and contract terms are Confidential.
- A customer may not sublicense, reverse engineer, or redistribute except as the
  agreement expressly allows.
- Open-source obligations are checked before every customer release.

### 7.3 No public distribution

There is no public download, public repository, package registry publication, or
community edition. This is D-8.

## 8. Trademarks and brand

- "DUST-OS", "Dust OS", the project logo, and any confusingly similar mark are
  owned by the Owner.
- No trademark licence is granted by the software licence, by this repository, or
  by any technical document.
- The marks may be used only to refer accurately to the project, with the Owner's
  written permission for commercial use.
- A fork, derivative, or modified build must not be presented as DUST-OS or as
  endorsed by the Owner. Derivative distribution is prohibited in any case.
- Domain names and social handles are registered in the Owner's name and are
  treated as Restricted assets.
- Public statements about the project, customers, or partners require the Owner's
  approval.

## 9. Cryptography and export control

- Cryptographic code is **Restricted**.
- Before distributing cryptography outside Indonesia, the Owner must review the
  applicable export, import, and end-use rules, and record the conclusion.
- Do not assume that published algorithms, open specifications, or "public
  domain" implementations remove export obligations.
- Sanctions and restricted-party screening is required for customers and
  partners before a contract is signed.
- A customer request for cryptographic capability is escalated to the Owner, not
  answered informally.

## 10. AI-assisted development

AI assistants may be used by Authorised Persons as a tool, under these rules:

- The author must understand and be able to explain every line they commit.
- Do not submit Restricted code, customer data, or credentials to a service that
  trains on or retains inputs without approval.
- Generated code is treated as third-party code until reviewed. Its provenance
  must be plausible and its licence must not contaminate the product.
- The pull request must disclose material AI assistance.
- The author remains fully responsible for defects, security, and licensing.
- AI output is never accepted as a substitute for testing evidence.

## 11. Privacy and personal data

- The project collects no telemetry by default.
- Personal data of team members, customers, and contacts is processed under
  [PRIVACY.md](../PRIVACY.md) and applicable law, including Indonesia's Law No. 27
  of 2022 on Personal Data Protection.
- Customer data is **Restricted**. It is never used in development, tests, or AI
  tools without a written basis and anonymisation.
- Data minimisation applies: collect only what the task requires.

## 12. Leak and incident response

On a suspected leak of Confidential or Restricted material:

1. **Contain.** Revoke access, rotate credentials and keys, disable the exposed
   channel.
2. **Preserve evidence.** Do not delete logs or messages.
3. **Assess.** Identify what was exposed, to whom, and for how long.
4. **Notify.** Inform the Owner immediately; notify affected customers and
   authorities where required by law or contract.
5. **Remediate.** Remove the exposure, fix the cause, and update controls.
6. **Record.** Write a short incident note and the lessons learned.

Do not negotiate with an extortionist, and do not make public statements without
the Owner's approval.

## 13. Review and revisit triggers

This policy is reviewed when:

- a legal entity is formed;
- the first employee or contractor is engaged;
- the first customer agreement is signed;
- a new dependency is proposed;
- a release is prepared;
- a jurisdiction outside Indonesia is targeted;
- a leak, dispute, or ownership question arises;
- the Owner turns 18 or gains a legal representative.

## 14. Decisions

Status: **Decided** — settled; **Provisional** — default in effect, expected to
be revisited; **Pending** — not decided, do not treat as settled.

Technical decisions D-1 to D-7 are in
[ARCHITECTURE.md](ARCHITECTURE.md#10-open-decisions).

**D-8. Public release.** *Decided.* There is none. DUST-OS is private and
proprietary, with no source-available or open-source edition. The earlier
source-available plan is withdrawn. This decision can only be reopened by the
Owner in writing, after legal review and after every provenance issue in NOTICE
is resolved.

**D-9. Disclosure of source.** *Decided.* Source is disclosed only under a signed
NDA and a written agreement, on a case-by-case basis, to auditors, partners,
customers, or acquirers. Disclosure does not create a public licence and does not
permit redistribution.

**D-10. Confidentiality classification.** *Decided.* The four-tier scheme in
Section 3 applies. The default is Confidential. Restricted material is named-person
only.

**D-11. Contributor terms.** *Decided.* Written IP assignment before the first
merged change. The CLA is retired. Minors require a guardian's countersignature.

**D-12. Third-party code.** *Decided.* Allow-list only. Copyleft is prohibited.
Unknown provenance is prohibited in shipped artifacts. Every component is recorded
in NOTICE and in the SBOM.

**D-13. Cryptography and export.** *Decided (provisional).* `crypto/` is
Restricted. Export review is required before distribution outside Indonesia. The
provisional status reflects the absence of a formal export classification.

**D-14. Customer licensing.** *Decided.* Written commercial agreement plus the
EULA template for each customer. No implied licence. No public distribution.

**D-15. Trademarks.** *Decided.* The name and logo are Owner-owned; no licence is
granted; derivatives may not use the mark.

**D-16. Governance and legal entity.** *Pending.* An individual project
represented by a parent or guardian, or an adult-owned PT/CV/foundation. Until an
entity exists, the Owner cannot sign enforceable commercial contracts alone. This
is a legal blocker, not a documentation task.

**D-17. Versioning and release gates.** *Decided.* Semantic Versioning, internal
milestones, and the quality gates in
[RELEASE_PROCESS.md](RELEASE_PROCESS.md). No release bypasses a gate.

**D-18. Access and change control.** *Decided.* Private repository, MFA,
protected `main`, mandatory review, CODEOWNERS, and signed commits where
configured. No direct pushes.

## 15. Legal status

This policy is written to professional standards, but it is **not legal advice**
and has not been reviewed by counsel.

Two facts limit what can be done today:

1. **The Owner is a minor.** Under Indonesian law, a 14-year-old is not
   generally competent to enter binding contracts, employ people, or form a
   company. Agreements signed alone may be voidable. A parent or guardian must
   act, or an adult-owned legal entity must be formed.
2. **Templates are templates.** The documents in [LEGAL/](../LEGAL/README.md)
   require review and adaptation by a qualified Indonesian lawyer before use.

Until both are addressed, the project can develop software and prepare
documentation, but it cannot reliably sell, hire, or enforce a licence.
