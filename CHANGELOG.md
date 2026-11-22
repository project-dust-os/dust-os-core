# Changelog

All notable changes to DUST-OS are recorded here. The format follows
[Keep a Changelog](https://keepachangelog.com/en/1.1.0/), and the project uses
[Semantic Versioning](https://semver.org/spec/v2.0.0.html) as described in
[DOCUMENTS/RELEASE_PROCESS.md](DOCUMENTS/RELEASE_PROCESS.md).

This file records product and repository changes, not every commit. A change that
affects a customer, the boot contract, or a dependency must appear here.

## [Unreleased]

### Added

- Internal engineering handbook, engineering policy, release process, and team
  plan.
- Contract templates under `LEGAL/` (EULA, IP assignment, NDA), marked as
  templates requiring legal review.
- Support and privacy policies.
- Code ownership map and internal issue and pull-request templates.

### Changed

- Documentation reorganized for a private, commercial project.
- License notice rewritten as proprietary and confidential; the source-available
  license and the public-release plan are withdrawn.
- Contribution terms changed from a CLA to a written IP assignment.

### Removed

- Public release manifest and publication procedure.
- Contributor License Agreement.
- `export-ignore` release filtering.

### Security

- No security release yet. See [SECURITY.md](SECURITY.md).

## [0.0.0] — 2026-11-22

### Added

- Initial documentation baseline: architecture, ownership, confidentiality,
  release gates, team plan, support, privacy, and legal templates.

### Notes

- Pre-alpha. The kernel does not boot and no artifact is released.
- No customer release exists, and none may be produced while
  [NOTICE](NOTICE), Section 1 remains unresolved.
