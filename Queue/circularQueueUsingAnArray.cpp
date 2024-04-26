#include <iostream>
#include <stdlib.h>
using namespace std;

int front = -1;
int rear = -1;

void enQueue(int queue[], int size, int value)
{
  if (front == -1)
  {
    front = 0;
    rear = 0;
    queue[rear] = value;
    return;
  }
  if ((rear == size - 1 && front == 0) || (rear + 1 == front))
  {
    cout << "Queue is full !!!" << endl;
    return;
  }
  if (rear == size - 1 && front != 0)
  {
    rear = 0;
  }
  else
  {
    rear++;
  }
  queue[rear] = value;
}

int deQueue(int queue[], int size)
{
  if (rear == front && front == -1)
  {
    return -1;
  }
  if (front == rear && front != -1)
  {
    int value = queue[front];
    front = -1;
    rear = -1;
    return value;
  }
  int value = queue[front];
  if (front == size - 1)
  {
    front = 0;
  }
  else
  {
    front++;
  }
  return value;
}

void printQueue(int queue[], int size)
{
  cout << "Queue values are ";
  for (int i = 0; i < size; i++)
  {
    cout << queue[i] << " ";
  }
  cout << endl;
}
int main()
{
  int size;
  cout << "Enter size of Queue : ";
  cin >> size;
  int queue[size];
  int n;
  do
  {
    cout << "Enter 1 to Enqueue a value" << endl
         << "Enter 2 to Dequeue a Value" << endl
         << "Enter 3 to Print Queue" << endl
         << "Enter 4 to Exit " << endl;
    cin >> n;
    if (n == 1)
    {
      int value;
      cout << "Enter a Value : ";
      cin >> value;
      enQueue(queue, size, value);
    }
    else if (n == 2)
    {
      int value = deQueue(queue, size);
      if (value < 0)
      {
        cout << "Queue is Empty" << endl;
      }
      else
      {
        cout << "Value is " << value << endl;
      }
    }
    else if (n == 3)
    {
      printQueue(queue, size);
    }
    else if (n == 4)
    {
      cout << "Exit" << endl;
    }
    else
    {
      cout << "Enter number between 1 - 4 !!!" << endl;
    }

  } while (n != 4);
}