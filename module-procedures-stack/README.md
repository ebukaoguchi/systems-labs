# Module: Who Calls Whom — Leaf and Non-Leaf Procedures and the Stack

**Pathway stage:** 03 · ISA
**Course:** SCIS 216 Computer Organization and Design — Lab 4 (Fall 2026)
**Format:** One lab session · **Level:** Early assembly programming, first procedures

## Why this lab exists

This is the lab where functions stop being a C++ idea and become a machine discipline. A procedure that calls nothing is a *leaf*: it may return with a bare `jr $ra`. A procedure that calls another procedure is *non-leaf*, and it has a problem: `jal` writes the return address into the same `$ra` it needs for its own return. The stack is the answer, and this lab teaches the stack as the mechanism that makes nested calls survivable: allocate, save `$ra`, call, restore, deallocate, return. The anchor example is a C++ `divmod` function (quotient and remainder of 17 ÷ 5) that students watch turn from leaf to non-leaf the moment it calls a helper.

## Learning objectives

By the end of this lab, students can:

- Distinguish leaf from non-leaf procedures and state exactly what each must save.
- Explain why `jal` makes saving `$ra` necessary: there is one return-address register and every call overwrites it.
- Use `$sp` to allocate and deallocate a stack frame, and store and reload a word at offsets within it.
- Describe the stack as LIFO, growing toward lower addresses, in 4-byte steps for words.
- Trace a nested call (`main` → non-leaf → leaf) and predict where control returns at each `jr $ra`.
- Translate a C++ program with a leaf and a non-leaf function into equivalent MIPS.

## Staged milestones

**Milestone 1 — The C++ anchor.** A small program: `divmod(17, 5)` returns the quotient (3) and prints the remainder (2). In C++ the call machinery is invisible. The lab's question: what does the machine have to do to make that call work, and what breaks when `divmod` itself starts calling functions?

**Milestone 2 — The stack.** `$sp` points at the top of a LIFO stack that grows downward. The frame idiom is taught both ways: word by word (`addiu $sp, $sp, -4` per push) and as a single frame allocation (`addiu $sp, $sp, -16` for four words, then offsets 0, 4, 8, 12 within the frame), with the deck's worked addresses (from $sp = 1000 down through 996, 992, 988, 984).

**Milestone 3 — Leaf versus non-leaf.** The definitions, stated as rules students can apply mechanically: a leaf calls nothing and saves nothing; a non-leaf calls something and must save and restore `$ra`. The deck shows `divmod` in both forms side by side: three instructions as a leaf, and the same body wrapped in save/restore once it calls `print_newline`.

**Milestone 4 — Worked example: the sentinel test** (`nonleaf_divmod.asm` accompanies this module). `main` calls the non-leaf `divmod`, then prints **99**, a sentinel chosen so it can only appear if `divmod` returned to the right place. Students are invited to comment out the restore and watch 99 never print: the failure *is* the lesson, because a lost `$ra` means a lost way home. (The newline printed before the 99 comes from the helper, called from inside `divmod`.)

**Milestone 5 — Worked example: proof by messages** (`nonleaf_messages.asm`). The same pattern with strings instead of arithmetic: `calculate` (non-leaf) calls `helper` (leaf), and main prints "Successfully returned to main!" only if every return lands. Expected output:

```
Inside helper function
Successfully returned to main!
```

**Milestone 6 — In-class task** (specification and expected result given; the solution is not). Translate the deck's C++ program: `doubleValue(x)` is a leaf returning `x * 2`; `calculate(a, b)` is a non-leaf that computes `a + b` and returns `doubleValue` of the sum; `main` calls `calculate(8, 4)`. The MIPS version must use `$sp` correctly and implement both procedures with the right save discipline. Expected result: **24**.

## Deliverables

Students submit:

- Source code for the in-class task, run in QtSpim
- A one-paragraph explanation, in their own words, of what would go wrong if `calculate` did not save `$ra`

## Instructor notes

- The sentinel design (Milestone 4) is deliberate: a wrong return address in a numeric program can print a plausible wrong number and hide; a missing 99 cannot hide. Prefer sentinel outputs whenever a lab's real subject is control flow rather than arithmetic.
- Students reliably ask why the stack grows *down*. The honest short answer is convention plus history (the heap grows up from the other end); what matters for this course is fluency with negative offsets from the original $sp, which the frame-allocation form of Milestone 2 drills.
- This module is the first half of a procedures pair. Its companion, *Register Spilling*, picks up the question this lab deliberately does not ask: what happens when a procedure runs out of registers, not just return addresses.
- Note for adopters: in Spring 2026 this material ran combined with the global pointer; the Fall deck separates procedure discipline from $gp and is the current version.

## Source files

`Lab_4_Leaf_NonLeaf_and_the_Stack.pptx`, the full slide deck used in class, and the two worked-example programs accompany this module in the repository.

---

*Part of the Systems Labs collection — laboratory modules for computer organization, architecture, and operating systems, maintained by Ebuka Philip Oguchi, Spelman College. Modules may be adopted and remixed with attribution.*
