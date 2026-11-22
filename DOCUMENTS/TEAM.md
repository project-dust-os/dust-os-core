# Team, Roles, and Hiring

Status: **planning document**, 22 November 2026. It describes the team the project
needs and the conditions for adding people. It does not announce any opening, and
nothing here is a promise of employment, equity, or payment.

Context: DUST-OS is private and pre-alpha. The current team is one person, and
that person is a minor. See [IP_POLICY.md](IP_POLICY.md), Section 15.

---

## 1. Current state

| Item | State |
| --- | --- |
| Team size | 1 |
| Roles filled | Owner, architect, kernel developer, build engineer, tester, writer |
| Bus factor | 1 |
| Revenue | None |
| Legal entity | None |
| Product | Does not boot yet |

The honest description is: a solo project with a large scope. The priority is not
to grow the team; it is to make the project worth joining.

## 2. Roles

| Role | Responsibility | When needed |
| --- | --- | --- |
| Owner / architect | Direction, boot contract, IP, releases, final approval | Now |
| Kernel developer | Memory management, scheduling, IPC, syscalls | Second technical hire |
| Platform / drivers | ACPI, interrupts, timers, storage, input, hardware bring-up | Third technical hire |
| Build / CI / QA | Reproducible builds, test harness, QEMU matrix, hardware lab, regression triage | **First hire** |
| Documentation / support | Onboarding, release notes, customer-facing docs | When customers exist |
| Security reviewer | Boot chain, memory safety, crypto, threat model | Part-time or contract |

One person may hold more than one role in a small team. The roles are
responsibilities, not job titles.

## 3. Team size

| Size | What it buys | Limitation |
| --- | --- | --- |
| 1 | Maximum learning speed | Bus factor 1; no review; no product |
| 2 | Review, some redundancy | One departure stops the project |
| 3 | Sustainable minimum; one person can take leave | Still no slack for support and sales |
| 4–5 | Real subsystem ownership; visible progress | Needs coordination and written process |
| 6–8 | Kernel, platform, QA, docs, support | Requires revenue or funding |
| 10+ | Product, security, support, sales | Only with a real customer base |

**Minimum sustainable: 3. Minimum useful: 2. Real progress: 4–5.**

Do not optimise for headcount. A team of five without a build system produces
five times as many unreproducible bugs.

## 4. Composition

For a kernel project, three kernel developers are often less useful than:

1. **Owner** — kernel core, boot contract, architecture.
2. **Generalist low-level engineer** — C and assembly, QEMU and hardware
   debugging, drivers.
3. **Build/CI/QA engineer** — reproducibility, test harness, regression triage,
   hardware matrix.

The third role is the most underestimated. Without it, most engineering time is
spent rediscovering whether a bug is new, environmental, or imaginary.

If only one person can be added, add **build/CI/QA**, not another kernel
developer.

## 5. Hiring readiness gates

Do not recruit until **all** of these are true:

- [ ] The kernel boots and prints to the screen and serial.
- [ ] One command builds the project from a clean clone.
- [ ] The boot contract is written and versioned.
- [ ] The build is reproducible on the reference toolchain.
- [ ] A test harness exists and runs in CI.
- [ ] Tasks are written down, with acceptance criteria, in an issue tracker.
- [ ] An IP assignment and NDA are ready for signature.
- [ ] Access control works: MFA, protected `main`, CODEOWNERS.
- [ ] Onboarding documentation exists.
- [ ] There is a legal entity or a guardian able to sign, and a budget.
- [ ] There is enough work to keep the person busy for at least three months.

The last gate matters. Hiring someone before the work is defined converts an
engineer into a project manager of a project that does not exist yet.

## 6. Order of hiring

1. **Build/CI/QA** — contract or part-time first. It removes the biggest
   bottleneck and does not require deep kernel knowledge.
2. **Kernel generalist** — only after the boot path and memory manager exist.
3. **Platform/driver engineer** — when real hardware support begins.
4. **Support/documentation** — when there are customers, not before.
5. **Security reviewer** — contract, before the first customer release.

## 7. Employment models

| Model | Use when | Risk |
| --- | --- | --- |
| Co-founder | Long-term shared ownership and risk | Requires a founders' agreement, vesting, and clarity on who decides |
| Employee | Stable, full-time work exists | Requires a legal entity, payroll, and tax compliance |
| Contractor | A bounded task with a definition of done | Must still sign IP assignment and NDA |
| Intern | Learning, with supervision | Must sign the same paperwork; do not use interns as unpaid labour |
| Open-source contributor | **Not applicable** | The project is private; the CLA is retired |

Equity, revenue sharing, and unpaid work must be written down before work starts.
Verbal promises destroy teams.

## 8. Access levels

| Level | Access | Who |
| --- | --- | --- |
| 0 | None | Applicants, former team members |
| 1 | Read-only documentation | Evaluators under NDA |
| 2 | Source read + issues | New team members during onboarding |
| 3 | Branch push + pull requests | Regular team members |
| 4 | Merge to protected branches, release builds | Senior team members |
| 5 | Repository settings, secrets, signing keys, legal records | Owner only |

Access is granted by name, reviewed every six months, and removed the same day an
engagement ends. Shared accounts are prohibited.

## 9. Onboarding

### Before day one

- Signed IP assignment and NDA on file.
- Account created with MFA; access level recorded.
- Hardware and toolchain ready.
- A named mentor and a first task.

### Week one

- Read [ARCHITECTURE.md](ARCHITECTURE.md), [IP_POLICY.md](IP_POLICY.md), and
  [CONTRIBUTING.md](../CONTRIBUTING.md).
- Build the project, boot it in QEMU, capture serial output.
- Fix one small documented defect and land it through review.
- Explain the boot contract back to the mentor.

### Day 30

- Owns one small subsystem or one test area.
- Has landed at least three reviewed changes.
- Can reproduce a boot failure from a bug report.

### Day 60

- Reviews other people's changes.
- Has written or updated a design note.
- Knows where the secrets are and why they are not in the repository.

### Day 90

- Owns a roadmap item end to end.
- Has participated in a release gate.
- Has given a candid assessment of what is slow and what is broken.

## 10. Performance and expectations

- Judge output by merged, tested, documented changes, not by hours or lines.
- A person who cannot explain their code cannot maintain it; that is a review
  blocker, not a style issue.
- Every person must be able to take two weeks off without the project stopping.
  If that is impossible, the process is broken.
- Burnout is a project risk. A 14-year-old founder and a small team cannot
  sustain crunch.

## 11. Legal constraints

- A minor cannot generally sign an enforceable employment contract, hire people,
  or form a company in Indonesia.
- A parent or guardian must act, or an adult-owned entity must be formed, before
  anyone is employed or paid.
- Every team member signs [LEGAL/IP_ASSIGNMENT.md](../LEGAL/IP_ASSIGNMENT.md) and,
  if applicable, [LEGAL/NDA.md](../LEGAL/NDA.md).
- Templates require review by an Indonesian lawyer before use.
- Do not promise equity, salary, or a job title before the entity and the
  paperwork exist.

## 12. Decision

**Do not recruit today.** The sequence is:

1. make the kernel boot;
2. make the build reproducible;
3. write the tasks and the onboarding;
4. fix the legal capacity problem;
5. hire one build/CI/QA person;
6. revisit after three months.

The trigger to add the next person is not "we feel slow". It is "we are turning
down work because the queue is full and the process is documented".
