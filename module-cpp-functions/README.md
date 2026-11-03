# Module: Many Small Jobs, One Menu — User-Defined Functions in C++

**Pathway stage:** 01 · Source code
**Course:** SCIS 123 C++ Programming — Lab 9 (Fall 2026)
**Format:** One lab session · **Level:** Introductory programming, after branching and loops; first user-defined functions

## Why this lab exists

Every program in this course so far has lived in one `main()`. That works until the program has to do the same job twice, or five jobs in rotation — and then `main()` becomes a scroll. This lab introduces the user-defined function as the way out: name a job, give it its own block, call it when needed. The vehicle is a menu-driven calculator, chosen because a menu is a program that is *nothing but* repeated, separable jobs: show the menu, do one operation, show the menu again. Each operation becomes a `void` function of its own, `main()` shrinks to a loop and a `switch`, and the structure of the code starts to look like the structure of the problem.

The lab is staged as live coding in three parts — prototypes and menu first, then `main()` and selection, then the arithmetic functions — so students watch a program being *designed*, not just transcribed. It also settles the vocabulary precisely: prototype, definition, call, argument, parameter, and the difference between a function that displays a result and one that returns it. That last distinction is load-bearing: the calculator's functions are `void` by decision, and the closing exercise reverses the decision, requiring value-returning functions for the same kind of job.

## Learning objectives

By the end of this lab, students can:

- Define and call a user-defined function, and explain why defining a function does not execute it.
- Write a function prototype, a definition, and a call, and state what each one tells the compiler or does at run time.
- Distinguish arguments from parameters, and explain why their names may differ while order and types may not.
- Explain the difference between a `void` function and a value-returning function, and why a `void` function's "result" cannot be assigned.
- Use `return;` to leave a `void` function early, and say why `return a / b;` would not compile in one.
- Combine functions with a `do-while` loop and a `switch` to build a menu-driven program that repeats until the user chooses to exit.
- Guard an operation against invalid input inside the function responsible for it (division by zero, checked in `divide()`).

## Staged milestones

**Milestone 1 — What a function is.** A user-defined function is a named collection of statements that performs one task, written once and called when needed. The deck's first example is a `displayMessage()` that prints a welcome. *The question to linger on: does defining it run it? No — a definition is inert until a call transfers control to it, and control returns to the caller when it finishes.*

**Milestone 2 — Prototype, definition, call.** `displayMessage.cpp` accompanies this module: the prototype `void displayMessage();` before `main()`, the call inside `main()`, and the definition after it, printing "Hello, students!". The prototype exists because the compiler must know the function before it meets the call; the arrangement — declare early, define after `main()` — is the layout every program in the rest of the lab uses.

**Milestone 3 — Arguments and parameters.** A `displaySum(int x, int y)` called as `displaySum(a, b)` with `a = 10`, `b = 20`: the arguments `a` and `b` supply the values, the parameters `x` and `y` receive them. Names need not match; order and compatible types must.

**Milestone 4 — `void` versus value-returning.** Two versions of an `add`: one `void`, printing the sum itself; one returning `int`, handing the sum back for the caller to store or print. Both are legitimate; they differ in who owns the result. The closing exercise in this lab is unanswerable without this distinction.

**Milestone 5 — The calculator, specified before it is coded.** The deck specifies first and codes second: a menu (Add, Subtract, Multiply, Divide, Exit), one `void` function per operation, a `do-while` to repeat the menu, a `switch` to process the choice, two integers requested only for choices 1–4, division by zero prevented, exit only on 5. Seven "Think Before You Code" questions settle the design — which jobs become functions, what each receives, `void` or return — before a line is written.

**Milestone 6 — Live coding, Parts 1–3, and the complete program.** `menuDrivenCalculator.cpp` accompanies this module: prototypes and the `showMenu()` definition; a `main()` that loops `showMenu()`, reads a choice, reads operands only for choices 1–4, and dispatches through the `switch`; then the four arithmetic functions, with `divide()` guarding `b == 0` by an early `return;` before it can divide. One session, reproduced from the shipped file:

```
===== CALCULATOR MENU =====
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
Enter choice: 1
Enter two numbers: 10 20
Result: 30
```

A second menu cycle with choice 4 and numbers 10 0 prints "Cannot divide by zero" — the deck's own second sample, also reproduced exactly. Division of 10 by 4 prints Result: 2.5, which is what the `static_cast<double>` in `divide()` is for.

**Milestone 7 — In-class exercise: the menu-driven grade calculator.** Students build the same shape with the opposite function decision: a menu offering average, highest, and lowest of three test scores, with `calculateAverage` returning a `double` and `findHighest` / `findLowest` returning `int`s, results displayed in `main()`. The deck gives the required prototypes and an example execution (scores 80, 90, 100 → Average Score: 90). The exercise is published here as a specification only, in this repository's usual way; no worked solution accompanies it.

**Milestone 8 — Extension: the calculator remembers.** The instructor's extended version of the calculator accompanies this module as a second program, `menuDrivenCalculatorWithFiles.cpp`. Each operation now computes its result into a variable and hands it to a `saveResult()` function, which appends one line (for example, `10 + 20 = 30`) to a file named `results.txt`; the menu gains a View Saved Results option, read back by a `viewResults()` function, and Exit moves to option 6. Three details carry the teaching. The file is opened in append mode (`ios::app`), so the history survives between runs instead of being overwritten. A refused division is never saved, because `divide()` returns before the save call is reached — placing the save inside each operation gives the guard jurisdiction over the file as well as the screen. And viewing before anything has been saved prints "No saved results found." rather than failing, because a missing file is an expected state, not an error. This is also where file handling, first met earlier in this pathway, returns inside a program the students built themselves.

The extension also ships in a second form, `menuDrivenCalculatorIfElse.cpp`, identical in behaviour in every respect — same menus, same prompts, same saved file — except that the menu selection is an `if` / `else if` chain instead of a `switch`. It exists for classes that meet selection through `if` first, and it makes a clean comparison object: one program, two selection mechanisms, nothing else changed, which is the Lab 5 comparison (ranges and complex conditions versus exact-value matching) with the variables held constant.

A third form, `menuDrivenCalculatorValueReturning.cpp`, reverses the deck calculator's central decision: the operations return their results (`int` for add, subtract, and multiply; `double` for divide) instead of displaying them, and `main()` owns both the printing and the division-by-zero check, which now stands in front of the call rather than inside the function. No file saving in this form; exit is option 5 again. It is the shape the Milestone 7 exercise requires — calculations returned, display in `main()` — so students can see the pattern working before they have to produce it, and the contrast with the `void` calculator is the Milestone 4 distinction running in a full program rather than a two-line example.

## Deliverables

Students submit:

- The completed menu-driven calculator, structured as specified: prototypes, `showMenu()`, one `void` function per operation, a `do-while` loop, and a `switch`.
- The menu-driven grade calculator from the in-class exercise, with value-returning functions for the three calculations.

## A note on the deck

The accompanying deck is the Lab 9 deck published whole, all 15 slides, as taught, including the complete calculator program it builds toward. The deck's requirements slide shows the input prompt as "Enter your choice:" while the code it builds prompts "Enter choice: " — a wording mismatch documented in the instructor notes; the code, and the shipped program, are authoritative. The exercise's menu-driven grade calculator appears in the deck as a specification with an example run, and is published here the same way. The Milestone 8 extension program is not in the deck: the instructor supplied it as the calculator's follow-on version, and it is published here with the module it extends.
