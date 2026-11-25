# Module: Inside the ALU — Adders, Multipliers, and Dividers

**Pathway stage:** 04 · Datapath (the hardware the ISA runs on)
**Course:** SCIS 216 Computer Organization and Design (packaged from the Fall 2026 lecture and in-class activity sequence)
**Format:** Two 75-minute sessions or one 2–3 hour lab · **Level:** Introductory systems

## Why this module exists

Students meet `add`, `mult`, and `div` as instructions, and they meet AND, OR, and NOT as physical gates on a breadboard. This module connects the two: it follows one continuous path from logic gates, to an adder, to the repeated add-and-shift loop that *is* multiplication, and the subtract-and-shift loop that *is* division. By the end, the ALU is not a box labelled "does arithmetic"; it is a small amount of hardware the students have watched work, cycle by cycle, in mathematics, in C, and in MIPS.

It is the bridge module of the collection: the breadboard lab ends at individual gates, and this module begins exactly there.

## Learning objectives

By the end of this module, students can:

- Explain how signed and unsigned binary values are represented, and decide whether an addition or subtraction overflows under a stated interpretation.
- Describe an adder as a circuit built from logic gates, trace its carry path, and explain what a partitioned adder gives up and gains.
- Trace the basic shift-and-add multiplier cycle by cycle.
- Trace the optimized multiplier and name the hardware it saves (and what it does not save: cycles).
- Trace an optimized restoring divider and identify dividend, divisor, quotient, and remainder at every step.
- Relate hardware multiplication and division to MIPS `mult`, `div`, `mfhi`, and `mflo`, including why software must check for division by zero itself.
- Compare basic, optimized, and faster arithmetic designs in terms of cycles, hardware, area, power, and control complexity, and defend a design choice for a stated workload.

## Before you start

- **Simulator:** QtSpim (MIPS32). Follow the shared guide: [Installing QtSpim for MIPS32](../setup/qtspim-installation.md).
- **Prerequisites:** the QtSpim Intro module (registers, `andi`, `add`, `sll`, `srl`) and, ideally, the Logic Gates on a Breadboard module (AND, OR, NOT, truth tables).
- **No physical build is required.** The adder discussion in Part 1 is a diagram and simulation activity. The physical builds are now their own modules in this group: the [Half Adder](../module-half-adder/) (one 7486 alongside one 7408), the [Full Adder](../module-full-adder/) (adding a 7432), the [Half Subtractor](../module-half-subtractor/) (adding a 7404), and the [Full Subtractor](../module-full-subtractor/); the 7486 is not in the breadboard lab's parts set. See `INSTRUCTOR_NOTES.md`.

## The module files

| File | What it is |
|------|------------|
| `traces.md` | The student worksheet: six parts with blank trace tables, design questions, the QtSpim tasks, a synthesis checkpoint, and expected final outputs for self-checking |
| `arithmetic_algorithms.c` | Both multiplication algorithms in C, with a self-checking `main` (worked example, worksheet values, and edge cases) |
| `multiplier.asm` | The basic shift-and-add loop in MIPS for QtSpim. Ships computing 6 × 3; students change the values to 9 × 6 |
| `division.asm` | MIPS `div` and the HI/LO registers, with a software divide-by-zero guard. Ships computing 17 ÷ 5; students change the values and then break the divisor on purpose |
| `diagrams/` | Five diagrams drawn for this module: `adder.svg`, `multiplier-basic.svg`, `multiplier-optimized.svg`, `divider-optimized.svg`, `alu-slice-schematic.svg` |
| `images/` | `alu-slice-breadboard-diagram.jpg`: the breadboard wiring diagram for a 1-bit ALU slice build still to come |
| `INSTRUCTOR_NOTES.md` | Pacing, the checkpoints that catch the common failures, the XOR/parts caution, and the publication boundary |

## The breadboard builds

Each physical build that grew up inside this module is now a module of its own, so it can be assigned, adopted, and found on its own. They are taken in build order: each one assumes the bench habits, and the single-node wiring rule, of the ones before it.

| Build | Module | Chips | What it shows |
|-------|--------|-------|---------------|
| Half adder | [The Half Adder — One XOR, One AND, and the First Column of Addition](../module-half-adder/) | 7486, 7408 | Sum and carry for one column of addition — and why one column is not enough: there is no carry-in |
| Full adder | [The Full Adder — Two Half Adders, One Carry Chain](../module-full-adder/) | 7486, 7408, 7432 | Two half adders and an OR gate: the column that accepts a carry-in, chained into every adder |
| Half subtractor | [The Half Subtractor — Difference and Borrow](../module-half-subtractor/) | 7486, 7404, 7408 | Difference and borrow for one column of subtraction — and the same limit: there is no borrow-in |
| Full subtractor | [The Full Subtractor — Subtraction with a Borrow-In](../module-full-subtractor/) | 7486, 7404, 7408, 7432 | Two half subtractors in series: the column that accepts a borrow-in, the full adder's mirror |

