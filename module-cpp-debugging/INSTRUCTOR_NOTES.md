# Instructor Notes — Find the Bugs (SCIS 123, Lab 3)

**Audience:** instructors adopting or remixing this module. These notes are not part of the student handout.

## What was trimmed from the original deck, and why

The published deck is the course's Lab 3 deck (*Debugging and Exam Review*, 23 slides) reduced to the 14-slide debugging sequence:

- **Removed: the "Exam Connection & Expectation" slide** (original slide 9). It frames the lab as Exam 1 preparation for this specific course; that is internal framing, and this repository does not publish examination material.
- **Removed: slides 16–23** (`scanf` format specifiers, `scanf` vs. `printf`, the `cstdio` example, the headers table, and the `switch` introduction, example, and customer-order challenge). These are the next topic in the course, not debugging, and the `switch` sequence belongs with the selection-statements module when that part of the SCIS 123 sequence is published. The customer-order fix-it program travels with it.
- The title slide is unchanged, so the deck still carries its original "Debugging and Exam Review" title; the module README explains the trim. If the mismatch bothers you in your own classroom, the module text stands alone without the deck.

## A misprint to know about before you teach it

The deck's "Syntax errors" slide for the student-profile program contains a garbled correction: its middle line misprints the fix for `cin << age;` (the correction should read `cin >> age;`). The complete corrected program on the following slide is right, and `studentProfile.cpp` in this module follows it. If you teach from the deck, either flag the line when you reach it or let students catch it — catching it is, admittedly, on-theme for this lab.

## Running the session

- Milestones 1–3 (the exam-average program) take the first half of the session. Resist fixing errors as students spot them out of order; the classification pass before any correction is where the method is learned.
- The two logic errors (precedence, the stray semicolon after `if`) are the assessment-worthy content. A student who finds every missing semicolon but misses both logic errors has learned the lesser half of the lab.
- Milestone 6 works well as a timed individual exercise after the two group walkthroughs; its two formula errors are both logic errors, which lands the closing point without further lecturing.
- The faulty programs are intentionally **not** shipped as `.cpp` files: they do not compile, by design, and this repository's build check compiles every `.cpp` it contains. The listings in the README are the handout; students retype or copy them into their own files.

## Verification

All three corrected programs were compiled with `g++ -std=c++17 -Wall -Wextra` without warnings and run before publication: exam average (80, 90, 70) prints an average of 80 and "You passed!"; the profile program reproduces the sample profile in the README, including the `cin.ignore()` behaviour after the age is read; area/perimeter for 5 by 3 prints 15.00 and 16.00.
