# Module: One Value, Four Bases — Number Systems in C++

**Pathway stage:** 01 · Source code
**Course:** SCIS 123 C++ Programming — Lab 4 (Fall 2026)
**Format:** One lab session · **Level:** Introductory programming, after variables, input/output, and arithmetic; first contact with `switch`

## Why this lab exists

Number systems are usually taught as paper exercises: convert this, convert that, hand it in. This lab makes the student build the converter instead. The program reads a value in any of the four bases a programmer actually meets — binary, octal, decimal, hexadecimal — and prints the same value in all four, which turns the equivalence table (255 = 11111111 = 377 = FF) from a fact to memorise into a thing the student's own code produces.

Building it smuggles in three durable tools. Input is read as a **string** first, because `FF` cannot be typed into an `int` — a small design decision with a real reason behind it, and the deck stops to ask about it explicitly. Conversion goes through `stoi` with an explicit base argument, so the base stops being notation and becomes a parameter. Display uses the stream manipulators `oct`, `dec`, and `hex` alongside `bitset`, which is most students' first encounter with the idea that output has state. The `switch` statement arrives here as a preview, one lab before branching is taught in full, because a four-way menu is the most natural first use for it.

## Learning objectives

By the end of this lab, students can:

- State the base and digit set of the binary, octal, decimal, and hexadecimal systems, and show that 255, 11111111, 377, and FF are one value in four notations.
- Convert a string to an integer in a chosen base with `stoi(input, nullptr, base)`, and explain what the third argument does.
- Explain why the input is read as a `string` rather than directly into an `int`.
- Explain what `stoi` does with input that contains invalid characters partway through: it converts the longest valid prefix and can report where it stopped.
- Display one integer in four bases using `bitset<8>` and the `oct`, `dec`, and `hex` manipulators, and explain why `dec` is needed to restore decimal output after `hex` has been used.
- Build a menu with `switch`, `case`, `break`, and `default`, and use `default` to reject an invalid choice.
- Compute an average without integer division using `static_cast<double>`, and format it with `fixed` and `setprecision`.

## Staged milestones

**Milestone 1 — The review table.** The lab opens with the four systems side by side (base, digits) and the anchor example: binary 11111111, octal 377, decimal 255, hexadecimal FF. One value, four alphabets. Everything after this slide is machinery for moving between the columns.

**Milestone 2 — Libraries, variables, and the string question (Steps 1–3).** The program needs `<iostream>`, `<string>`, and `<bitset>`. Three variables carry the whole design: `input` (a string), `choice` (an int), and `number` (the converted value). *The slide to linger on: the deck's own question — why store the input as a string rather than immediately as an int? A student who can answer that (FF is not a number an `int` can be typed into) understands the program before it is written.* The menu follows: four choices, read `choice`, then read the number as a string.

**Milestone 3 — The switch and `stoi` (Step 4).** Each case converts with a different base: `stoi(input, nullptr, 2)`, `8`, `10`, or `16`; `default` prints "Invalid choice." and ends the program. The deck then puts `stoi` under a microscope with a second, tiny program, `stoiPositionDemo.cpp`, which accompanies this module: converting `"123abc"` with the position argument yields the number 123 and reports that conversion stopped at position 3. This is the moment to establish that `stoi` reads a prefix, not a promise.

**Milestone 4 — Display and the complete program (Step 5).** `numberSystemsConverter.cpp` accompanies this module. One run:

```
Choose the number system of your input:
1. Binary
2. Octal
3. Decimal
4. Hexadecimal
Enter your choice: 4
Enter the number: FF

Binary:      11111111
Octal:       377
Decimal:     255
Hexadecimal: ff
```

The deck's second test also checks out exactly: choice 1 with input 1010 prints binary 00001010, octal 12, decimal 10, hexadecimal a. Both runs were reproduced from the shipped file before publication.

**Milestone 5 — In-class exercise: sum and average in a chosen base.** Students write a second program: read three integers, calculate and display the sum, calculate the average (with `static_cast<double>` and two decimal places), then ask how to display the sum — binary, octal, or hexadecimal — and use a `switch` for the display, with "Invalid choice" for anything else. The deck carries a worked solution, and it accompanies this module as `sumAverageDisplay.cpp`. For 10, 15, 20 with display choice 2, it prints:

```
Enter three integers: 10 15 20
Average: 15.00
Sum: 45

Choose how to display the sum:
1. Binary
2. Octal
3. Hexadecimal
Enter your choice: 2
Sum in Octal: 55
```

## Deliverables

Students submit:

- The converter program, handling all four input bases and rejecting an invalid menu choice.
- The three-integers exercise program, with the sum displayed in a base chosen at run time.

## A note on the deck

The accompanying deck is the Lab 4 deck published whole, all 15 slides, as taught. It includes the worked solution to the in-class exercise, as the course's Lab 6 deck in this repository also carries its worked implementation; instructors who want the exercise to run as assessment should lift the solution slides (the final three) out of their own copy. The deck's one internal inconsistency — the exercise's example output lists the sum before the average, while the solution program prints the average first — is documented in the instructor notes; the program is authoritative.
