#include <iostream>
using namespace std;

bool binarySearch(int arr[], int toSearch, int size)
{
  int si = 0;
  int li = size - 1;
  int mi;
  while (si <= li)
  {
    mi = (si + li) / 2;
    if (toSearch > arr[mi])
    {
      si = mi + 1;
    }
    else if (toSearch < arr[mi])
    {
      li = mi - 1;
    }
    else
    {
      return true;
    }
  }
  return false;
  for (int i = 0; i < size; i++)
  {
    if (toSearch == arr[i])
    {
      return true;
    }
  }
  return false;
}

int main()
{
  int arr[10] = {12, 15, 23, 27, 31, 32, 37, 41, 45, 53};
  if (binarySearch(arr, 15, 10))
  {
    cout << "Found" << endl;
  }
  else
  {
    cout << "Not found " << endl;
  }
}