#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    Node *next, *prev;
} *top;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void pushStack(int value)
{
    Node *newNode = createNode(value);

    if (!top) top = newNode;
    else
    {                        
        top->next = newNode; 
        newNode->prev = top; 
        top = newNode;       
    }
}

void removeTop()
{
    if (!top) return;
    else if (!top->prev) 
    {
        free(top);  
        top = NULL; 
    }
    else 
    {
        Node *newTop = top->prev;        
        top->prev = newTop->next = NULL; 
        free(top);                       
        top = newTop;                    
    }
}

void readTop()
{
    Node *currentNode = top;
    printf("Value: %d\n", currentNode->value);
    printf("Alamat Top sekarang: %p\n", currentNode);
}

int main()
{
    pushStack(30);
    pushStack(10);
    pushStack(90);
    pushStack(55);
    readTop();

    removeTop();

    readTop();

    return 0;
}