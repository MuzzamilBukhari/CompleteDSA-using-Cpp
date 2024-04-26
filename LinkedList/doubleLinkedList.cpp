#include <iostream>
#include <stdlib.h>
using namespace std;
struct Record
{
  int rollNo;
  float CGPA;
  Record *prev;
  Record *next;
  int index;
};

void sortedInsert(Record **head)
{
  Record *ptr = (Record *)malloc(sizeof(Record));
  cout << "Enter Roll no of the Student : ";
  cin >> ptr->rollNo;
  cout << "Enter CGPA of Student : ";
  cin >> ptr->CGPA;
  if (*head == NULL)
  {
    ptr->prev = NULL;
    ptr->next = NULL;
    ptr->index = 0;
    *head = ptr;
    return;
  }
  Record *curr = *head;
  if (ptr->rollNo < (*head)->rollNo)
  {
    ptr->prev = NULL;
    ptr->next = *head;
    ptr->index = 0;
    *head = ptr;
    curr->prev = *head;
    while (curr != NULL)
    {
      curr->index++;
      curr = curr->next;
    }
    return;
  }
  curr = (*head)->next;
  while (curr != NULL)
  {
    if (ptr->rollNo < curr->rollNo)
    {
      ptr->next = curr;
      ptr->index = (curr->prev->index) + 1;
      curr->prev->next = ptr;
      while (curr != NULL)
      {
        curr->index++;
        curr = curr->next;
      }
      return;
    }
    curr = curr->next;
  }
  if (curr == NULL)
  {
    curr = (*head)->next;
    while (curr->next != NULL)
    {
      curr = curr->next;
    }
    curr->next = ptr;
    ptr->prev = curr;
    ptr->next = NULL;
    ptr->index = (curr->index) + 1;
  }
}

void insert(Record **head)
{
  Record *ptr = (Record *)malloc(sizeof(Record));
  cout << "Enter Roll no of the Student : ";
  cin >> ptr->rollNo;
  cout << "Enter CGPA of Student : ";
  cin >> ptr->CGPA;
  ptr->prev = NULL;
  ptr->next = NULL;
  if (*head == NULL)
  {
    ptr->index = 0;
    *head = ptr;
    return;
  }
  Record *curr = *head;
  ptr->index = 1;
  while (curr->next != NULL)
  {
    curr = curr->next;
    ptr->index++;
  }
  curr->next = ptr;
  ptr->prev = curr;
}

void search(Record *head)
{
  if (head == NULL)
  {
    cout << "List is Empty" << endl;
    return;
  }
  int toSearch;
  cout << "Enter Roll no you want to Search : ";
  cin >> toSearch;
  if (head->rollNo == toSearch)
  {
    cout << "CGPA of the student is " << head->CGPA << endl;
    return;
  }
  Record *curr = head->next;
  while (curr != NULL)
  {
    if (curr->rollNo == toSearch)
    {
      cout << "CGPA of the student is " << curr->CGPA << endl;
      return;
    }
    curr = curr->next;
  }
  if (curr == NULL)
  {
    cout << "Roll no not Found in the List" << endl;
  }
}

void print(Record *head)
{
  if (head == NULL)
  {
    cout << "List is Empty" << endl;
    return;
  }
  Record *curr = head;
  while (curr != NULL)
  {
    cout << "CGPA of Roll no " << curr->rollNo << " is " << curr->CGPA << " and the index of Node is " << curr->index << endl;
    curr = curr->next;
  }
}

void deleteElement(Record **head)
{
  if (*head == NULL)
  {
    cout << "List is Empty " << endl;
    return;
  }
  int toDelete;
  cout << "Enter Roll no of Student which you want to Delete : ";
  cin >> toDelete;
  Record *curr = *head;
  if (curr->rollNo == toDelete)
  {
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(curr);
    curr = *head;
    while (curr != NULL)
    {
      curr->index--;
      curr = curr->next;
    }
    cout << "Deleted successfully  " << endl;
    return;
  }
  curr = curr->next;
  while (curr != NULL)
  {
    if (curr->rollNo == toDelete)
    {
      curr->prev->next = curr->next;
      curr->next->prev = curr->prev;

      free(curr);
      cout << "Deleted successfully  " << endl;
      break;
    }
    curr = curr->next;
  }
  if (curr == NULL)
  {
    cout << "Roll no Not found in the List " << endl;
  }
  else
  {
    curr = curr->next;
    while (curr != NULL)
    {
      curr->index--;
      curr = curr->next;
    }
  }
}

void deleteList(Record **head)
{
  if (*head == NULL)
  {
    cout << "List is empty " << endl;
    return;
  }
  Record *curr = *head;
  while (*head != NULL)
  {
    *head = (*head)->next;
    free(curr);
    curr = *head;
  }
  cout << "Whole List Deleted " << endl;
}

int count(Record *head)
{
  int count = 0;
  Record *curr = head;
  while (curr != NULL)
  {
    count++;
    curr = curr->next;
  }
  return count;
}

int main()
{
  Record *head = NULL;
  int n;
  do
  {
    cout << "Enter 1 to Insert data " << endl
         << "Enter 2 to search data " << endl
         << "Enter 3 to print all Records" << endl
         << "Enter 4 to Delete a Record " << endl
         << "Enter 5 to Delete whole List " << endl
         << "Enter 6 to print total no of Nodes " << endl
         << "Enter 7 to Quit" << endl;
    cin >> n;
    if (n == 1)
    {
      sortedInsert(&head);
    }
    else if (n == 2)
    {
      search(head);
    }
    else if (n == 3)
    {
      print(head);
    }
    else if (n == 4)
    {
      deleteElement(&head);
    }
    else if (n == 5)
    {
      deleteList(&head);
    }
    else if (n == 6)
    {
      cout << "Total no of Nodes are " << count(head) << endl;
    }
  } while (n != 7);
}