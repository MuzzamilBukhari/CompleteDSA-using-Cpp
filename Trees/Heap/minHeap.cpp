#include <iostream>
#include <stdlib.h>
using namespace std;

void cHeapify(int arr[], int ci)
{
  int pi = (ci - 1) / 2;
  while (arr[ci] < arr[pi])
  {
    int tmp = arr[ci];
    arr[ci] = arr[pi];
    arr[pi] = tmp;
    ci = pi;
    if (ci == 0)
      break;
    pi = (ci - 1) / 2;
  }
}

int max(int a, int b)
{
  return a > b ? a : b;
}

void insert(int arr[], int value, int size)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == -1)
    {
      arr[i] = value;
      if (i != 0)
      {
        cHeapify(arr, i);
      }
      break;
    }
  }
}

void dHeapify(int arr[], int pi, int size)
{
  int lc = 2 * pi + 1;
  int rc = 2 * pi + 2;
  while (arr[pi] > arr[lc] || arr[pi] > arr[rc])
  {
    if (arr[lc] < arr[rc])
    {
      int tmp = arr[lc];
      arr[lc] = arr[pi];
      arr[pi] = tmp;
      pi = lc;
      lc = 2 * pi + 1;
      rc = 2 * pi + 2;
      if (rc >= size || lc >= size)
      {
        break;
      }
    }
    else
    {
      int tmp = arr[rc];
      arr[rc] = arr[pi];
      arr[pi] = tmp;
      pi = rc;
      lc = 2 * pi + 1;
      rc = 2 * pi + 2;
      if (rc >= size || lc >= size)
      {
        break;
      }
    }
  }
}

void deleteData(int arr[], int size)
{
  for (int i = size - 1; i >= 0; i--)
  {
    if (arr[i] != -1)
    {
      arr[0] = arr[i];
      arr[i] = -1;
      dHeapify(arr, 0, size);
      break;
    }
  }
  if (arr[0] == -1)
  {
    cout << "Heap is Empty " << endl;
  }
}

int main()
{
  int size;
  cout << "Enter size of an Array : ";
  cin >> size;
  int minHeap[size];
  for (int i = 0; i < size; i++)
  {
    minHeap[i] = -1;
  }
  insert(minHeap, 99, size);
  insert(minHeap, 78, size);
  insert(minHeap, 23, size);
  insert(minHeap, 63, size);
  insert(minHeap, 97, size);
  insert(minHeap, 55, size);
  insert(minHeap, 230, size);
  insert(minHeap, 117, size);
  insert(minHeap, 70, size);
  int a;
  do
  {
    cout << "Enter 1 to Insert data " << endl
         << "Enter 2 to delete " << endl
         << "Enter 3 to print " << endl
         << "Enter 4 to exit " << endl;
    cin >> a;
    if (a == 1)
    {
      int value;
      cout << "Enter value : ";
      cin >> value;
      insert(minHeap, value, size);
    }
    else if (a == 2)
    {
      deleteData(minHeap, size);
    }
    else if (a == 3)
    {
      for (int i = 0; i < size; i++)
      {
        cout << minHeap[i] << " ";
      }
    }
    else if (a == 4)
    {
      cout << "Quit" << endl;
    }
  } while (a != 4);
}