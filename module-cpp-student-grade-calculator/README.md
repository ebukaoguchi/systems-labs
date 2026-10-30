# Module: Putting It All Together — The Student Grade Calculator

**Pathway stage:** 01 · Source code
**Course:** SCIS 123 C++ Programming — Lab 6 (Fall 2026)
**Format:** One lab session · **Level:** Introductory programming, review of Chapters 1–4

## Why this lab exists

Every lab before this one taught a single idea: input, arithmetic, a condition, a function. This lab is the first time students assemble all of them into one complete, organised program. The Student Grade Calculator is deliberately ordinary — names, scores, a weighted average, a letter grade — because the lesson is not the problem, it is the *decomposition*: a large program broken into small functions, each with one job, connected in `main()`. Students who finish this lab have the template every later program in the course will follow.

## Learning objectives

By the end of this lab, students can:

- Design a program as a set of functions before writing it: inputs, processing, and outputs identified first.
- Write functions with parameters and return values, and use prototypes when definitions follow `main()`.
- Read a name containing spaces with `getline`, and explain why `cin >>` is not enough.
- Choose `if / else if / else` for ranges of values and `switch` for matching individual values, and say why each fits.
- Format decimal output with `fixed` and `setprecision(2)`.
- Apply a weighted-average formula across categories.

## Staged milestones

**Milestone 1 — Decompose before coding.** The program's flow is drawn first: get information, get scores, calculate the exam average, calculate the final grade, determine the letter grade, display a message, display the report. Each step becomes a function; `main()` coordinates and does almost no work itself. *The slide to linger on: the function list (five prototypes) next to the flow diagram — they are the same picture in two notations.*

**Milestone 2 — Input, once, properly.** One function, `getScore()`, replaces four copies of prompt-and-read. The student's name is read with `getline` — with the demonstration that `cin >> name` stops at the first space and turns "Ebuka Oguchi" into "Ebuka".

**Milestone 3 — The calculations.** The exam average, including the `2.0` versus `2` question (with `double` operands either works here; `2.0` announces floating-point intent). Then the weighted final grade:

```
Final Grade = (Exam Average × 0.50) + (Homework × 0.25) + (Lab × 0.25)
```

**Milestone 4 — Two kinds of decision.** The letter grade uses `if / else if / else` because grades are *ranges* (90 and above, 80 to 90, …). The performance message uses `switch` because a letter grade is one of a few *specific values*. The comparison is the conceptual heart of the lab: ranges versus values is how a programmer chooses between the two statements for the rest of their career.

**Milestone 5 — The worked example: Student Grade Calculator.** The complete program (`studentGradeCalculator.cpp` accompanies this module), with this expected output for the deck's sample input (Jane Smith; Exam 1 = 85, Exam 2 = 92, Homework = 88, Lab = 95):

```
------ GRADE REPORT ------
Student: Jane Smith
Exam Average: 88.50
Homework: 88.00
Lab: 95.00
Final Grade: 90.00
Letter Grade: A
Excellent performance!
```

The final grade lands on exactly 90.00, on the A boundary, on purpose: it forces the class to check whether `>=` was used, and what would happen at 89.99.

**Milestone 6 — Transfer exercises** (specifications and example outputs given; solutions are not).

- *Shopping Discount Calculator* (in-class exercise): subtotal from price × quantity; discount rate by customer type (Regular 0%, Student 10%, Member 15%) chosen with `if / else if / else`; a `switch` message per type; at least three functions besides `main()`; money to two decimals. Deck example: Jane Smith, $50 × 3, Student: subtotal $150.00, discount $15.00, final total $135.00.
- *Practice: Car Rental Calculator:* base cost from days × daily rate; additional-fee rate by vehicle type (Economy 0%, SUV 10%, Luxury 20%); `switch` for the vehicle message. Deck example: 4 days at $50, SUV: base $200.00, fee $20.00, final cost $220.00.
- *Practice: Shipping Cost Calculator:* rate per mile by shipping type (Standard $0.50, Express $0.75, Overnight $1.00), plus a heavy-package fee, `switch` for the shipping message. Deck example: 25 lb, 100 miles, Express: shipping $75.00, heavy-package fee $10.00, final cost $85.00.
- *Challenge (from the deck): input validation.* The worked example's `getScore()` prints "Invalid score." for a value outside 0–100 but returns it anyway. Students improve it so an invalid score cannot silently flow into the grade, and apply the same thinking to the Shopping exercise's price and quantity.

## Deliverables

Students submit:

- Source code for the Shopping Discount Calculator
- Source code for one of the two practice calculators

## Instructor notes

- The name bug (Milestone 2) and the boundary grade (Milestone 5) are the session's two reliable discussions; both are cheaper to meet here, in a friendly program, than in graded work later.
- The `getScore()` validation gap is left in the worked example deliberately: it converts "validation" from a slogan into a one-function repair students can actually make, and it seeds the deck's own challenge slide.
- Note for adopters comparing files: an earlier classroom draft of this program circulates in the course folder with different prompts and messages. The version shipped here is the one that matches the deck and its expected output exactly.

## Source files

`Lab_6_Putting_It_All_Together.pptx` — the full slide deck used in class — and `studentGradeCalculator.cpp`, the worked-example implementation, accompany this module in the repository.

---

*Part of the Systems Labs collection — laboratory modules for computer organization, architecture, and operating systems, maintained by Ebuka Philip Oguchi, Spelman College. Modules may be adopted and remixed with attribution.*
