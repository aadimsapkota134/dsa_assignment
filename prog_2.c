//Write a program to convert an infix mathematical expression to postfix and evaluate it.
#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100 //macro

//stack ko structure 
typedef struct 
{
    int top;
    char data[MAX];
}Stack;

//initialize stack
void initialize(Stack* s){
    s->top = -1;
}

void push(Stack* s, char x){
    if(s->top == MAX-1) {
        printf("Stack Overflow!");
        // MAX-1 cuz indexing starts from 0
        return; //stack overflow, so return nothing
    }
    s->data[++s->top] = x; //first, increase the stack's top index by 1, then store the character 'x' in that updated position
}
//pop a char from the stack
char pop(Stack* s){
    if (empty(s)){
        printf("Stack Underflow!");
        return '\0'; //stack underflow
        //must return a valid character, cuz function expects so.
    }
    return s->data[(s->top)--]; //first, return then decrease the stack's top index by 1
}
//peek without popping
char peek(Stack* s){
    if(empty(s)){
        return '\0';
    }
    return s->data[s->top];
}
int empty(Stack* s){
    return s->top == -1;
}

//OPERATOR FUNCTIONS

//precedence level of operators
int precedence(char opr){
    switch(opr){
        case '+':
        case '-': return 1;

        case'*':
        case '/': return 2;

        case '^': return 3;
    }
    return 0;
}

//checking if the character is an operator or not
int isOperator(char c){
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}
int isOperand(char c){
    return isalnum(c);   // checks digit or alphabet
}

//infix to postfix convert
void infixToPostfix(char* infix, char*postfix){
    Stack s;
    initialize(&s);

    int i=0;// index for infix
    int k=0; //index for postfix

    while(infix[i]!='\0'){

        char current = infix[i];

        //case1:for operand: directly add to postfix(in output)
        if(isOperand(current)){
            postfix[k++] = current; //first add current to postfix, then only increment index 'k'
        }

        //case2: opening brackets: push to stack
        else if(current == '('){
            push(&s, current);
        }

        //case3: closing brackets
        else if(current == ')'){
            //pop until matching '(' is found
            while(!empty(&s) && peek(&s)!='('){
                postfix[k++] = pop(&s);//pop returns a character
            }

            //remove '(' from stack
            if(!empty(&s)){
                pop(&s);
            }
        }

        //case4: operator encountered
        else if (isOperator(current)){
            //pop operators with higher or equal precedence
            while(!empty(&s) && ((precedence(peek(&s)) > precedence(current)) ||(precedence(peek(&s)) == precedence(current) && current != '^'))){

                postfix[k++] = pop(&s);
            }

            push(&s, current);
        }
        i++;
    }
    //pop remaining operators
    while(!empty(&s)){
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0';
}

//postfix evaluation
int evaluatePost(char *postfix){
    int stack[MAX]; //integer stack
    int top = -1;

    for(int i=0; postfix[i]!='\0'; i++){
        char current = postfix[i];

        //if operand: push to stack
        if(isOperand(current)){
            stack[++top] = current - '0';
        }

        //if operator: pop two operands and apply

        else{
            int oprnd2 = stack[top--];
            int oprnd1 = stack[top--];
            int result;

            switch(current){
                case '+': result = oprnd1 + oprnd2; break;
                case '-': result = oprnd1 - oprnd2; break;
                case '*': result = oprnd1 * oprnd2; break;
                case '/': result = oprnd1 / oprnd2; break;
                case '^': result = (int)pow(oprnd1, oprnd2); break;
            }
            stack[++top]=result;
        }
    }
    return stack[top];
}

int main(){
    char infix[MAX];
    char postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    //conversion to postfix
    infixToPostfix(infix, postfix);

     // display postfix expression
    printf("Postfix expression: %s\n", postfix);

    //evaluation of postfix
    int result =evaluatePost(postfix);

    printf("Evaluated postfix result: %d\n", result);

    return 0;
}