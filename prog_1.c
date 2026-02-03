/*Write a program to check if any given mathematical expression has a balanced number of
parentheses or not?*/
//using a stack
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100 //macros

//stack ko structure
typedef struct Stack {
    int top;
    char item[MAX];
}St;

//push a character onto the stack
void push(St* s, char c){
    if(s->top == MAX-1) {
        // MAX-1 cuz indexing starts from 0
        return; //stack overflow, so return nothing
    }
    s->item[++(s->top)] = c; //first, increase the stack's top index by 1, then store the character 'c' in that updated position
}

//pop a char from the stack
char pop(St* s){
    if (s->top == -1){
        return '\0'; //stack underflow
        //must return a valid character, cuz function expects so.
    }
    return s->item[(s->top)--]; //first, return then decrease the stack's top index by 1
}

//check if brackets match
int isMatch(char ch1, char ch2){
    if ( ch1 == '(' && ch2 == ')') return 1;
    if ( ch1 == '[' && ch2 == ']') return 1;
    if ( ch1 == '{' && ch2 == '}') return 1;
    return 0;
}

//main logic to check if the expression is balanced
int isBalanced(char* ex){
    St s;
    s.top=-1;//initializing
    int n = strlen(ex);//length of expression

    for(int i=0; i<n;i++){
        //opening braces, then push 
        if(ex[i] == '(' || ex[i]=='[' || ex[i]=='{'){
            push(&s, ex[i]);
        }

        // closing bracket, then pop
        else if(ex[i] == ')' || ex[i] == '}' || ex[i] == ']' ){
            if (s.top == -1) return 0; //empty stack, hence, closing braces with NO ANY OPENING AT ALL: 'a+b)'

            if(!isMatch(pop(&s),ex[i])){ //'pop' function is called here itself

                return 0; //mismatched braces: '{a+b]' 
                //match must be the 'top' of the stack, for the espression to have balanced parantheses
            }
        }
    }
    //now, since 'pop' operations were done, stack will be empty only if all brackets were matched
    return (s.top == -1); //empty xa bhane, yesle true return garxa, ani 'balanced' bhanera infer gardaa bho
} // sixxxxsevennnnnnnnn

int main(){
    //test expressions to check (array maa haldim)

    char* expressions[] = {
        "a+(b-c)*(d", "m+[a-b*(c+d*{m)]", "a+(b-c)"
    }; //array ho hai yo chi

    printf("Parantheses Balance Checker\n\n");
    for(int i=0;i<3;i++){
        printf("Expression: %s\n",expressions[i]);
        if(isBalanced(expressions[i])){
            printf("Result: Balanced\n\n");
        }
        else{
            printf("Result: Unbalanced\n\n");
        }
    }

    return 0;
}
