# Instructor Notes — Many Small Jobs, One Menu (SCIS 123, Lab 9)

**Audience:** instructors adopting or remixing this module. These notes are not part of the student handout.

## The deck, as published

The Lab 9 deck is published whole: 15 slides, no trims. Screening before publication found no publisher or textbook slide content and no examination material in it; it is the instructor's own lab deck, in the same pattern as the Lab 3, Lab 4, and Lab 6 decks already in this repository. The complete menu-driven calculator program is part of the deck as taught, and ships as `menuDrivenCalculator.cpp`. The in-class exercise (menu-driven grade calculator) appears in the deck as a specification with required prototypes and an example execution only — no solution is published, in this repository or in the deck.

## Three things to know before you teach it

**The prompt wording differs between the requirements slide and the code.** The requirements slide's menu mock ends with "Enter your choice:". The live-coding slides and the complete program prompt with "Enter choice: ". The shipped `menuDrivenCalculator.cpp` follows the code. Students transcribing from the requirements slide will produce the longer prompt; both are correct behaviour, but autograders and sample-output comparisons should be set to the code's wording.

**There are two different `displayMessage()` programs in the deck.** The review slide's version prints "Welcome to CIS 123!"; the prototypes slide's complete program prints "Hello, students!". They are separate examples making separate points (what a function is; then how prototype, call, and definition fit together). The shipped `displayMessage.cpp` follows the second, complete program. If a student asks why the message changed, that is the answer — but you may prefer to flag it before they do.

**`a` and `b` in `main()` are read only for choices 1–4, deliberately.** The `if (choice >= 1 && choice <= 4)` guard around the operand prompt means that on Exit or an invalid choice the variables are never read and never used — the `switch` cases that consume them are exactly the guarded ones. Students reliably ask why the program does not ask for numbers before showing the exit message; the deck itself poses the question. It is also the honest place to mention that the variables are uninitialised on the paths that skip the prompt, and safe only because those paths never touch them.

## Running the session

- Keep the "Think Before You Code" pass intact. The seven design questions (which jobs become functions, what each receives, `void` or return, which function shows the menu, how the loop repeats, where the zero guard lives) are where the lab's actual content sits; the three live-coding parts are the answers being typed.
- The `do-while` choice deserves its thirty seconds: the menu must display at least once before any choice exists, which is the whole argument for testing at the bottom.
- In `divide()`, students may propose checking `b` in `main()` instead. The deck's design — the guard inside the function that divides, with an early `return;` — is the modular answer, and it sets up the contrast with the exercise, where the calculations return values and `main()` owns the display.
- Expected calculator behaviour worth demonstrating live beyond the deck's samples: an invalid choice (7) prints "Invalid choice, try again" and the menu repeats; only 5 exits.

## Verification

Both accompanying programs were compiled with `g++ -std=c++17 -Wall -Wextra` without warnings and run before publication. The calculator was driven through a scripted session covering every path: add (10, 20 → Result: 30) and divide-by-zero (10, 0 → "Cannot divide by zero"), reproducing the deck's two sample runs exactly; divide (10, 4 → Result: 2.5); invalid choice (7 → "Invalid choice, try again", menu repeats); and exit (5 → "Exiting program..."). `displayMessage.cpp` prints "Hello, students!", as its deck example states. The exercise's example arithmetic was checked by hand: the average of 80, 90, 100 is 90, matching the deck.
