#include <iostream>
using namespace std;

void selectionSort(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < size; j++)
    {
      if (arr[j] < arr[minIndex])
      {
        minIndex = j;
      }
    }
    // swap
    int tmp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = tmp;
  }
}

int main()
{
  int arr[10] = {23, 56, 72, 46, 16, 33, 29, 42, 59, 41};
  selectionSort(arr, 10);
  for (int i = 0; i < 10; i++)
  {
    cout << arr[i] << " ";
  }
}