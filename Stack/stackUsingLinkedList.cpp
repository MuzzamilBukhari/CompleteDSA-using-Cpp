#include <iostream>
using namespace std;

struct StackNode
{
  int data;
  StackNode *next;
};

void push(int value, StackNode **top)
{
  StackNode *ptr = (StackNode *)malloc(sizeof(StackNode));
  ptr->data = value;
  if (*top == NULL)
  {
    ptr->next = NULL;
    *top = ptr;
    return;
  }
  ptr->next = *top;
  *top = ptr;
}

int pop(StackNode **top)
{
  if (*top == NULL)
  {
    return -1;
  }
  StackNode *curr = *top;
  *top = (*top)->next;
  int data = curr->data;
  free(curr);
  cout << "Pop successfully" << endl;
  return data;
}

void print(StackNode *top)
{
  if (top == NULL)
  {
    cout << "List is empty" << endl;
    return;
  }
  StackNode *curr = top;
  while (curr != NULL)
  {
    cout << curr->data << " ";
    curr = curr->next;
  }
}
int main()
{
  StackNode *top = NULL;
  int n;
  do
  {
    cout << "Enter 1 to push " << endl
         << "Enter 2 to pop" << endl
         << "Enter 3 to Print " << endl
         << "Enter 4 to Quit" << endl;
    cin >> n;
    if (n == 1)
    {
      int value;
      cout << "Enter value : ";
      cin >> value;
      push(value, &top);
    }
    else if (n == 2)
    {
      cout << pop(&top) << endl;
    }
    else if (n == 3)
    {
      print(top);
    }
    else if (n == 4)
    {
      cout << "Quit " << endl;
    }
    else
    {
      cout << "Invalid" << endl;
    }
  } while (n != 4);
}