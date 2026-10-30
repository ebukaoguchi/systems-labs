# Module: When Registers Run Out — Register Spilling in MIPS

**Pathway stage:** 03 · ISA
**Course:** SCIS 216 Computer Organization and Design — Lab 5 (Fall 2026)
**Format:** One lab session · **Level:** Assembly programming, after procedures and the stack

## Why this lab exists

Registers are the fastest storage in the machine, and there are only 32 of them. When a computation has more live values than registers can hold, something has to give: a value is *spilled*, written to the stack, its register reused, and the value reloaded when it is needed again. Compilers do this constantly and invisibly; this lab makes students do it by hand, once, in a function small enough to hold in their heads. It also draws the distinction students most often blur: saving `$ra` in a non-leaf procedure and spilling a value look like the same three instructions, but they happen for entirely different reasons.

## Learning objectives

By the end of this lab, students can:

- Define register spilling and identify the moment it becomes necessary: a value is still live, but its register is needed for something else.
- Perform a spill and a reload with `$sp`, `sw`, and `lw`, keeping the stack balanced.
- Distinguish saving `$ra` (preserving a return address that a `jal` would overwrite) from spilling (freeing a register for reuse), and state where each can occur.
- Manage a stack frame holding both kinds of saves at different offsets without confusing their slots.
- Explain, with their own code as evidence, why spilling is a compiler's everyday decision rather than an error condition.

## Staged milestones

**Milestone 1 — Two saves that are not the same.** The deck's comparison table is the module's conceptual core:

| | Saving $ra | Register spilling |
|---|---|---|
| Purpose | Preserve the return address | Free a register for reuse |
| Cause | A nested call would overwrite $ra | Too many live values |
| Where | Non-leaf procedures | Leaf and non-leaf procedures |

Same instructions, different reasons. Students who can explain the table can be trusted with the code.

**Milestone 2 — Worked example: spilling in a leaf procedure** (`spilling_example.asm` accompanies this module). Compute `f(a, b, c, d) = (a + b)(c + d) + (a + b)`. The trap is built into the formula: `x = a + b` is needed at the very end, but its register is wanted for `y = c + d` in between. The deck's five-step discipline: compute x, spill x, reuse the register for y, reload x, finish. With a = 2, b = 3, c = 4, d = 5: x = 5, y = 9, z = 45. Expected output: **50**.

**Milestone 3 — Worked example: spilling in a non-leaf procedure** (`nonleaf_spilling.asm`). The same function, restructured: the multiplication is delegated to a leaf helper `g(x, y) = x * y`, which makes `f` non-leaf. Now one 8-byte frame holds both saves at once, `$ra` at 4($sp) and spilled x at 0($sp), and x must survive not just register reuse but a procedure call that repurposes the argument registers. Expected output: **50**, reached by a harder road; comparing the two programs line by line is the exercise's real content.

**Milestone 4 — In-class tasks** (specifications, test values, and expected outputs given; solutions are not).

- *Task 1, eight arguments:* `calculate(a, …, h)` computes `p = (a + b)(c + d)` and `q = (e + f)(g + h)` and returns `p + q`, with test values a = 2 through h = 9 (from the course's test harness). More live values than the simple examples: students choose for themselves what spills. Expected output: **266** (p = 45, q = 221).
- *Task 2, non-leaf with spilling:* `calculate(a, b, c, d)` calls a leaf `multiply(x, y)` and returns `multiply(x, y) − x`, where `x = a + b` and `y = c + d`, with a = 3, b = 5, c = 4, d = 6. Requirements per the deck: spill x before computing y, save and restore `$ra`, reload x after the call. Expected output: **72** (x = 8, y = 10, z = 80, 80 − 8).

## Deliverables

Students submit:

- Source code for both in-class tasks, run in QtSpim
- For Task 1: an annotation of their own code marking each spill and reload, with the live value named

## Instructor notes

- Sequence matters in the example programs: the spill in Milestone 2 is *forced* by choosing one register for both x and y in a four-argument function that could, in truth, be register-comfortable. Name this honestly in class: the lab manufactures scarcity to teach the mechanism, and real scarcity arrives with larger functions and compiler allocation. Students respect the mechanism more when they know the setup.
- The classic bug is reloading from the wrong offset once `$ra` joins the frame (Milestone 3). It produces a program that returns a plausible wrong value instead of crashing, which is exactly why the module's two examples share inputs and outputs: a 50 that arrives by the wrong road can be caught by diffing the roads.
- This module completes the procedures pair begun by *Leaf and Non-Leaf Procedures and the Stack*. Together they cover the full procedure discipline the capstone's design note will later assume.
- Note for adopters: in Spring 2026 the spilling material was split across Lab 4 (with the global pointer) and Lab 5 (branching); the Fall sequence is the current organisation.

## Source files

`Lab_5_Register_Spilling.pptx`, the full slide deck used in class, and the two worked-example programs accompany this module in the repository.

---

*Part of the Systems Labs collection — laboratory modules for computer organization, architecture, and operating systems, maintained by Ebuka Philip Oguchi, Spelman College. Modules may be adopted and remixed with attribution.*
