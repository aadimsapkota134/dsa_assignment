

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void insertAfter(struct Node *givenNode, int value)
{
    if (givenNode == NULL)
    {
        printf("Insertion not possible cuz given node is NULL\n");
        return;
    }

    struct Node *newNode = createNode(value);

    newNode->next = givenNode->next;
    newNode->prev = givenNode;

    if (givenNode->next != NULL)
    {
        givenNode->next->prev = newNode;
    }

    givenNode->next = newNode;
}

void deleteNode(struct Node **head, struct Node *target)
{
    if (*head == NULL || target == NULL)
    {
        printf("Deletion not possible cuz it's invalid node\n");
        return;
    }

    if (target == *head)
    {
        *head = target->next;
    }

    if (target->prev != NULL)
    {
        target->prev->next = target->next;
    }

    if (target->next != NULL)
    {
        target->next->prev = target->prev;
    }

    free(target);
}


void forwTrav(struct Node *head)
{
    struct Node *temp = head;

    printf("NULL <-> ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = createNode(10);
    struct Node *second = createNode(20);
    struct Node *third = createNode(30);

    // Manual linking for initial list 
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    printf("Initial list:\n");
    forwTrav(head);

    printf("\nInsert 25 after node 20:\n");
    insertAfter(second, 25);
    forwTrav(head);

    printf("\nDelete node with value 20:\n");
    deleteNode(&head, second);
    forwTrav(head);

    return 0;
}
