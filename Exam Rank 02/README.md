# Bit Operation
## 🧠 What are bit operations?

Every number in C is stored in binary (bits: 0 and 1).

Example:

- 5  = 00000101

- 3  = 00000011

Bitwise operators let you manipulate these bits directly.

## 🔧 The 6 Bitwise Operators in C
### 1. AND &

Compares each bit → returns 1 only if both bits are 1.
```
5 & 3
  0101 (5)
& 0011 (3)
= 0001 (1)
```
👉 Code:
```
#include <stdio.h>

int main(void)
{
    int a = 5;
    int b = 3;

    printf("%d\n", a & b); // 1
}
```
### 2. OR |

Returns 1 if at least one bit is 1
```
5 | 3

  0101
| 0011
= 0111 (7)
```
Code

```
printf("%d\n", 5 | 3); // 7

```
### 3. XOR ^

Returns 1 if bits are different
```
5 ^ 3

  0101
^ 0011
= 0110 (6)
```
Code
```
printf("%d\n", 5 ^ 3); // 6

```
💡 Important trick:
```
x ^ x = 0
x ^ 0 = x
```
### 4. NOT ~

Flips all bits (0 → 1, 1 → 0)

```
~5

5  = 00000101
~5 = 11111010  (depends on system, usually = -6)
```
Code
```
printf("%d\n", ~5); // -6 (on most systems)
```
⚠️ This uses two’s complement, so results can be negative.

### 5. Left Shift <<

Shifts bits to the left → multiplies by 2

```
5 >> 1

00000101 → 00000010 = 2
```
Code
```
printf("%d\n", 5 << 1); // 10
```
### 6. Right Shift >>

Shifts bits to the right → divides by 2
```
5 >> 1

00000101 → 00000010 = 2
```
Code
```
printf("%d\n", 5 >> 1); // 2
```
## ✅ 1. Check if a bit is ON

Check if nth bit is set:
```
int is_set = (num >> n) & 1;
```
Example:
```
int num = 5; // 0101

printf("%d\n", (num >> 0) & 1); // 1
printf("%d\n", (num >> 1) & 1); // 0
```
Binary of 5:
```
0101
 ↑ ↑ ↑ ↑
 3 2 1 0   (bit positions)
```
- 🔹 (num >> n)

This shifts bits to the right by n positions.

So:

num >> 0 → 0101 (no change)
num >> 1 → 0010

- 🔹 & 1

This keeps only the last bit (rightmost bit).
```
xxxx & 0001 → keeps only last bit
```

1️⃣
Code
```
(num >> 0) & 1
```
Step
```
0101 >> 0 → 0101
0101 & 0001 → 0001 → 1
```
✔ Result: 1

2️⃣
Code
```
(num >> 1) & 1
```
Step
```
0101 >> 1 → 0010
0010 & 0001 → 0000 → 0
```
✔ Result: 0

## ✅ 2. Set a bit

Turn ON a bit:
Code
```
num = num | (1 << n);
```
🧠 Break it into parts
1️⃣ (1 << n)

Shift 1 left by n positions.

Example (n = 2):
```
1       = 0001
1 << 2  = 0100
```
👉 This creates a mask with only the nth bit set.

2️⃣ num | (mask)

OR operation:

1 | anything = 1 ✅ (forces bit ON)
0 | x = x

So this guarantees that the nth bit becomes 1, no matter what it was before.

🔍 Example
```
int num = 5; // 0101
int n = 1;

num = num | (1 << n);
```
Step by Step

```
num       = 0101
1 << 1    = 0010
----------------
OR (|)    = 0111  → 7
```
✔ Result:
```
num = 7;
```
🧪 Another quick example
```
int num = 8; // 1000
int n = 0;

num = num | (1 << 0);
```
```
1000
0001
----
1001 → 9
```
## ✅ 3. Clear a bit

Turn OFF a bit:
```
num = num & ~(1 << n);
```
🧠 Break it down
1️⃣ (1 << n) → create a mask

Example (n = 2):
```
1 << 2 = 0100
```
2️⃣ ~(1 << n) → invert the mask
```
0100  →  ~(...) → 1011
```
👉 Now everything is 1 except the nth bit (which is 0)

3️⃣ num & mask

AND rules:

1 & x = x → keeps the bit
0 & x = 0 → forces OFF

So:
👉 All bits stay the same except the nth bit becomes 0

🔍 Example
```
int num = 7; // 0111
int n = 1;

num = num & ~(1 << n);
```
Step by Step
```
int num = 7; // 0111
int n = 1;

num = num & ~(1 << n);
```
✔ Result:
```
num = 5;
```
🧪 Another quick example

```
int num = 9; // 1001
int n = 0;

num = num & ~(1 << 0);
```
```
1001
~0001 = 1110
-----------
1000 → 8
```
🧠 Easy memory trick
```
| Operation         | Meaning      |             |
| ----------------- | ------------ | ----------- |
| `num              | (1 << n)`    | turn ON bit |
| `num & ~(1 << n)` | turn OFF bit |             |
| `num ^ (1 << n)`  | toggle bit   |             |


```
## ✅ 4. Toggle a bit

Flip it:
```
num = num ^ (1 << n);
```
👉 It means: “toggle (flip) the nth bit of num”

If the bit is 1 → becomes 0
If the bit is 0 → becomes 1

🧠 Break it down
1️⃣ (1 << n) → create mask

Example (n = 1):
```
1 << 1 = 0010
```
👉 Only the nth bit is 1
2️⃣ XOR ^ behavior

Key rules:
```
0 ^ 0 = 0
1 ^ 0 = 1
1 ^ 1 = 0
0 ^ 1 = 1
```
👉 XOR flips bits when mask = 1

🔍 Example
```
int num = 5; // 0101
int n = 1;

num = num ^ (1 << n);
```
Step by step:
```
num       = 0101
1 << 1    = 0010
----------------
XOR (^)   = 0111 → 7
```
✔ Result:
```
num = 7;
```
🔁 Toggle again (important!)

If you run the same line again:
```
0111 ^ 0010 = 0101
```
👉 It goes back!

✔ That’s why XOR is called toggle

🧪 Another example
```
int num = 7; // 0111
int n = 1;

num = num ^ (1 << n);
```
```
0111
0010
----
0101 → 5
```
👉 Bit was 1 → now becomes 0
