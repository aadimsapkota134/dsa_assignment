# Infix to Postfix Conversion and Evaluation Using Stack

## (a) Data Structure Definition

The program uses a stack data structure implemented using an array.

Structure:
```c
typedef struct {
    int top;
    char data[MAX];
} Stack;
```
Explanation:

- `top` represents index of top element.
- `data[]` stores operators during conversion.
- Stack follows LIFO principle which helps maintain operator precedence and bracket matching.

Another integer stack is used internally for postfix evaluation.

---

## (b) Description of Functions

### 1. `initialize()`
Initializes stack by setting top to -1.

### 2. `empty()`
Returns true if stack contains no elements.

### 3. `push()`
Adds element to stack.

### 4. `pop()`
Removes and returns top element.

### 5. `peek()`
Returns top element without removing.

### 6. `precedence()`
Defines operator priority.

### 7. `isOperator()`
Checks whether character is an operator.

### 8. `isOperand()`
Checks whether character is digit or alphabet.

### 9. `infixToPostfix()`
Converts infix expression to postfix:

- Operands go directly to output.
- Opening brackets pushed to stack.
- Closing brackets triggers pop until matching '('.
- Operators pushed based on precedence rules.

### 10. `evaluatePostfix()`
Evaluates postfix expression using integer stack:

- Push operands.
- When operator encountered:
    - Pop two operands
    - Apply operation
    - Push result back.

---

## (c) Overview of main()

1. Accept infix expression from user.
2. Convert infix to postfix.
3. Display postfix expression.
4. Evaluate postfix expression.
5. Display result.

---

## (d) Sample Output
```
Enter infix expression: 3+5*2

Postfix Expression: 352*+

Evaluated Result: 13

---
```
