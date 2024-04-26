#include <iostream>
#include <stdlib.h>
using namespace std;
struct StNode
{
  int value;
  StNode *next;
};
StNode *top = NULL;

void push(int value)
{
  StNode *ptr = (StNode *)malloc(sizeof(StNode));
  ptr->value = value;
  ptr->next = top;
  top = ptr;
}

int pop()
{
  if (top == NULL)
  {
    return -1;
  }
  int value = top->value;
  StNode *tmp = top;
  top = top->next;
  free(tmp);
  return value;
}

void print()
{
  if (top == NULL)
  {
    cout << "Stack Underflow" << endl;
  }
  StNode *curr = top;
  while (curr != NULL)
  {
    cout << "Value is " << curr->value << endl;
    curr = curr->next;
  }
}
