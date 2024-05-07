#include <iostream>
using namespace std;

int top = -1;
void push(int value, int stack[], int size)
{
  if (top == size - 1)
  {
    cout << "Stack overflow" << endl;
    return;
  }
  top++;
  stack[top] = value;
}

int pop(int stack[], int size)
{
  if (top == -1)
  {
    return -1;
  }
  int tmp = stack[top];
  top--;
  return tmp;
}

void print(int stack[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << stack[i] << " ";
  }
  cout << endl;
}
int main()
{
  int stack[10];
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
      push(value, stack, 10);
    }
    else if (n == 2)
    {
      cout << pop(stack, 10) << endl;
    }
    else if (n == 3)
    {
      print(stack, 10);
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