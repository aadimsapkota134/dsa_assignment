/*Write and Implement the reverse traversal algorithm in the linked list. Write main() to
demonstrate the use of the function.*/

// a singly list list has nodes which has adress of only the next node
// tei bhayera, one way is stack based approach(LIFO)
/*
1.traverse list forward
2.push each node's data onto a stack
3. pop elements from stack to print in reverse order*/
//arko option hami sanga recursion hunthiyo ho, tara even recursion uses call stack. SO WHY NOT, a stack itself!
#include<stdio.h>
#include<stdlib.h>

//linked list
typedef struct Node
{
    int data; 
    struct Node* next; //link to next node
}Node;

//stack
typedef struct Stack
{
    int *arr; //dynamic array to store stact elements
    int top; 
    int max_size;
}St;

//linked list ko node create
Node* createNode(int value){
    Node* newNode = (Node*) malloc(sizeof(Node));

    if(newNode==NULL){
        printf("Failed heap allocation! ");
        exit(1);
    }

    newNode->data = value;
    newNode->next =NULL;
    
    return newNode;
}

//insertion at the end ko logic
void insertEnd(Node* *head, int value){
    //here, function must be able to change the head itself, so, adress of head(pass by reference).
    Node* newNode = createNode(value);
    if(*head==NULL){
        *head = newNode; //set the list's head to point to newly created node
        return; //early exit, kinabhane insertion is complete for empty-list
    }
    Node* temp = *head;//temp points to head which points to first node

    //traverse the lsit until temp points to last node
    while(temp->next!=NULL){
        temp=temp->next; //updateORforward the point to next node
    }

    /*now that temp points to the last node in the list,
    link the last node to the newly created node*/
    temp->next = newNode;
    //now, the last node's next changes from NULL to newNode
}

//forward traverse aba
void forwTrav(Node* head){
    //here, function should ONLY read head, so, pass by copying of address
    Node* temp = head;

    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp= temp->next;
    }

    printf("NULL LIST\n");
}

/*STACK FUNCTIONS*/

St* createStack(int max){
    St* stack = (St*) malloc(sizeof(St));

    if(stack == NULL){
        printf("Stack Allocation Failed! ");
        exit(1);
    }

    stack -> max_size = max;
    stack-> top = -1;//initialize
    stack->arr = (int*) malloc(max * sizeof(int));

    if(stack->arr==NULL){
        printf("Stack array allocation failed! ");
        exit(1);
    }
    
    return stack;

}

void push(St* stack, int value){
    stack->arr[++stack->top] =value;//first, increment the top index by 1
    //storing the new value at the updated top index
}

int pop(St* stack){
    int value= stack->arr[stack->top--];
    //first pop the value, then decrement the top index by 1
    return value;
    
}

void revTrav(Node* head, int count) {
    if (head == NULL) return;

   
    St* stack = createStack(count);
    Node* temp = head;

   
    while (temp != NULL) {
        push(stack, temp->data);
        temp = temp->next;
    }

   
    printf("Reverse: ");
    while (stack->top != -1) {
        printf("%d -> ", pop(stack));
    }
    printf("NULL\n");

    // Cleaning up stack ko memory
    free(stack->arr);
    free(stack);
}


int main() {
    Node* list = NULL;
    int n = 5;

    for(int i = 1; i <= n; i++) {
        insertEnd(&list, i * 10);
    }

    forwTrav(list);
    revTrav(list, n);

    return 0;
}




