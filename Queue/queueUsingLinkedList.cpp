#include <iostream>
#include <stdlib.h>
using namespace std;

struct QNode
{
  int value;
  QNode *next;
};

QNode *front = NULL;
QNode *rear = NULL;
void enQueue(int value)
{
  QNode *ptr = (QNode *)malloc(sizeof(QNode));
  ptr->value = value;
  ptr->next = NULL;
  if (front == NULL)
  {
    front = ptr;
    rear = ptr;
    return;
  }
  rear->next = ptr;
  rear = ptr;
}
int deQueueue()
{
  if (front == NULL)
  {
    return -1;
  }
  int value = front->value;
  QNode *tmp = front;
  front = front->next;
  free(tmp);
  return value;
}

void print()
{
  if (front == NULL)
  {
    cout << "Queue is Empty " << endl;
    return;
  }
  QNode *curr = front;
  while (curr != NULL)
  {
    cout << "Value is " << curr->value << endl;
    curr = curr->next;
  }
}
int main()
{
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
      enQueue(value);
    }
    else if (n == 2)
    {
      int value = deQueueue();
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
      print();
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