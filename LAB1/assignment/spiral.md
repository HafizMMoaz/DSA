# Spiral Number Pattern

## OBJECTIVE
Print an `n x n` spiral number pattern using nested loops and no hardcoding.

---

## EXAMPLE OUTPUT (n = 4)

```text
1  2  3  4
12 13 14 5
11 16 15 6
10 9  8  7
```

---

## REQUIREMENTS
- Use nested loops
- No hardcoded matrix values
- Must work for any `n >= 1`

---

## APPROACH
1. Create a 2D array/vector of size `n x n`.
2. Maintain four boundaries:
   - `top`, `bottom`, `left`, `right`
3. Fill numbers in 4 directions repeatedly:
   - Left to right
   - Top to bottom
   - Right to left
   - Bottom to top
4. Shrink boundaries after each direction.
5. Print the filled matrix with nested loops.

---

## END
