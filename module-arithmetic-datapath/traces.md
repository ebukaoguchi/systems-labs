# Student Worksheets: Traces and Design Activities

**Module:** Inside the ALU: Adders, Multipliers, and Dividers  
**Course:** SCIS 216 Computer Organization and Design

Work in pencil, in a notebook, or in a copy of this file. The point of a trace is to show the state of the hardware after every step, not only the final answer. Expected final outputs for self-checking are collected at the end: finish each trace before you look.

**Before you start:** install QtSpim using the shared guide, [Installing QtSpim for MIPS32](../setup/qtspim-installation.md). All multiplication and division values in this worksheet are non-negative.

---

## Part 0: Numbers the hardware can hold

All values in this part are stored in **8 bits**.

For each row, work out the 8-bit result the hardware keeps, what that pattern means as a signed value and as an unsigned value, and whether overflow occurred under the stated interpretation.

| # | Operation | Interpretation | 8-bit pattern kept | Value of the pattern | Overflow? Why? |
|---|-----------|---------------|--------------------|----------------------|----------------|
| 1 | 57 + 42 | signed | | | |
| 2 | 96 + 45 | signed | | | |
| 3 | 200 + 100 | unsigned | | | |
| 4 | −64 − 70 | signed | | | |

Questions:

1. In row 2, what does MIPS `add` do about the result, and what does `addu` do differently?
2. In row 3, nothing is "negative", so what tells you something was lost?
3. In one sentence: why can the same 8-bit pattern be a correct answer in one program and a bug in another?

---

## Part 1: From logic gates to an adder

Use the module diagram `diagrams/adder.svg`.

1. Label the two input bits, the sum output, the carry-in, and the carry-out of one full-adder block.
2. In a 4-bit adder built from four full adders, where does the carry-out of bit 0 go? Where does the carry-out of bit 3 go, and what can it tell you?
3. A **partitioned** adder splits one wide adder into independent lanes, for example four 16-bit lanes inside a 64-bit unit, with the carries between lanes blocked. Give:
   - one kind of workload this helps, and why;
   - one thing that becomes harder or is given up.
4. The breadboard lab used AND, OR, and NOT gates. A full adder also needs XOR (sum is A ⊕ B ⊕ carry-in). In one sentence, explain why AND and OR alone feel awkward for the sum bit. *(Simulation only: this module does not require a physical full-adder build.)*

---

## Part 2: Basic multiplier: shift and add

The hardware loop is:

1. Look at the least significant bit (LSB) of the **multiplier**.
2. If it is 1, add the **multiplicand** to the **product**.
3. Shift the multiplicand one bit left; shift the multiplier one bit right.
4. Repeat until the multiplier is 0.

### Worked example: 6 × 3 (completed for you)

All values are shown in 8 bits.

| Step | Multiplicand | Multiplier | LSB | Action | Product |
|------|--------------|------------|-----|--------|---------|
| Start | 00000110 | 00000011 | – | – | 00000000 |
| 1 | 00000110 | 00000011 | 1 | Add multiplicand | 00000110 |
| after shift | 00001100 | 00000001 | – | – | 00000110 |
| 2 | 00001100 | 00000001 | 1 | Add multiplicand | 00010010 |
| after shift | 00011000 | 00000000 | – | Stop: multiplier is 0 | 00010010 |

Final product: `00010010` = **18**. The algorithm performed **2 additions**.

### Your trace: 9 × 6

Multiplicand = `00001001`, multiplier = `00000110`, product starts at `00000000`.

| Step | Multiplicand | Multiplier | LSB | Action | Product |
|------|--------------|------------|-----|--------|---------|
| Start | 00001001 | 00000110 | – | – | 00000000 |
| 1 | | | | | |
| after shift | | | | | |
| 2 | | | | | |
| after shift | | | | | |
| 3 | | | | | |
| after shift | | | | | |
| 4 | | | | | |
| after shift | | | | | |

Questions:

1. Final product in binary and decimal: _______________
2. How many additions did the algorithm perform? _______________
3. Which bits of the multiplier decided that number, and why?

---

## Part 3: Optimized multiplier

The optimized design removes the separate multiplier register. The multiplier starts in the **lower half** of one combined product register; the upper half starts at 0. Each cycle:

