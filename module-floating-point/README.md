# Module: Numbers with Points — Floating Point Representation and Arithmetic

**Pathway stage:** 03 · ISA (how the machine represents real numbers)
**Course:** SCIS 216 Computer Organization and Design — companion to *Inside the ALU*
**Source material:** CIS 216 Lecture 003, floating-point section (taught Fall 2026); this module is the packaged follow-on to that lecture material
**Format:** One to two lab sessions · **Level:** After integer arithmetic and the ALU module

## Why this module exists

The ALU module covered how the machine adds, multiplies, and divides integers. This module answers the question students ask next: where does the point go? Floating point is a representation before it is an arithmetic: a fixed 32-bit budget divided among a sign, an exponent, and a fraction, buying enormous range at the price of exactness. Students convert in both directions by hand, perform one addition the hardware's way, and then meet coprocessor 1: the separate floating point register file where MIPS keeps these values, with its own loads, arithmetic, and comparisons. The module ends by collapsing the two halves: a program prints the raw bit pattern of 7.5, and the word on the screen is the same word the students derived on paper.

## Learning objectives

By the end of this module, students can:

- Lay out an IEEE 754 single-precision word: sign, biased exponent (bias 127), and fraction with its hidden leading 1.
- Convert decimal values to bit patterns and bit patterns back to decimal values.
- Explain why values like 0.1 have no exact binary floating point representation, and what rounding does about it.
- Execute the floating point addition algorithm: align exponents, add mantissas, normalize.
- Write QtSpim programs using `.float` data, `lwc1`/`swc1`, and the `.s` arithmetic instructions (`add.s`, `sub.s`, `mul.s`, `div.s`).
- Compare floating point values with `c.eq.s` / `c.lt.s` / `c.le.s` and branch on the result with `bc1t` / `bc1f`.
- Move a value between the coprocessor and integer registers (`mfc1`) and read its raw representation.

## Staged milestones

**Milestone 1 — The format.** One word, three fields (`diagrams/ieee754-single.svg`): bit 31 sign, bits 30–23 exponent, bits 22–0 fraction, and the value formula (−1)^S × 1.fraction × 2^(exponent − 127). The two ideas to secure before any arithmetic: the exponent is stored biased, and the leading 1 of the fraction is *implied*, which is why 23 stored bits carry 24 bits of precision.

**Milestone 2 — Conversions, both directions** (worksheets Parts A and B). Decimal to bits for 5.75, −12.25, 0.1, and 100.5; bits to decimal for four given words. The companion C tool `float_bits.c` prints any value's fields and serves as the checking oracle, after students commit to their own answers. Part A3 is the milestone's payload: 0.1's fraction never terminates, the pattern repeats, and the stored value is 0.10000000149…, a first honest encounter with floating point error.

**Milestone 3 — Addition the hardware's way** (worksheet Part C). 7.5 + 2.25 in five steps: express, align, add, normalize, encode (result 9.75, word 0x411C0000). The alignment step is where the module's earlier integer material pays off: aligning exponents *is* the shift operation, now applied to mantissas.

**Milestone 4 — The worked example: arithmetic in coprocessor 1** (`floating_point.asm` accompanies this module). With a = 7.5 and b = 2.5, the program prints the sum (10.0), difference (5.0), product (18.75), and quotient (3.0), loading with `lwc1`, computing with the `.s` instructions, and printing with syscall 2. Worksheet Part D has students predict every line before the run.

**Milestone 5 — Comparisons and the bridge back to bits.** Floating point comparison does not reuse `slt`: `c.lt.s` sets a flag in the coprocessor, and `bc1t` branches on it, which the program uses to print "a is greater than b". Then the closing move: `mfc1` copies 7.5's bits into an integer register and syscall 34 prints them in hexadecimal: **40f00000**, the exact word from Milestone 2's worksheet. Representation and code are the same object, seen from two sides.

**Milestone 6 — Transfer exercise.** Students modify the program to a = 12.5, b = 0.5 (worksheet Part E), predicting all six output lines, including 12.5's bit pattern (41480000), before running.

## Deliverables

Students submit:

- The completed worksheets (Parts A–E), with Part D and Part E predictions written before the corresponding runs
- Their modified program from Part E, run in QtSpim

## Source files

`floating_point.asm` (the worked example), `float_bits.c` (the conversion oracle, in C), `traces.md` (the worksheets), `diagrams/ieee754-single.svg` (the format diagram), and `INSTRUCTOR_NOTES.md` accompany this module. Unlike the deck-based modules in this collection, this module is packaged from lecture material and has no slide deck; the instructor notes explain why, and what was left out.

---

*Part of the Systems Labs collection — laboratory modules for computer organization, architecture, and operating systems, maintained by Ebuka Philip Oguchi, Spelman College. Modules may be adopted and remixed with attribution.*
