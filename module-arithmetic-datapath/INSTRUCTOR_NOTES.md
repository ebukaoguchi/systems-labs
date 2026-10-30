# Instructor Notes: Inside the ALU

**Module:** Inside the ALU: Adders, Multipliers, and Dividers  
**Companion file:** `traces.md` (the student worksheet)

## Where this module sits

This module is the bridge between two existing Systems Labs modules. *Logic Gates on a Breadboard* ends with individual gates; the MIPS modules begin with instructions such as `add`, `mult`, and `div` treated as given. This module opens the box between them: gates become an adder, the adder becomes the ALU's engine, and repeated add/shift and subtract/shift loops become multiplication and division.

Run it after the QtSpim Intro module (students need `andi`, `add`, `sll`, `srl`, and the register conventions) and after or alongside the breadboard lab (students need AND, OR, NOT, and the idea of a truth table).

## Suggested pacing

Two 75-minute sessions, or one 2–3 hour lab:

| Segment | Time | Parts |
|---------|------|-------|
| Numbers and overflow | 20 min | Part 0 |
| Adders and partitioning | 20 min | Part 1 |
| Basic multiplier, trace and code | 40 min | Parts 2 and 6a |
| Optimized multiplier and trade-offs | 30 min | Parts 3 and 4 |
| Division, trace and HI/LO | 40 min | Parts 5 and 6b |
| Synthesis writing | homework | traces.md checkpoint |

The floating-point material from the same lecture sequence (IEEE 754 representation and arithmetic) is deliberately **not** in this module. It is a representation topic, not a datapath-construction topic, and it makes a cleaner follow-on module than a final hour here.

## Checkpoints that catch the common failures

- **Part 0:** the reliable misconception is that overflow is a property of the bit pattern. It is not: it is a property of the pattern *plus the interpretation*. Row 3 (unsigned 200 + 100) exists to break the "overflow means negative" idea; ask for the carry out explicitly.
- **Part 2:** students shift the product, or test the multiplicand's bit. Insist they say the loop aloud in register names before tracing: the *multiplier* decides, the *multiplicand* moves, the *product* accumulates.
- **Part 3:** students want to say the optimized multiplier is "faster". It is not: it runs the same number of cycles with less hardware. Part 3, question 3 is the assessment of the whole module in miniature: make them name the saved hardware (the separate multiplier register and its shifter).
- **Part 5:** the restore step is where traces collapse. Have students write the trial subtraction result *before* deciding keep-or-restore, in a scratch column, rather than erasing. Erasing the failed subtraction is exactly the habit that makes their traces unreadable.
- **Part 6b:** students expect `div` to name a destination register. The HI/LO surprise is the teaching moment: ask where the answer "lives" before revealing `mflo`/`mfhi`.

## The adder activity: simulation, not solder

Part 1 asks students to reason about a full adder, whose sum bit is A ⊕ B ⊕ carry-in. The breadboard lab's parts set (7404, 7408, 7432) contains no XOR gate, so a physical full-adder build is **not** possible from the existing bench kit. Options, in order of preference:

1. Keep Part 1 as diagram labelling plus a simulator build (any free logic simulator) — this is how the module ships.
2. If a physical build is wanted, add one 7486 (quad XOR) per bench to the parts list; a half adder needs one XOR and one AND, a full adder two XORs, two ANDs, and one OR, all available once the 7486 is added.

Do not promise the physical build in the student worksheet until the parts are actually in the room.

## Assessment notes

- The synthesis question at the end of `traces.md` ("what differs between an adder, a multiplier, and a divider?") is the highest-value item. Strong answers name control and sequencing: the adder is one pass of combinational logic; the multiplier and divider are loops around an adder/subtractor, differing in shift direction, test bit, and what gets written back.
- Expected final outputs in `traces.md` are deliberately final-only. The cycle-by-cycle tables for the worksheet's values (9 × 6, 10 × 5, 13 ÷ 3) are not published anywhere in this package, so the traces can be graded as evidence of process.
- The worked examples (6 × 3 in both multiplier designs, 17 ÷ 5 in MIPS) are the demonstrations from the lecture sequence and are safe to publish in full. The completed solutions to the *lecture's own in-class tasks* (the 7 × 5 multiplication task and the optimized-division task in the Fall 2026 Lecture 003 deck) are **not** in this package and should stay out of it: they are the answer keys to activities an instructor may still run live.

## Provenance and publication boundary

This module was packaged from the Fall 2026 CIS/SCIS 216 lecture sequence (Week 1 number representation, Lecture 002 on MIPS instructions, Lecture 003 on computer arithmetic). The lecture decks themselves are not part of the package: they contain textbook chapter material and diagrams alongside the instructor's activities, plus the in-class solutions named above. Every diagram in `diagrams/` was drawn for this module. If the module is adopted elsewhere, keep that boundary: publish activities, specifications, worked demonstrations, and expected final outputs, not lecture decks or answer tables.