1. Look at the LSB of the whole product register.
2. If it is 1, add the multiplicand to the **upper half only**.
3. Shift the whole product register one bit right.
4. Repeat once for each bit of the multiplier (4 cycles in this worksheet's small version).

Use the module diagram `diagrams/multiplier-optimized.svg`.

### Your trace: 10 × 5 (4-bit operands, 8-bit product register)

Multiplicand = `1010`. The product register starts as `0000 0101` (upper half `0000`, lower half = multiplier `0101`).

| Cycle | LSB | Add to upper half? | Product register after add (before shift) | Product register after shift |
|-------|-----|--------------------|-------------------------------------------|------------------------------|
| Start | – | – | – | 0000 0101 |
| 1 | | | | |
| 2 | | | | |
| 3 | | | | |
| 4 | | | | |

Questions:

1. Final product in binary and decimal: _______________
2. How many additions were performed? _______________
3. The basic multiplier and this design both take about one cycle per multiplier bit. What exactly did the optimized design save? Name the hardware, not just "it is more efficient".

---

## Part 4: Faster designs and trade-offs

Complete the comparison from what you have traced, then answer the scenarios.

| Design | Registers / hardware | Cycles for an n-bit multiply | Main advantage | Main cost |
|--------|---------------------|------------------------------|---------------|-----------|
| Basic multiplier | | about n | | |
| Optimized multiplier | | about n | | |
| Faster multiplier (many adders) | | few | | |

Scenarios: write a short paragraph for each.

1. **A sensor node** runs on a coin cell, multiplies occasionally, and chip area is tiny. Which design, and why?
2. **A phone processor** multiplies constantly in media and AI workloads, and users notice slowness. Which design, and why?
3. Your two answers probably differ. State the general rule they illustrate about hardware design.

---

## Part 5: Division hardware

Vocabulary first: in 13 ÷ 3, the **dividend** is 13, the **divisor** is 3, the **quotient** is 4, and the **remainder** is 1.

The optimized divider keeps the partial remainder and the growing quotient in one combined register. The divisor stays fixed. Each iteration:

1. Shift the combined register one bit left.
2. Subtract the divisor from the **upper half**.
3. If the result is negative, restore the upper half and write quotient bit **0** in the bit freed by the shift. If the result is zero or positive, keep it and write quotient bit **1**.
4. Repeat once for each quotient bit (4 iterations here).

Use the module diagram `diagrams/divider-optimized.svg`.

### Your trace: 13 ÷ 3 (4-bit values, 8-bit combined register)

Divisor = `0011`. The combined register starts as `0000 1101` (upper half = partial remainder `0000`, lower half = dividend `1101`).

| Iteration | Register after shift left | Upper half − divisor | Negative? | Restore? | Quotient bit written | Register at end of iteration |
|-----------|---------------------------|----------------------|-----------|----------|----------------------|------------------------------|
| Start | – | – | – | – | – | 0000 1101 |
| 1 | | | | | | |
| 2 | | | | | | |
| 3 | | | | | | |
| 4 | | | | | | |

Questions:

1. Final quotient (lower half) in binary and decimal: _______________
2. Final remainder (upper half) in binary and decimal: _______________
3. Check your answer the ordinary way: divisor × quotient + remainder should equal the dividend. Does it?
4. Why can division not be sped up with parallel adders as easily as multiplication? (Hint: what does each step of division depend on?)

---

## Part 6: The MIPS connection

You will run two programs in QtSpim.

### 6a. Shift-and-add in MIPS: `multiplier.asm`

1. Load and run `multiplier.asm`. It computes 6 × 3 by the Part 2 algorithm. Confirm the printed result.
2. Find the four instructions that implement the hardware loop and match each to its step:
   - test the multiplier's LSB → _______________
   - add the multiplicand → _______________
   - shift the multiplicand left → _______________
   - shift the multiplier right → _______________
3. Change the stored multiplicand to 9 and the multiplier to 6, reinitialize, and run again. Result: _______________ (Compare with your Part 2 trace.)
4. The program stops when the multiplier becomes 0. What would go wrong with this simple version if the multiplier were negative? (Think about what `srl` does to a negative two's-complement value.)

### 6b. Built-in division and HI/LO: `division.asm`

1. Load and run `division.asm`. It divides 17 by 5. Note the printed quotient and remainder.
2. MIPS `div` does not put its answer in an ordinary register. Where does the quotient go, and where does the remainder go? Which instructions copy them out?
3. Change the dividend to 43 and the divisor to 7, reinitialize, and run. Quotient: ______ Remainder: ______
4. Now change the divisor to 0 and run again. What happens, and which instruction in the program is responsible for that behaviour? Why must software do this check itself?

---

## Synthesis checkpoint

Submit all of the following:

1. Your completed traces from Parts 2, 3, and 5.
2. Your completed design comparison and the two scenario paragraphs from Part 4.
3. From Part 6: the four matched instructions (6a.2), and a screenshot or copied console output for one modified run of each program.
4. One paragraph, in your own words, answering: **"An adder, a multiplier, and a divider are all built from the same few operations. What differs between them?"**

---

## Expected final outputs (check only after tracing)

**Part 0**

1. Pattern `01100011` = 99 signed and unsigned. No overflow.
2. Pattern `10001101` = −115 as a signed value (141 as an unsigned pattern). **Signed overflow**: two positives produced a negative-looking result. `add` traps; `addu` keeps the wrapped pattern.
3. Pattern `00101100` = 44. The true sum is 300, which needs 9 bits; the carry out of the top bit is the evidence that value was lost.
4. Pattern `01111010` = +122 as a signed value. **Signed overflow**: the true result, −134, is outside the 8-bit signed range.

**Part 2** — 9 × 6: final product `00110110` = **54**; **2 additions** (the multiplier, 0110, has two 1 bits).

**Part 3** — 10 × 5: final product register `0011 0010` = **50**; **2 additions**. The saving is the separate multiplier register and its shifting hardware: the multiplier rides inside the product register and is consumed bit by bit.

**Part 5** — 13 ÷ 3: quotient `0100` = **4**, remainder `0001` = **1**. Check: 3 × 4 + 1 = 13. ✓

**Part 6a** — Unmodified run prints **18**. After the change it prints **54**, matching your trace.

**Part 6b** — Unmodified run prints quotient **3**, remainder **2**. With 43 and 7: quotient **6**, remainder **1**. With divisor 0: the program prints its divide-by-zero message and exits without executing `div`; the `beq` check on the divisor is responsible.
