# Module: Store the Grid — Arrays and Nested Loops in C++

**Pathway stage:** 01 · Source code
**Course:** SCIS 123 C++ Programming — Lab 10 (Fall 2026)
**Format:** One lab session · **Level:** Introductory programming, after nested loops and user-defined functions; first arrays

## Why this lab exists

Earlier in this course, nested loops printed grids: rows of numbers, generated on the fly and gone the moment they scrolled past. This lab asks the question that turns printing into programming: what if the numbers have to *stay*? The answer is the array, the first data structure in the course: a named block of elements of one type, each reachable by an index. The lab moves from a one-dimensional array (declare it, read an element, walk it with a loop) to the two-dimensional array that stores the grid the loops used to print, and then does real work on stored data: adding two matrices element by element, and searching a grid for duplicate values. A three-dimensional array closes the session, presented as what it is: the same idea with one more index, and one more loop to traverse it.

The duplicates exercise is the lab's centre of gravity. It is the first task in the course whose solution is an algorithm the student has to design rather than a pattern to transcribe: three nested loops, a comparison that must start *after* the current element, and an output convention (rows numbered from 1) that deliberately disagrees with the language's indexing (from 0). The deck designs it in the open, pseudocode first, before any code is written.

## The files in this module

| File | What it is |
|---|---|
| `README.md` | This module specification |
| `Lab_10_Arrays_and_Nested_Loops.pptx` / `.pdf` | The lab deck as taught (16 slides) |
| `arrayBasics.cpp` | One-dimensional arrays: declaration with an initializer list, access by index, traversal with a `for` loop |
| `print2DArray.cpp` | Printing a 2 × 3 array with nested loops, one row per line |
| `matrixAddition.cpp` | Adding two 2 × 3 matrices element by element into a third array |
| `print3DArray.cpp` | Printing a 2 × 2 × 3 array layer by layer with three nested loops |
| `INSTRUCTOR_NOTES.md` | Pacing, the two indexing conventions, the duplicates design discussion, and the publication boundary |

## Learning objectives

By the end of this lab, students can:

- Declare an array with an initializer list and state how many elements it holds.
- Access an element of a one-, two-, or three-dimensional array by its indices, and explain why indices begin at 0.
- Traverse arrays of one, two, and three dimensions with loops nested to the same depth as the array.
- Perform an element-by-element operation on two arrays of the same shape and store the result in a third.
- Design a duplicate search over a two-dimensional array that never compares an element with itself, and justify starting the inner comparison at `i + 1`.
- Convert between the index of an element (from 0) and its position as a person counts it (from 1) when displaying results.

## Staged milestones

**Milestone 1 — One dimension: declare, access, traverse.** `arrayBasics.cpp` accompanies this milestone: `int numbers[5] = {10, 20, 30, 40, 50};`, then `numbers[0]` and `numbers[2]` printed directly, then the whole array walked by a `for` loop. Its complete output:

```
10
30
10
20
30
40
50
```

The two direct accesses come first on purpose: an element is a variable with an address computed from its index, and the loop that follows is only that same access with the index moving.

**Milestone 2 — From printing a grid to storing one.** The nested-loops module earlier in this pathway generated a square grid of numbers and printed it. The deck recalls that grid and poses the storage question directly: printing answers *what does it look like*, an array answers *what is in it*, and only the second can be searched, summed, or changed afterwards. A two-dimensional array is introduced as rows and columns: `int numbers[2][3]` holds 2 rows of 3, six elements in all, and the element at row `r`, column `c` is `numbers[r][c]`. The deck's access examples, worth asking aloud: `numbers[0][0]` is 10, `numbers[0][2]` is 30, `numbers[1][1]` is 50, `numbers[1][2]` is 60, and `numbers[1][0]`, the deck's posed question, is 40.

**Milestone 3 — Printing a 2D array.** `print2DArray.cpp` accompanies this milestone: an outer loop over rows, an inner loop over columns, a newline at the end of each row. Its complete output:

```
10 20 30
40 50 60
```

The correspondence to state explicitly: the loop nest has the same shape as the data. Two dimensions, two loops; the outer loop owns the newline because the outer loop owns the row.

**Milestone 4 — Element-by-element work: matrix addition.** `matrixAddition.cpp` adds the deck's two 2 × 3 arrays position by position into a third array, `sum`, printing each element as it is computed. Its complete output:

```
11 22 33
44 55 66
```

This is the first program in the lab that *computes over* stored data rather than merely displaying it, and the shape discipline is the lesson: the operation only makes sense because all three arrays share the same dimensions and the same indices mean the same position in each.

**Milestone 5 — In-class exercise: find the duplicates.** Students write a program named `find_duplicate` that examines a two-dimensional array of integers and reports any row containing a duplicate value, printing the row number and the duplicated integer. For the deck's array,

```cpp
int num_list[2][4] = {
    {3, 10, 11, 3},
    {2, 5, 3, 2}
};
```

the expected output is:

```
Row 1 has duplicate 3
Row 2 has duplicate 2
```

Three design points are settled in the deck before coding. The search needs three nested loops: select a row, select an element, compare it with the elements *after* it in the same row. The comparison starts at `j = i + 1`, which both avoids comparing an element with itself and checks each pair once. And the displayed row numbers begin at 1, as people count rows, even though the indices begin at 0: the conversion is the student's to make, deliberately. The deck closes the design with a challenge it leaves open: a value occurring three or more times in a row will be reported more than once by this algorithm, and preventing that is a further design step. The exercise is published here as a specification only, in this repository's usual way; no worked solution accompanies it. Its stated requirements: the program must compile, must work for other arrays and not only the sample values, must use nested loops, and must not compare an element with itself.

**Milestone 6 — Three dimensions.** A third index adds layers: `int numbers[2][2][3]` is 2 layers of 2 rows of 3 columns, 12 elements in all, and an element is reached as `numbers[layer][row][column]`. The deck's access examples: `numbers[0][0][0]` is 1, `numbers[0][1][2]` is 6, `numbers[1][0][2]` is 9, `numbers[1][1][1]` is 11, and `numbers[1][1][2]`, the deck's posed question, is 12. `print3DArray.cpp` traverses it with three nested loops, printing a layer heading before each layer. Its complete output:

```
Layer 1
1 2 3
4 5 6

Layer 2
7 8 9
10 11 12
```

The review questions the deck ends on are the lab's checkpoint: how many loops does a 2D traversal take, and a 3D one; why indices begin at 0; why the duplicate search starts at `j = i + 1`; and what the difference is between printing a grid and storing one.

## Deliverables

Students submit:

- The completed `find_duplicate` program, demonstrated against the deck's sample array and one array of the student's own construction that contains a row with no duplicates.
- One paragraph answering: "A nested loop can print any grid an array can store. What can the stored grid do that the printed one cannot?"

## What is, and is not, in this package

The package contains the module specification, the instructor's lab deck, and four small programs, each the complete compilable form of code presented in the deck, compiled and run before publication so that every output shown above is reproduced exactly. The in-class exercise is published as a specification with expected output only; its solution is not published, so the exercise remains gradeable as evidence of process.

## Source material

Packaged from the Fall 2026 SCIS 123 Lab 10 session, accompanying Gaddis, *Starting Out with C++: From Control Structures through Objects*, chapter 7 (arrays and vectors). The deck is the instructor's own; no publisher slide content is included.

---

*Part of the Systems Labs collection: laboratory modules for computer organization, architecture, and operating systems, maintained by Ebuka Philip Oguchi, Spelman College. Modules may be adopted and remixed with attribution.*
