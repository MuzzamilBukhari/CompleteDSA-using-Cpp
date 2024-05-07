#include <iostream>
using namespace std;

bool linearSearch(int arr[], int toSearch, int size)
{
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
  int arr[10] = {23, 56, 72, 46, 16, 33, 29, 42, 59, 41};
  if (linearSearch(arr, 47, 10))
  {
    cout << "Found" << endl;
  }
  else
  {
    cout << "Not found " << endl;
  }
}