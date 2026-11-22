# Release Process

Status: **in force**, 22 November 2026. This document defines how DUST-OS is
versioned, built, verified, signed, distributed, and withdrawn. It applies to
internal milestones, evaluation builds, and customer releases.

A release is a controlled product event, not a push to a branch.

---

## 1. Principles

1. **Reproducible.** The same commit and toolchain produce the same binary.
2. **Gated.** No release bypasses a quality gate, including for the Owner.
3. **Traceable.** Every artifact maps to a commit, a build record, and an SBOM.
4. **Signed.** Every artifact has a digest and a signature.
5. **Private.** Artifacts are distributed through controlled channels, never
   through public mirrors.
6. **Reversible.** Every release has a rollback or withdrawal plan.

## 2. Versioning

Semantic Versioning, `MAJOR.MINOR.PATCH`, with pre-release suffixes:

```
0.1.0-alpha.1
0.1.0-beta.1
0.1.0-rc.1
0.1.0
1.0.0
```

Rules for the `0.x` period:

- `MINOR` increments for a milestone or a breaking change to the boot contract,
  the internal ABI, or the build interface.
- `PATCH` increments for compatible fixes.
- A pre-release suffix is mandatory until the first customer release.
- A version is never reused. A withdrawn version is marked withdrawn, not
  reissued under the same number.
- Build metadata may be appended for internal builds, e.g.
  `0.1.0-alpha.1+build.37`.

The version is recorded in one authoritative file and in the release tag. Do not
maintain two version numbers.

## 3. Release channels

| Channel | Audience | Content | Stability |
| --- | --- | --- | --- |
| Internal | Team | Every milestone build | Unstable; no notice |
| Evaluation | Prospective customer under NDA | Selected build + evaluation licence | Limited support |
| Customer | Paying customer | Signed build + EULA + notices | Per support agreement |
| Security fix | Affected customers | Minimal patch on a supported line | Expedited gates |

There is no public channel. See [IP_POLICY.md](IP_POLICY.md), D-8.

## 4. Quality gates

A release candidate must pass every gate. A failed gate is a stop, not a warning.

### Gate 1 — Build

- Clean build from a clean clone on the reference toolchain.
- Toolchain versions recorded and pinned.
- Build is reproducible: two independent builds produce identical digests.
- No warnings treated as acceptable if the build is configured with `-Werror`.
- No uncommitted files, no local paths, no build output in the source tree.

### Gate 2 — Boot and runtime

- Boots in QEMU with the supported OVMF build.
- Boots on at least one physical machine (two for a customer release).
- `ExitBootServices` succeeds 20 out of 20 consecutive boots.
- Serial log captured for every test configuration.
- No hang on any error path exercised by the test plan.

### Gate 3 — Tests

- The test harness runs and its results are archived.
- No known Critical or High defect is open.
- Medium defects are listed in the release notes with a workaround.
- Boot contract tests pass for the exact header version shipped.

### Gate 4 — Security

- No secrets in the source tree or artifacts (scanned).
- Dependency and artifact digests match the SBOM.
- Security review completed for changes touching the boot chain, memory
  management, cryptography, or privilege boundaries.
- Open security reports assessed; none may be silently ignored.

### Gate 5 — Legal and provenance

- Every third-party component is recorded in [NOTICE](../NOTICE) with its licence
  text.
- No file from [NOTICE](../NOTICE), Section 1 is present. This gate **blocks any
  release** until the boot headers are attributed, rewritten, or removed.
- Every team member who contributed has a signed IP assignment on file.
- The EULA, notices, and SBOM are included in the deliverable.
- Export-control review is recorded if cryptography is included.

### Gate 6 — Documentation

- Release notes written.
- Known limitations documented.
- Installation, boot, and recovery instructions updated.
- [CHANGELOG.md](../CHANGELOG.md) updated.

### Gate 7 — Approval

- The Owner signs the release record.
- The release record lists: version, commit, toolchain, gates passed, artifacts,
  digests, approver, and date.

## 5. Release candidate procedure

