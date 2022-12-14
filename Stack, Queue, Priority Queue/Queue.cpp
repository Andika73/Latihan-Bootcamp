#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    Node *next, *prev;  
} *front, *rear;

Node *createNode(int value)
{
    Node *newRear = (Node *)malloc(sizeof(Node));
    newRear->value = value;
    newRear->next = newRear->prev = NULL;
    return newRear;
}

void pushQueue(int value)
{
    Node *newRear = createNode(value);

    if (!front) front = rear = newRear;
    else
    {                         
        rear->prev = newRear; 
        newRear->next = rear;  
        rear = newRear;       
    }
}

void removeFront()
{
    if (!front) return;
    else if (!front->prev)  
    {
        free(front);   
        front = NULL;  
    }
    else  
    {
        Node *newFront = front->prev;        
        front->prev = newFront->next = NULL;  
        free(front);                          
        front = newFront;                    
    }
}

void readNode(Node *currentNode)
{
    printf("Value: %d\n", currentNode->value);
    printf("Alamat node sebelumnya: %p\n", currentNode->prev);
    printf("Alamat node sekarang: %p\n", currentNode);
    printf("Alamat node setelahnya: %p\n", currentNode->next);
}

void printQueue()
{
    for (Node *temp = rear; temp != NULL; temp = temp->next)
    {
        readNode(temp);
        puts("|");
        puts("v");
    }
    puts("NULL");
}

int main()
{
    pushQueue(50);
    pushQueue(10);
    pushQueue(30);
    pushQueue(20);
    pushQueue(40);
    printQueue();
    removeFront();
    printQueue();

    return 0;
}