#include <iostream>
#include <stdlib.h>
using namespace std;

int top = 0;
void push(int stack[], int size, int value)
{
  if (top == size)
  {
    cout << "Stack Overflow!!!" << endl;
    return;
  }
  stack[top] = value;
  top++;
}

int pop(int stack[])
{
  if (top == 0)
  {
    return -1;
  }
  top--;
  return stack[top];
}

void print(int stack[], int size)
{
  cout << "Stack values are : ";
  for (int i = 0; i < size; i++)
  {
    cout << stack[i] << " ";
  }
  cout << endl;
}
