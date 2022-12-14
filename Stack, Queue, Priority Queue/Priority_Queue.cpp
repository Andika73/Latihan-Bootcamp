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

void pushRear(int value)
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

void pushQueue(int res)
{
  Node *newNode = createNode(res);

  if (!front || rear->value < res) pushRear(res);
  else if (front->value > res)
  {
    front->next = newNode;
    newNode->prev = front;
    front = newNode;
  }
  else
  {
    Node *currentNode = rear->next;
    while (currentNode->value > res)
    {
      currentNode = currentNode->next;
    }
    newNode->next = currentNode;
    currentNode->prev->next = newNode;
    newNode->prev = currentNode->prev;
    currentNode->prev = newNode;
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
    Node *newFront = front->prev;        // the new top candidate will be below the current top
    front->prev = newFront->next = NULL; // isolate the current top
    free(front);                         // free the allocated memory
    front = newFront;                    // the new top will replace the deleted top
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
  pushQueue(60);
  pushQueue(90);
  pushQueue(50);
  pushQueue(80);

  printQueue(); 

  removeFront();

  printQueue();

  return 0;
}