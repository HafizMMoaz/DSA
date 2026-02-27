# Hollow Butterfly Pattern

## OBJECTIVE
Print a hollow butterfly pattern for any `n` using nested loops and conditions.

---

## EXAMPLE OUTPUT (n = 5)

```text
*       *
**     **
* *   * *
*  * *  *
*   *   *
*  * *  *
* *   * *
**     **
*       *
```

---

## REQUIREMENTS
- Use nested loops
- Use condition to print `*` or space
- No hardcoding
- Must work for any `n >= 1`
- Pattern has upper half + lower half

---

## LOGIC
For each row in the upper half:
- Left wing width increases from `1` to `n`
- Inner spaces are `2 * (n - row)`

For each row in the lower half:
- Left wing width decreases from `n - 1` to `1`
- Inner spaces are `2 * (n - row)` for mirrored row index

Use conditions inside nested loops:
- Print `*` on wing boundaries
- Print space inside hollow area

---

## END
