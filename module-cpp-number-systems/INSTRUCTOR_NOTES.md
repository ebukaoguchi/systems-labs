# Instructor Notes — One Value, Four Bases (SCIS 123, Lab 4)

**Audience:** instructors adopting or remixing this module. These notes are not part of the student handout.

## The deck, as published

The Lab 4 deck is published whole: 15 slides, no trims. Screening before publication found no publisher or textbook slide content and no examination material in it; it is the instructor's own lab deck, in the same pattern as the Lab 3 and Lab 6 decks already in this repository. It does contain the worked solution to its own in-class exercise (the final three slides). That is how the lab was taught, and the module README says so openly; if you adopt the exercise as graded work, remove those slides from your copy.

## Two things to know before you teach it

**The exercise's example output and its solution print in different orders.** The task slide's Example Output lists "Sum: 45" before "Average: 15.00". The solution program prints the average first, because its `cout` statements run in that order, and its own closing recap follows the program. The shipped `sumAverageDisplay.cpp` follows the solution program, and a run confirms: Average line, then Sum line. If a student submits output in the task slide's order with otherwise correct values, their program is right and the slide is wrong.

**`bitset<8>` truncates, silently.** The binary display is fixed at 8 bits, so any value above 255 loses its high bits on the Binary line only, while the other three bases stay correct. Verified by running the shipped converter with decimal input 300: it prints Binary: 00101100 (the low 8 bits, which read as 44), Octal: 454, Decimal: 300, Hexadecimal: 12c. Either constrain in-class inputs to 0–255, or use exactly this as a discussion prompt — it is the cleanest first encounter with fixed-width representation in the course, and it points straight at the computer-organization treatment of the same idea. Widening to `bitset<16>` is the one-line fix if you prefer correctness over the discussion.

## A behaviour worth one minute of class time

`stoi` converts the longest valid prefix and stops at the first character it cannot use — the shipped `stoiPositionDemo.cpp` shows it stopping at position 3 in "123abc". The consequence students should predict before anyone runs it: choosing Binary and typing 102 does not error; it converts "10" and reports 2. Input with no valid digits at all (choosing Decimal and typing "abc") makes `stoi` throw, and the uncaught exception ends the program abruptly. Handling that is beyond this lab's scope, but naming it now prevents a confused lab session later.

## Running the session

- Milestones 1–3 (the review table, the string question, the switch and `stoi`) are the teaching; Milestones 4–5 are assembly and practice. Do not rush the Step 2 question about why the input is a string — it is the lab's central design idea.
- The `switch` here is deliberately a preview: the deck itself flags it as "part of chapter 4 but partially introducing it to you". The full branching treatment (if / else if chains, switch as an alternative, fall-through) is Lab 5's material; students who ask why not just use `if` are asking next week's question, and the honest answer is that for menus the class will compare the two directly then.
- The exercise's average is the second teaching point: `static_cast<double>(sum) / 3` exists because `sum / 3` would truncate. A student whose average for 10, 15, 20 comes out as 15.00 by luck should be asked for 10, 15, 21 — the cast only shows its value when the division is not exact (46 / 3: 15 with integer division, 15.33 with the cast).

## Verification

All three accompanying programs were compiled with `g++ -std=c++17 -Wall -Wextra` without warnings and run before publication. The converter reproduces both of the deck's tests exactly (binary 1010 → 00001010 / 12 / 10 / a; hexadecimal FF → 11111111 / 377 / 255 / ff) and its invalid-choice path; the exercise solution reproduces the deck's recap (10, 15, 20 → Average: 15.00, Sum: 45, Sum in Octal: 55; display choice 1 gives Sum in Binary: 00101101); the `stoi` demo prints Number: 123 and Stopped at position: 3. The `bitset<8>` truncation described above was likewise verified by run (decimal 300), not inferred.
