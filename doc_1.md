# Balanced Parentheses Checker (Using Stack)

## (a) Data Structure Definition

This program uses a **stack** as the primary data structure to check whether a mathematical expression has balanced parentheses or not.

```c
typedef struct Stack {
    int top;
    char item[MAX];
} St;
```
* The stack size is fixed using the macro `MAX`. `MAX` is 100 here.


**Explanation:**

* `top` stores the index of the topmost element in the stack.
* `item[MAX]` is an array that stores characters (parentheses and brackets) .
* The stack follows the **LIFO (Last In, First Out)** principle, which is ideal for matching opening and closing parentheses.


---

## (b) Description of Functions

### 1. `push(St* s, char c)`

**Purpose:** To insert an opening bracket onto the stack.

* Check for stack overflow.
* Increment `top` and store the character.

---

### 2. `char pop(St* s)`

**Purpose:** To remove and return the top element from the stack.

* Check for stack underflow.
* Return `\0` if the stack is empty.(because function must return a 'char' as defined)

---

### 3. `int isMatch(char ch1, char ch2)`

**Purpose:** To Check whether a pair of opening and closing brackets match.

**Valid Matches:**

* `(` and `)`
* `[` and `]`
* `{` and `}`

Returns `1` if matched, otherwise `0`.

---

### 4. `int isBalanced(char* ex)`

**Purpose:** Core logic to verify whether the expression has balanced parentheses.

**Working:**

* Iterate through the expression character by character.
* Push opening brackets onto the stack.
* Pop and match when a closing bracket is found.
* If a mismatch occurs or a closing bracket appears without a corresponding opening bracket, it returns unbalanced.
* Finally check whether the stack is empty.

Returns:

* `1` → Balanced
* `0` → Unbalanced

---

## (c) Overview of `main()` Function

* Store test expressions(given in question_1 of the assignment) in an array.
* Iterate through each expression.
* Call `isBalanced()` for each expression.
* Print whether the expression is **Balanced** or **Unbalanced**.

The `main()` function is to demonstrate and test the stack-based parentheses checker.

---

## (d) Sample Output

```
Parantheses Balance Checker

Expression: a+(b-c)*(d
Result: Unbalanced

Expression: m+[a-b*(c+d*{m)]
Result: Unbalanced

Expression: a+(b-c)
Result: Balanced
```

---