1. Cut `release/<version>` from `main`.
2. Update the version and [CHANGELOG.md](../CHANGELOG.md).
3. Run the full gate checklist; record evidence.
4. Build the release artifacts from the tagged commit.
5. Generate the SBOM and the third-party notices bundle.
6. Sign the artifacts and publish the digests to the release record.
7. Test the exact artifacts that will be delivered, not a local rebuild.
8. Obtain approval.
9. Tag the release, e.g. `v0.1.0-alpha.1`.
10. Distribute through the approved channel.
11. Archive the release record and evidence.

## 6. Artifacts and naming

Suggested naming:

```
dust-os-<version>-<arch>-<channel>.<ext>
dust-os-0.1.0-alpha.1-x86_64-eval.img
dust-os-0.1.0-alpha.1-x86_64-eval.img.sha256
dust-os-0.1.0-alpha.1-x86_64-eval.img.sig
dust-os-0.1.0-alpha.1-sbom.json
dust-os-0.1.0-alpha.1-notices.tar.gz
```

Rules:

- No version, no artifact. A file named `latest` is not a release.
- Every artifact has a SHA-256 digest.
- Every artifact is signed with the project's release key.
- The private signing key never leaves the approved hardware or secret store.
- The SBOM lists every component, version, licence, and digest.
- Debug symbols are archived separately and are not shipped to customers unless
  the agreement says otherwise.

## 7. Signing and verification

- Release signing uses a dedicated key, not a developer key.
- The public verification key is distributed to customers with the release.
- Customers can verify the digest and the signature independently.
- A build that cannot be reproduced is flagged in the release record.
- Key rotation is recorded, and old signatures remain verifiable.

## 8. Distribution

| Channel | Control |
| --- | --- |
| Private customer portal | Named accounts, MFA, download logging |
| Encrypted transfer | Per-customer link with expiry |
| Physical media | Labelled, logged, encrypted where practical |
| Evaluation | NDA + evaluation licence, watermark or build identifier |

Prohibited:

- public repositories, package registries, mirrors, or file-sharing links;
- sending source code in a chat or email without encryption and approval;
- distributing a build that is not in the release record.

## 9. Release notes

Every release note contains:

- version, date, and commit;
- what is included, and what is excluded;
- known defects and limitations, with workarounds;
- upgrade or migration notes;
- security fixes, without exploit detail before customers are notified;
- the supported hardware and firmware matrix;
- licence and support references.

Write for the reader who was not in the room.

## 10. Rollback and withdrawal

- **Rollback:** customers return to the previous supported version. The previous
  artifact and its record remain available.
- **Withdrawal:** a release is marked withdrawn with a reason and a date. It is
  not deleted from the record, and the same version is never reissued.
- **Security withdrawal:** notify affected customers privately, publish a fixed
  version, and document the issue after the agreed disclosure date.
- **Compromised key:** rotate the key, re-sign affected artifacts, and notify
  customers.

## 11. Support windows

Before the first customer release, no version is supported. After that:

| Release type | Support window |
| --- | --- |
| Major | Defined per customer agreement |
| Minor | Until the next minor plus an agreed period |
| Patch | Superseded by the next patch |
| Pre-release | No support |

Support scope and response targets are in [SUPPORT.md](../SUPPORT.md).

## 12. Records and retention

Keep for each release:

- the release record and approval;
- the commit and tag;
- the toolchain manifest;
- build logs and reproducibility evidence;
- test results and serial logs;
- the SBOM and third-party notices;
- artifact digests and signatures;
- customer distribution records.

Retention: for as long as the release is supported, plus the period required by
law and by customer agreements.

## 13. Release checklist

Copy this into the release issue and tick every line.

```
[ ] Version chosen and recorded in one place
[ ] CHANGELOG.md updated
[ ] Clean build from clean clone
[ ] Reproducible build verified
[ ] QEMU boot matrix passed
[ ] Physical hardware boot passed
[ ] ExitBootServices 20/20
[ ] Test suite passed; results archived
[ ] No open Critical or High defects
[ ] Security review completed
[ ] Secrets scan clean
[ ] SBOM generated and matches artifacts
[ ] NOTICE resolved; no unresolved-provenance file present
[ ] IP assignments on file for all contributors
[ ] EULA and notices bundled
[ ] Export review recorded, if cryptography included
[ ] Artifacts signed; digests published
[ ] Release notes written
[ ] Owner approval recorded
[ ] Tag created
[ ] Distribution restricted to the approved channel
```
