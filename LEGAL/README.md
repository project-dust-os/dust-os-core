# Legal Templates

Status: **templates only**, 22 November 2026.

> **NOT LEGAL ADVICE.**
>
> These documents are starting points written in plain language. They have not
> been reviewed by a lawyer. Do not sign, send, or rely on them until a qualified
> Indonesian lawyer has reviewed and adapted them to the actual parties, the
> actual transaction, and current law.
>
> Using an unreviewed template can create an unenforceable or harmful agreement.
> The cost of review is small compared with the cost of a contract that does not
> work.

---

## 1. Index

| Template | Use | Parties |
| --- | --- | --- |
| [EULA.md](EULA.md) | Licence terms delivered with a customer product | Licensor and end customer |
| [IP_ASSIGNMENT.md](IP_ASSIGNMENT.md) | Assignment of work product to the project | Project owner and team member or contractor |
| [NDA.md](NDA.md) | Mutual confidentiality before discussions | Project owner and counterparty |

Missing documents that will be needed later, and must be drafted by counsel:

- founders' agreement, if a co-founder joins;
- employment agreement, once a legal entity exists;
- contractor/services agreement;
- commercial licence and support agreement;
- source-code escrow agreement;
- reseller or OEM agreement;
- data-processing agreement.

## 2. Hard rules

1. **Counsel review is mandatory** before first use of any template.
2. **Capacity is mandatory.** The Owner is a minor. A parent or guardian must act,
   or an adult-owned legal entity must be the contracting party. A minor's
   signature alone may be voidable.
3. **Every page is initialled, and the signature block is complete.** Identify
   the signatory, their role, and their authority.
4. **Use the correct entity.** If a PT, CV, or foundation exists, the entity is the
   party, not the individual.
5. **Keep the signed original** outside the repository. Never commit signed
   agreements containing personal data.
6. **Version every change.** A template change gets a version number and a date.
7. **Do not mix templates.** An NDA is not an IP assignment, and an EULA is not a
   support agreement.
8. **Stamp duty and formalities** are decided by counsel, not guessed.
9. **Electronic signature** is used only if counsel confirms it is valid for the
   document and the parties.
10. **Translation.** These templates are in English. If an Indonesian-language
    version is executed, counsel decides which version controls.

## 3. Order of precedence

For a given party, the binding order is:

1. the signed agreement between the parties;
2. the schedules and order forms attached to it;
3. the project policies in `DOCUMENTS/`;
4. this README and the unsiged templates.

Where a signed agreement conflicts with a policy, the signed agreement controls
for that party. It does not change the policy for anyone else.

## 4. Signing checklist

```
[ ] Correct legal parties and entity names
[ ] Authority of each signatory confirmed
[ ] Guardian signature included, if a party is a minor
[ ] Scope, deliverables, and payment defined
[ ] IP ownership and assignment clear
[ ] Confidentiality obligations clear
[ ] Licence grant and restrictions clear
[ ] Support and warranty position clear
[ ] Liability and indemnity reviewed
[ ] Term, termination, and survival reviewed
[ ] Governing law and dispute forum reviewed
[ ] Export-control and sanctions position reviewed
[ ] Third-party and open-source obligations addressed
[ ] Privacy and data-processing terms addressed
[ ] Every schedule and annex attached
[ ] Every page initialled; originals stored securely
[ ] Copy delivered to each party
[ ] Record entered in the contract register
```

## 5. Contract register

Keep a register, outside the repository, with:

| Field | Example |
| --- | --- |
| Agreement ID | `NDA-2026-001` |
| Type | NDA / IP assignment / EULA / commercial |
| Counterparty | Name and entity |
| Signatory and authority | Name, role |
| Effective date | 2026-11-22 |
| Term and renewal | 3 years, no auto-renewal |
| Storage location | Physical safe or approved encrypted store |
| Review date | Annual |
| Notes | Guardian signature, translation, stamp duty |

## 6. Legal caveats

- **Minor owner.** Under Indonesian law, a 14-year-old is generally not competent
  to enter binding contracts, employ people, or form a company. A guardian or an
  adult-owned entity must act.
- **No attorney-client relationship.** Reading these templates does not create
  one.
- **No guarantee of enforceability.** Even a well-drafted contract depends on
  capacity, formality, and the facts.
- **Local law may differ.** If a counterparty is outside Indonesia, counsel must
  review the governing law and jurisdiction.
- **Crypto and export.** Cryptography may trigger export-control obligations;
  counsel and, where needed, a specialist must review before distribution.

## 7. Contact

Project contact: **dvennote65@gmail.com**

Bring a specific transaction and the actual parties to counsel. "Review this
template" is not enough.
