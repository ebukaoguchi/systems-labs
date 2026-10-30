# Module: Making Decisions — Conditional Branching and Control Flow in MIPS

**Pathway stage:** 03 · ISA
**Course:** SCIS 216 Computer Organization and Design — Lab 6 (Fall 2026)
**Format:** One lab session · **Level:** Early assembly programming

## Why this lab exists

Until this lab, student programs run straight downhill: every instruction executes, in order, exactly once. Real programs decide and repeat. This lab installs the machinery of decision in MIPS: comparisons with `slt`, conditional branches with `beq` and `bne`, the unconditional `j`, and labels as targets. Its discipline is translation: each exercise starts as a short C-style program with a register mapping, and the student's job is to lower it, faithfully, into assembly whose control flow has the same shape as the source.

## Learning objectives

By the end of this lab, students can:

- Use `slt` to turn a comparison into a value, and branch on that value.
- Implement an if / else if / else chain with `beq`, `bne`, labels, and `j`, including the jump that keeps one branch from falling into the next.
- Implement a while loop as a test at the top and a jump back from the bottom.
- Combine the two: a conditional inside a loop, with state traced by hand before the program is run.
- Predict a program's output for given inputs and check the prediction in QtSpim.

## Staged milestones

**Milestone 1 — The control-flow toolkit.** `beq` branches when two registers are equal, `bne` when they differ, `slt` writes 1 or 0 according to a less-than test, and `j` transfers control unconditionally. The deck's register refresher runs first ($s registers for values that must persist, $t registers for scratch work), because every exercise in this lab assigns registers before it assigns instructions.

**Milestone 2 — Worked Example 1: the if / else if / else chain** (`example1_if_else_chain.asm` accompanies this module). Translate: `a = 5, b = 3`; if `a < b`, result is `a + b`; else if `a == b`, result is `a * b`; else result is `a − b`. The two teaching moments are structural: the `slt` result is tested by branching against `$zero`, and every taken path ends with `j STORE`, because assembly has no braces to close a block; without the jump, execution falls through into the next branch's code. Expected output: **2**.

**Milestone 3 — Worked Example 2: a while loop with an if inside** (`example2_while_with_if.asm`). Sum with a twist: add even values of `i`, subtract odd ones, for `i` from 0 to 4. Students trace before running (sum goes 0, −1, 1, −2, 2), then meet the parity trick: `andi $t4, $t0, 1` isolates the lowest bit, so evenness becomes a branchable fact. Expected output: **2**.

**Milestone 4 — In-class tasks** (specifications and expected outputs given; solutions are not).

- *Task 1, if–else:* `x = 8, y = 5`; if `x < y`, `z = x + y`, else `z = x − y`. Mapping: x → $s0, y → $s1, z → $s2. Expected output: **3**.
- *Task 2, while loop with if–else:* for `i` from 0 while `i < 6`, add `i` to sum when `i < 3`, subtract it otherwise. The deck's expected trace runs 0, 1, 3, 0, −4, −9. Expected output: **−9**.

## Deliverables

Students submit:

- Source code for both in-class tasks, run in QtSpim
- A hand trace of Task 2's sum at each iteration, written before the program was run

## Instructor notes

- The fall-through bug is this lab's rite of passage: a student whose Example 1 prints the wrong branch's answer has almost always forgotten the `j STORE`, not misunderstood the comparisons. Diagnose in that order.
- Insist on the trace-first habit in Milestone 3. The loop's expected values are printed in the deck so students check their *understanding* against the trace and their *code* against QtSpim, two different checks that beginners constantly merge into one.
- Note for adopters: this lab's numbering follows the Fall 2026 sequence. In Spring 2026 the same material ran as Lab 5; the Fall deck is the current version.

## Source files

`Lab_6_Conditional_Branching_and_Control_Flow.pptx`, the full slide deck used in class, and the two worked-example programs accompany this module in the repository.

---

*Part of the Systems Labs collection — laboratory modules for computer organization, architecture, and operating systems, maintained by Ebuka Philip Oguchi, Spelman College. Modules may be adopted and remixed with attribution.*
