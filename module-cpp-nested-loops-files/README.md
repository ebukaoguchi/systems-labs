# Module: Data That Survives the Program — Nested Loops and File Handling in C++

**Pathway stage:** 01 · Source code
**Course:** SCIS 123 C++ Programming — Lab 8 (Fall 2026)
**Format:** One lab session · **Level:** Introductory programming, second half of the course

## Why this lab exists

Until this lab, every program a student has written forgets everything when it exits: input comes from the keyboard, output dies on the screen. This lab breaks that wall. Students process grouped data with nested loops, write the results to a file with `ofstream`, then read the file back with `ifstream` and display it — a complete write → persist → read pipeline in a single session, built around one worked example and transferred twice to new problems.

## Learning objectives

By the end of this lab, students can:

- Explain the purpose of file input and output, and distinguish `ifstream` from `ofstream`.
- Open, write to, read from, and close text files — and check whether the open succeeded.
- Use nested loops to process multiple groups of data.
- Use accumulators and conditional statements to analyze data, including placing an accumulator reset correctly.
- Create programs that save results to files and retrieve them.

## Staged milestones

**Milestone 1 — Nested loops, counted honestly.** A 3 × 4 loop nest printing rows and columns. Before running anything, students answer: how many times does the inner loop execute in total? (12 — and being able to say *why* is the milestone.)

**Milestone 2 — Writing with `ofstream`.** Create `numbers.txt` holding 10, 20, 30. `open()` → `<<` → `close()`, and the warning that opening an existing file this way replaces its contents.

**Milestone 3 — Reading with `ifstream`.** The `while (infile >> number)` idiom — and why the loop needs no increment: the stream itself advances. Then the failure discipline: a file can fail to open (missing, wrong path, permissions), `ifstream` never creates a missing file, and every serious program checks.

**Milestone 4 — The worked example: Weekly Sales Report** (live-coded in three parts).

- *Part 1:* validated input (number of stores, number of days) and opening `sales_report.txt` with an open-check.
- *Part 2:* nested loops with an accumulator and classification — total each store's daily sales; $500 or more is "Good," otherwise "Needs Improvement"; write one line per store. The conceptual heart of the lab lives here, in one question: *why must `total = 0;` sit inside the outer loop?* (Move it out, and every store inherits the previous stores' sales.)
- *Part 3:* close the file, reopen it with `ifstream`, and display the report line by line with `getline` — chosen over `>>` because report lines contain spaces.

A complete reference implementation (`weeklySalesReport.cpp`) accompanies this module as the worked-example code.

**Milestone 5 — Transfer exercises** (specifications and expected file contents given; solutions are not).

- *Employee Work Hours Report:* employees × workdays, total hours per employee, more than 40 hours classified "Overtime," results written to `employee_report.txt`.
- *Electricity Consumption Report:* households × days of kWh usage, totals classified "High Usage" above 100 kWh, written to `electricity_report.txt` and read back for display.
- *Optional practice:* a Student Attendance Report (present/absent per meeting, "Perfect Attendance" detection), with a challenge to reject any attendance value other than 0 or 1.

## Deliverables

Students submit:

- Source code for both transfer exercises
- The generated report files (`employee_report.txt`, `electricity_report.txt`)

## Instructor notes

- Teach Milestone 4's accumulator question by demonstration: move `total = 0;` outside the outer loop, rerun with the deck's sample input (Store 1: 200 + 350; Store 2: 100 + 150), and let the wrong second line — $800 instead of $250 — make the argument.
- The `getline` vs. `>>` distinction lands best as a bug: read the report back with `>>` first and watch every line shatter into words.
- Expected file contents are given for the transfer exercises deliberately: students can verify their own output exactly, which is this course's first taste of testing against a specification.

## Source files

`Lab_8_Nested_Loops_Files.pptx` — the full slide deck used in class — and `weeklySalesReport.cpp`, the worked-example implementation, accompany this module in the repository.

---

*Part of the Systems Labs collection — laboratory modules for computer organization, architecture, and operating systems, maintained by Ebuka Philip Oguchi, Spelman College. Modules may be adopted and remixed with attribution.*
