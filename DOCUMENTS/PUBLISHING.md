# Publishing the Public Release

This document describes how the public source release is produced from the private
development tree. It is published so that the release process is verifiable, not
because contributors need to run it.

The public release is **not** this repository with a different remote. It is a
curated snapshot of an allow-listed subset, with no private history attached.

Scope is defined in [LICENSING.md](LICENSING.md). If this document and that one
disagree, LICENSING.md wins.

---

## 1. Principle

- The private tree is canonical.
- The public release is generated, reviewed, and tagged.
- Never publish by flipping repository visibility. That publishes everything,
  including history.
- Never rewrite published history. If a mistake is published, publish a corrected
  release and document it.

## 2. Pre-flight checklist

Run every step before the first public release and before every later release.

### Step 1 — Scope

- [ ] Every published path is listed as published in LICENSING.md.
- [ ] The snapshot is generated from [PUBLIC_PATHS.txt](../PUBLIC_PATHS.txt), and
      every included path appears there.
- [ ] No path marked private is present in the snapshot.
- [ ] Only files tracked by git are copied; no build output and no untracked file
      enters the snapshot.
- [ ] Public headers do not include private headers. Build the snapshot from a
      clean clone to prove it.
- [ ] Nothing in the snapshot imports a private build file that references paths
      outside the snapshot.

### Step 2 — Provenance

- [ ] Every third-party file is listed in `NOTICE` with URL, license, and the full
      license text.
- [ ] No file with unresolved provenance is included.
- [ ] **Current blocker:** `boot/bootmgrc/include/*` has no attribution. `boot/`
      is approved for publication, so those files must be resolved (attribute,
      rewrite, or delete) before `boot/` can ship.
- [ ] Every original file carries the SPDX header from `COPYRIGHT.md`, or is
      deliberately excluded.

### Step 3 — Secrets and personal data

- [ ] No credentials, tokens, keys, or `.env` files, in the snapshot **or in its
      history**.
- [ ] No absolute local paths. CMake cache files are the usual offender: a
      `CMakeCache.txt` records the builder's home directory.
- [ ] No private hostnames, IP addresses, or internal URLs.
- [ ] Personal email addresses appear only where intended.
- [ ] Build output is not tracked. The private index currently records
      `build/CMakeCache.txt` and `build/CMakeFiles/*`; these must be removed before
      any commit that could reach a public release.

### Step 4 — Documents

- [ ] `README.md` describes the public subset accurately, including its status.
- [ ] `LICENSE`, `COPYRIGHT.md`, `NOTICE`, and `CLA.md` are present and current.
- [ ] `CONTRIBUTING.md` points to `CLA.md` and to the publication scope.
- [ ] `SECURITY.md` gives a private reporting channel.
- [ ] No internal policy document (including this file and LICENSING.md) is
      included unless deliberately published.

### Step 5 — Build and verify

- [ ] The snapshot builds from a clean clone on a clean machine or container.
- [ ] If it does not build, the release notes say so explicitly. Do not imply a
      working system.
- [ ] The tag, the release notes, and the recorded private commit hash match.

### Step 6 — Tag and record

- [ ] Tag the public release (`v0.x.y`) and the private commit it came from.
- [ ] Write release notes: what is included, what is excluded, what is known
      broken, and which license applies.
- [ ] Archive the export manifest used for this release.

## 3. History policy

**Do not publish the private history.** Use one of these instead:

| Approach | Risk | Recommendation |
| --- | --- | --- |
| Fresh public repository, files copied from an allow-listed export | Low; history starts empty | **Recommended** |
| Public repository seeded from `git filter-repo` on a copy | High; every commit must be inspected for private paths and secrets | Not for a first release |
| Public branch of the private repository | Very high; one wrong push publishes everything | Do not use |
| Two repositories, public canonical for public paths | Medium; requires a stable sync direction (D-12) | Good later |

A fresh repository is recommended because history is permanent: a secret or a
private file in an old commit is published forever, even if deleted in a later
commit.

## 4. Contribution flow

Until D-12 is decided, assume **snapshot**:

1. Contributor opens a pull request against the public repository.
2. The contributor states acceptance of `CLA.md` and signs off commits.
3. You review. Reject anything you cannot explain or that violates scope.
4. Apply the patch to the private tree, run the tests, and commit there first.
5. The change appears in the next public release.

If the public repository is later made canonical for the published paths, the
direction reverses: private pulls from public, and the private tree never pushes
unreviewed commits into public.

## 5. Moving code between trees

### Public → private

Permitted only if:

- the Owner holds all rights in that code (original work, or assigned by CLA);
- the code is removed from the public repository in a later release, not rewritten
  out of published history;
- the last public release containing it stays available under its original
  license;
- the release notes state that the component moved.

### Private → public

Permitted only if:

- no third-party or export-restricted component is included;
- the code has the project's SPDX header or is attributed in `NOTICE`;
- the public build still succeeds with the component included;
- the scope table in LICENSING.md is updated in the same change.

## 6. Licensing a release

- Every release names its license in the README and in the release notes.
- A license change never applies retroactively.
- The `LICENSE` file in the snapshot is the one that governs that snapshot.
- If the public license ever changes, both versions stay available and are
  identified by tag.

## 7. Incident response

If private material is published by mistake:

1. Do not silently rewrite history; assume it has been mirrored.
2. Remove the material from the current tree in a new release.
3. Rotate any exposed credentials immediately.
4. Publish a short note describing what was exposed and for how long.
5. Update this checklist so the same mistake cannot repeat.
