# Module: Find the Bugs — Debugging and Reading Code in C++

**Pathway stage:** 01 · Source code
**Course:** SCIS 123 C++ Programming — Lab 3 (Fall 2026)
**Format:** One lab session · **Level:** Introductory programming, after basic input/output, variables, arithmetic, and selection

## Why this lab exists

Students meet debugging as an accident in most courses: something breaks, and they fix it by staring. This lab teaches it as a discipline instead. Three short programs are presented broken, on purpose, and the class works them in a fixed order: find every error, classify it, correct it, and state what the program should print. The distinction the lab is really about is the one beginners blur: **syntax errors**, which the compiler catches, versus **logic errors**, which the compiler passes in silence and only the output exposes. Two of the errors in this lab are logic errors, and both live in the first program.

The faulty programs are printed below as listings, deliberately not as compilable files: copying one into an editor and making it run is the exercise. The corrected programs accompany this module as `.cpp` files and are the demonstrations worked through live in class; the slide deck (the Lab 3 deck, trimmed to this debugging sequence) carries the same material in presentation form.

## Learning objectives

By the end of this lab, students can:

- Read a short program they did not write and locate errors in it systematically, rather than by running it and hoping.
- Distinguish syntax errors from logic errors, and give an example of each from the lab's programs.
- Use the stream operators in the right direction: `<<` for output with `cout`, `>>` for input with `cin`.
- Explain why `main()` returns `int`, and why a missing semicolon is a syntax error wherever it occurs.
- Explain operator precedence in `exam1 + exam2 + exam3 / 3` and correct it with parentheses and `3.0`.
- Explain why a semicolon directly after `if (condition);` ends the statement and detaches the block that follows.
- Choose `string` over `char` for text of more than one character, and `getline` over `>>` for input containing spaces.

## Staged milestones

**Milestone 1 — The syntax hunt (faulty program 1).** The class receives this program, which reads a name and three exam scores and reports an average and a verdict:

```cpp
#include <iostream>
#include <string>
using namespace std

double main()
{
    string name;
    int exam1, exam2, exam3;
    double average;

    cout >> "Enter your name: ";
    getline(cin, name);

    cout << "Enter Exam 1 score: ";
    cin << exam1;

    cout << "Enter Exam 2 score: ";
    cin >> exam2

    cout << "Enter Exam 3 score: ";
    cin >> exam3;

    average = exam1 + exam2 + exam3 / 3;

    cout << "Student: " >> name << endl;
    cout << "Average: " << average << endl;

    if (average >= 70);
    {
        cout << "You passed!" << endl;
    }
    else
    {
        cout << "You did not pass." << endl;
    }

    return 0;
}
```

Working from a checklist (semicolons present? `main()` declared correctly? stream operators pointing the right way? braces balanced?), students identify each error and classify it before anyone touches a keyboard. *The slide to linger on: the checklist itself — it is the debugging method, and it transfers to every program after this one.*

**Milestone 2 — The two errors the compiler will not catch.** With the syntax fixed, the program compiles and still lies twice. `average = exam1 + exam2 + exam3 / 3;` divides only the third score, by precedence. `if (average >= 70);` ends the `if` at the semicolon, so the pass message and the `else` no longer belong to the condition. Both corrections are one character deep and invisible to the compiler; the class establishes the habit that *compiles* and *correct* are different claims.

**Milestone 3 — Worked example 1: the corrected program.** `examAverage.cpp` accompanies this module. For the name Ada Lovelace and scores 80, 90, 70, it prints:

```
Student: Ada Lovelace
Average: 80
You passed!
```

**Milestone 4 — Types and input (faulty program 2).** A student-profile program: name, major, classification, age, favourite programming language. Its errors are of a second kind: `char favoriteLanguage;` for a multi-character answer, `cin <<` in place of `cin >>`, a missing semicolon after `int age`, and input read with `>>` where the answer contains spaces:

```cpp
#include <iostream>
#include <string>
using namespace std

int main()
{
    string name;
    string major;
    string classification;
    int age
    char favoriteLanguage;

    cout << "Enter your full name: ";
    getline(cin, name);

    cout << "Enter your major: ";
    getline(cin, major);

    cout << "Enter your classification: ";
    cin << classification;

    cout << "Enter your age: ";
    cin << age;

    cout << "Enter your favorite programming language: ";
    cin >> favoriteLanguage;

    cout << endl;
    cout << "----- Student Profile -----" << endl;
    cout << "Name: " >> name << endl;
    cout << "Major: " << major << endl;
    cout << "Classification: " << classification << endl;
    cout << "Age: " << age << endl;
    cout << "Favorite Programming Language: " << favoriteLanguage << endl;

    return 0
}
```

**Milestone 5 — Worked example 2.** `studentProfile.cpp` accompanies this module. The corrections force two genuine design points: the language field becomes a `string` read with `getline`, and after `cin >> age;` a `cin.ignore();` is needed before the next `getline`, or the leftover newline answers it. For Jane Smith, Computer Science, Junior, 20, C++:

```
----- Student Profile -----
Name: Jane Smith
Major: Computer Science
Classification: Junior
Age: 20
Favorite Programming Language: C++
```

**Milestone 6 — Guided practice: area and perimeter.** A third faulty program, worked against the clock. It computes `area = length + width;` and `perimeter = 2 * length + width;` — both wrong, both compiling — alongside the now-familiar syntax errors (`cin << length;`, two missing semicolons, a reversed `cout >>`). The corrected program, `areaPerimeter.cpp`, accompanies this module; for length 5 and width 3 it prints:

```
Area: 15.00
Perimeter: 16.00
```

The two formula errors close the lab's argument: the most expensive bugs in the session were never syntax at all.

## Deliverables

Students submit:

- A corrected version of faulty program 1, with a written list of every error found, its classification (syntax or logic), and the output the corrected program produces for scores of their choosing.
- The same for one of faulty programs 2 or 3, assigned in class.

## A note on the deck

The accompanying deck is the Lab 3 (*Debugging and Exam Review*) deck with two removals: the exam-expectations slide, which is course-internal framing, and the closing sequence on `scanf`/`printf`, headers, and the `switch` statement, which belongs to the later selection-statements material in this course and will travel with that module when it is published. What remains is the debugging sequence exactly as taught.