A fifth build, the 1-bit ALU slice, is still to come. Its gate-level schematic (`diagrams/alu-slice-schematic.svg`) and its breadboard wiring diagram (`images/alu-slice-breadboard-diagram.jpg`) are kept in this folder until it gets a module of its own.

## Staged milestones

**Milestone 1 — Numbers the hardware can hold (worksheet Part 0).** Eight-bit addition and subtraction under signed and unsigned interpretations. The deliverable insight: overflow is a property of the pattern *plus* the interpretation, and `add` and `addu` are the same hardware making different promises. *Checkpoint: every overflow decision is justified in one sentence.*

**Milestone 2 — From gates to an adder (Part 1).** Label the full adder, follow the carry chain, then block the carries to get a partitioned adder and reason about who benefits (multimedia lanes) and what is lost. *Checkpoint: the carry path is traced without prompting.*

**Milestone 3 — The basic multiplier (Part 2).** A completed 6 × 3 demonstration trace, then the student's own 9 × 6 trace. The loop, stated in register names: the multiplier decides, the multiplicand moves, the product accumulates. *Checkpoint: the student can predict the number of additions from the multiplier's bits before tracing.*

**Milestone 4 — The same algorithm in code (Part 6a, with `arithmetic_algorithms.c`).** The C and MIPS versions of the loop are matched instruction by instruction against the hardware steps, then run in QtSpim with the worksheet's values. *Checkpoint: the QtSpim output matches the hand trace.*

**Milestone 5 — The optimized multiplier (Part 3).** The multiplier moves inside the product register; students trace 10 × 5 in the combined register and name precisely what hardware disappeared. *Checkpoint: the student states, unprompted, that the saving is hardware, not cycles.*

**Milestone 6 — Faster designs and trade-offs (Part 4).** Parallel partial products with many adders; a completed comparison table; two design-defence paragraphs (a coin-cell sensor node, a phone processor). *Checkpoint: each defence names a cost, not only a benefit.*

**Milestone 7 — Division (Parts 5 and 6b).** Trial subtraction, restore-or-keep, one quotient bit per cycle; a 13 ÷ 3 trace; then the same split in MIPS, where the remainder and quotient surface as HI and LO, and the divide-by-zero check turns out to be software's job. *Checkpoint: divisor × quotient + remainder is verified against the dividend.*

## Deliverables

Students submit, per the synthesis checkpoint in `traces.md`:

- The completed multiplier, optimized-multiplier, and divider traces
- The completed design comparison and two scenario paragraphs
- The matched C-to-MIPS instruction list and one modified run of each QtSpim program
- One paragraph answering: "An adder, a multiplier, and a divider are all built from the same few operations. What differs between them?"

## What is, and is not, in this package

The package contains the module specification, the student worksheet with **expected final outputs only**, two verified code files in each of C and MIPS, and diagrams drawn for this module. The cycle-by-cycle answers to the worksheet's own exercises are not published, so the traces remain gradeable as evidence of process.

The Fall 2026 lecture decks the module was packaged from are **not** included: they mix textbook chapter material and diagrams with the instructor's activities, and two of them carry completed solutions to in-class tasks that an instructor may still run live. The worked examples published here (6 × 3 in both multiplier designs, 17 ÷ 5 in MIPS) are the lecture demonstrations, included in full on purpose.

Floating-point arithmetic, which the same lecture sequence covers after division, is deliberately out of scope: it is a representation topic and is planned as a separate follow-on module.

## Source files

Packaged from the Fall 2026 SCIS 216 sequence: Week 1 (number systems, two's complement, overflow), Lecture 002 (MIPS instructions, encoding, shifts, and logical operations), and Lecture 003 (addition and subtraction, adders and partitioned adders, the three multiplier designs, division hardware, and MIPS HI/LO), accompanying Patterson & Hennessy, *Computer Organization and Design*, 6th ed., chapters 2–3.

---

*Part of the Systems Labs collection: laboratory modules for computer organization, architecture, and operating systems, maintained by Ebuka Philip Oguchi, Spelman College. Modules may be adopted and remixed with attribution.*
