## Summary

<!-- One or two sentences: what problem does this solve? -->

## What this changes

<!-- Bullet points. Mention files or subsystems touched. -->

## Related issue

<!-- Fixes #, closes #, or "none". Work without an issue needs a reason. -->

## Author checklist

- [ ] My IP assignment and NDA are signed and on file.
- [ ] This is my original work, or the third-party code is approved and recorded
      in `NOTICE`.
- [ ] It contains no GPL, LGPL, AGPL, or SSPL code.
- [ ] I understand every line and can explain it in review.
- [ ] Material AI assistance is disclosed below.
- [ ] No secrets, credentials, customer data, or personal data are included.
- [ ] No direct push to `main`; this change arrives through this pull request.
- [ ] Commits are signed off (`git commit -s`).
- [ ] Documentation and `CHANGELOG.md` are updated if behaviour changed.
- [ ] The boot contract and its shared header are updated together, if touched.

## AI assistance

<!-- Required if used. Say which tool and which parts. Write "none" otherwise. -->

## Testing

<!-- Required. Delete nothing; write "not tested" if you did not test. -->

- Environment (QEMU version / hardware model):
- Boot method and command:
- What was tested:
- What was **not** tested, and why:

## Boot evidence

<!-- Required for boot, memory-management, and privilege-boundary changes.
Paste the serial log between the fences. -->

```
```

## Known defects and limitations

<!-- Required. "None known" is an acceptable answer only if true. -->

## Release impact

- [ ] No customer-visible change
- [ ] Needs a release note
- [ ] Changes the boot contract or ABI
- [ ] Changes a third-party dependency
- [ ] Security-sensitive; review requested
