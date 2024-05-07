#include <iostream>
using namespace std;

struct Node
{
  int data;
  int index;
  Node *next;
};

void sortedInsert(int value, Node **head)
{
  Node *ptr = (Node *)malloc(sizeof(Node));
  ptr->data = value;
  ptr->index = 0;
  ptr->next = NULL;
  if (*head == NULL)
  {
    *head = ptr;
    return;
  }
  if (ptr->data < (*head)->data)
  {
    ptr->next = *head;
    *head = ptr;
    Node *curr = (*head)->next;
    while (curr != NULL)
    {
      curr->index++;
      curr = curr->next;
    }
    return;
  }
  Node *prev = NULL;
  Node *curr = *head;
  while (curr->next != NULL)
  {
    ptr->index++;
    prev = curr;
    curr = curr->next;
    if (ptr->data < curr->data)
    {
      prev->next = ptr;
      ptr->next = curr;
      while (curr != NULL)
      {
        curr->index++;
        curr = curr->next;
      }
      return;
    }
  }
  // if current == null
  ptr->index++;
  curr->next = ptr;
}

void insert(int value, Node **head)
{
  Node *ptr = (Node *)malloc(sizeof(Node));
  ptr->data = value;
  ptr->index = 0;
  ptr->next = NULL;
  if (*head == NULL)
  {
    *head = ptr;
    return;
  }
  Node *curr = *head;
  while (curr->next != NULL)
  {
    ptr->index++;
    curr = curr->next;
  }
  ptr->index++;
  curr->next = ptr;
}

bool search(int toSearch, Node *head)
{
  if (head == NULL)
  {
    return false;
  }
  Node *curr = head;
  while (curr != NULL)
  {
    if (curr->data == toSearch)
    {
      return true;
    }
    curr = curr->next;
  }
  return false;
}

void print(Node *head)
{
  if (head == NULL)
  {
    cout << "List is Empty" << endl;
    return;
  }
  Node *curr = head;
  while (curr != NULL)
  {
    cout << curr->data << " and index is " << curr->index << " ";
    curr = curr->next;
  }
  cout << endl;
}

void deleteNode(int toDelete, Node **head)
{
  if (*head == NULL)
  {
    cout << "List is EMpty" << endl;
    return;
  }
  if ((*head)->data == toDelete)
  {
    Node *curr = *head;
    *head = (*head)->next;
    free(curr);
    curr = *head;
    while (curr != NULL)
    {
      curr->index--;
      curr = curr->next;
    }
    cout << "Deleted Successfully " << endl;
    return;
  }
  Node *prev = *head;
  Node *curr = (*head)->next;
  while (curr != NULL)
  {
    if (curr->data == toDelete)
    {
      prev->next = curr->next;
      free(curr);
      curr = prev->next;
      while (curr != NULL)
      {
        curr->index--;
        curr = curr->next;
      }
      cout << "Deleted Successfully" << endl;
      return;
    }
    prev = curr;
    curr = curr->next;
  }
  cout << "Value not Found" << endl;
}

void deleteList(Node **head)
{
  if (*head == NULL)
  {
    cout << "list is already empty" << endl;
    return;
  }
  Node *curr = *head;
  do
  {
    *head = (*head)->next;
    free(curr);
    curr = *head;
  } while (curr != NULL);
  cout << "Delete whole List Successfully" << endl;
}

int countNode(Node *head)
{
  if (head == NULL)
  {
    return -1;
  }
  int count = 0;
  Node *curr = head;
  do
  {
    count++;
    curr = curr->next;
  } while (curr != NULL);
  return count;
}

int main()
{
  Node *head = NULL;
  int n;
  do
  {
    cout << "Enter 1 to insert " << endl
         << "Enter 2 to Search" << endl
         << "Enter 3 to Print " << endl
         << "Enter 4 to Delete" << endl
         << "Enter 5 to Delete Whole List" << endl
         << "Enter 6 to Count total no of Nodes" << endl
         << "Enter 7 to Quit" << endl;
    cin >> n;
    if (n == 1)
    {
      int value;
      cout << "Enter value : ";
      cin >> value;
      sortedInsert(value, &head);
    }
    else if (n == 2)
    {
      int toSearch;
      cout << "Enter value to Search ffor : ";
      cin >> toSearch;
      if (search(toSearch, head))
      {
        cout << "Found" << endl;
      }
      else
      {
        cout << "Not found " << endl;
      }
    }
    else if (n == 3)
    {
      print(head);
    }
    else if (n == 4)
    {
      int toDelete;
      cout << "Enter value to Delete : ";
      cin >> toDelete;
      deleteNode(toDelete, &head);
    }
    else if (n == 5)
    {
      deleteList(&head);
    }
    else if (n == 6)
    {
      cout << countNode(head) << endl;
    }
    else if (n == 7)
    {
      cout << "Quit " << endl;
    }
    else
    {
      cout << "Invalid" << endl;
    }
  } while (n != 7);
}