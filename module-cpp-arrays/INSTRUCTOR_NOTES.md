# Instructor Notes — Store the Grid (SCIS 123, Lab 10)

**Audience:** instructors adopting or remixing this module. These notes are not part of the student handout.

## The deck, as published

The Lab 10 deck is published whole, no trims: 16 slides, the instructor's own lab deck, in the same pattern as the Lab 3, Lab 4, Lab 6, and Lab 9 decks already in this repository. Screening before publication found no publisher or textbook slide content and no examination material in it. The course text's arrays chapter (Gaddis, chapter 7) was used only to check topic coverage; nothing from it is reproduced. The in-class exercise (find_duplicate) appears in the deck as a specification with expected output only: no solution is published, in this repository or in the deck.

## Three things to know before you teach it

**Two indexing conventions run at once, deliberately.** C++ indices begin at 0; the duplicates exercise requires rows to be *displayed* numbered from 1. The deck states the requirement outright ("use row numbers beginning at 1, even though C++ indices begin at 0"), and students will still submit programs that print "Row 0". Treat that as the lab's cheapest diagnostic: it separates students who read the specification from students who pattern-matched the loop.

**`j = i + 1` does two jobs, and students usually see only one.** Starting the comparison loop after the current element prevents comparing an element with itself (the reason the deck names) and also checks each pair exactly once, halving the comparisons. Ask for the second reason explicitly; the deck's review section returns to it.

**The triple-occurrence challenge is genuinely open.** With the deck's algorithm, a value appearing three times in a row is reported three times (once per equal pair). The deck poses preventing that as a challenge and does not answer it. Reasonable student answers include tracking values already reported for the row, or breaking out of the comparison loop after the first match for a given element; each has a different behaviour for a row holding two distinct duplicated values, which makes it a good discussion fork. No reference answer is published, by design.

## Deck-to-code notes

- The deck's matrix-addition slide presents the program's body without its `#include` and `main()` scaffolding visible in the slide's code box. `matrixAddition.cpp` is the complete compilable form of the same code, with the deck's array values and loop structure unchanged.
- All four shipped programs print each element followed by a space, exactly as the deck's code does, so captured output has a trailing space at each line end. The outputs quoted in the README are shown without the trailing spaces; the values and line breaks match the runs exactly.
- The deck's 3D slide introduces `int numbers[2][2][3]` and leaves its "Total elements" line to be completed in class: the answer is 12 (2 layers × 2 rows × 3 columns), and the README states it.

## Running the session

- Keep the Milestone 2 question ("printing a grid versus storing one") verbal and brief; it is the lab's thesis and the deliverable paragraph returns to it.
- The access questions the deck poses mid-slide (`numbers[1][0]`, then `numbers[1][1][2]`) work best cold, before the traversal code appears: they expose whether students are reading indices as coordinates or as a count.
- For the exercise, hold the line on designing before coding: the deck's Think Before You Code slide (how a row is selected, how elements within a row are reached, why self-comparison is excluded, what happens with more than one duplicate) is where most of the lab's learning sits. Students who start typing immediately reliably produce the two-loop version that compares across rows.

## Verification

All four programs were compiled with `g++ -std=c++17` and run before publication; every output quoted in the README was reproduced exactly (modulo the trailing spaces noted above). The find_duplicate exercise has no shipped program, by design; its expected output was verified by hand-tracing the deck's algorithm against the deck's sample array.
