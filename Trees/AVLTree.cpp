#include <iostream>
using namespace std;

struct BSTNode
{
  int data;
  int heightLeft;
  int heightRight;
  BSTNode *left;
  BSTNode *right;
};

int maxHeight(int a, int b)
{
  return a > b ? a : b;
}

BSTNode *shiftLeft(BSTNode *unbalanceNode)
{
  BSTNode *retNode = unbalanceNode->right;
  BSTNode *tmp = retNode->left;
  retNode->left = unbalanceNode;
  unbalanceNode->right = tmp;
  if (tmp == NULL)
  {
    unbalanceNode->heightRight = 0;
  }
  else
  {
    unbalanceNode->heightRight = maxHeight(tmp->heightLeft, tmp->heightRight) + 1;
  }
  retNode->heightLeft = maxHeight(unbalanceNode->heightLeft, unbalanceNode->heightRight) + 1;
  return retNode;
}

BSTNode *shiftRight(BSTNode *unbalanceNode)
{
  BSTNode *retNode = unbalanceNode->left;
  BSTNode *tmp = retNode->right;
  retNode->right = unbalanceNode;
  unbalanceNode->left = tmp;
  if (tmp == NULL)
  {
    unbalanceNode->heightLeft = 0;
  }
  else
  {
    unbalanceNode->heightLeft = maxHeight(tmp->heightLeft, tmp->heightRight) + 1;
  }
  retNode->heightRight = maxHeight(unbalanceNode->heightLeft, unbalanceNode->heightRight) + 1;
  return retNode;
}

BSTNode *insert(BSTNode *root, int data)
{
  if (root == NULL)
  {
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    node->data = data;
    node->heightLeft = node->heightRight = 0;
    node->left = node->right = NULL;
    return node;
  }
  if (data < root->data)
  {
    root->left = insert(root->left, data);
    root->heightLeft = maxHeight(root->left->heightLeft, root->left->heightRight) + 1;
  }
  else if (data > root->data)
  {
    root->right = insert(root->right, data);
    root->heightRight = maxHeight(root->right->heightLeft, root->right->heightRight) + 1;
  }
  int balanceFactor = root->heightLeft - root->heightRight;
  if (balanceFactor < -1)
  {
    if (data > root->right->data)
    {
      root = shiftLeft(root);
    }
    else
    {
      // double shift
      root->right = shiftRight(root->right);
      root = shiftLeft(root);
    }
  }
  else if (balanceFactor > 1)
  {
    if (data < root->left->data)
    {
      root = shiftRight(root);
    }
    else
    {
      // double shift
      root->left = shiftLeft(root->left);
      root = shiftRight(root);
    }
  }
  return root;
}

// Search
bool search(BSTNode *root, int toSearch)
{
  if (root == NULL)
  {
    return false;
  }
  if (toSearch == root->data)
  {
    return true;
  }
  if (toSearch < root->data)
  {
    search(root->left, toSearch);
  }
  else if (toSearch > root->data)
  {
    search(root->right, toSearch);
  }
}

// In Order Traversial
void inOrderTraversial(BSTNode *root)
{
  if (root == NULL)
  {
    return;
  }
  inOrderTraversial(root->left);
  cout << root->data << " ";
  inOrderTraversial(root->right);
}

// Pre Order Traversial
void preOrderTraversial(BSTNode *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->data << " ";
  preOrderTraversial(root->left);
  preOrderTraversial(root->right);
}

// Post Order Traversial
void postOrderTraversial(BSTNode *root)
{
  if (root == NULL)
  {
    return;
  }
  postOrderTraversial(root->left);
  postOrderTraversial(root->right);
  cout << root->data << " ";
}

BSTNode *min(BSTNode *root)
{
  if (root == NULL)
  {
    return NULL;
  }
  if (root->left == NULL)
  {
    return root;
  }
  min(root->left);
}

BSTNode *max(BSTNode *root)
{
  if (root == NULL)
  {
    return NULL;
  }
  if (root->right == NULL)
  {
    return root;
  }
  max(root->right);
}

BSTNode *deleteNode(BSTNode *root, int toDelete)
{
  if (root == NULL)
  {
    cout << "Value not Found !" << endl;
    return root;
  }
  if (toDelete < root->data)
  {
    root->left = deleteNode(root->left, toDelete);
  }
  else if (toDelete > root->data)
  {
    root->right = deleteNode(root->right, toDelete);
  }
  else
  {
    if (root->left == NULL)
    {
      BSTNode *tmp = root->right;
      free(root);
      cout << "Deleted Successfully " << endl;
      return tmp;
    }
    if (root->right == NULL)
    {
      BSTNode *tmp = root->left;
      free(root);
      cout << "Deleted Successfully " << endl;
      return tmp;
    }
    BSTNode *tmp = root->right;
    BSTNode *minNode = min(tmp);
    root->data = minNode->data;
    root->right = deleteNode(root->right, minNode->data);
  }
}

int main()
{
  BSTNode *root = NULL;

  // Test Case 1
  // root = insert(root, 88);
  // root = insert(root, 23);
  // root = insert(root, 77);
  // root = insert(root, 119);
  // root = insert(root, 250);
  // root = insert(root, 211);
  // root = insert(root, 189);
  // root = insert(root, 76);
  // root = insert(root, 29);
  // root = insert(root, 72);
  // root = insert(root, 84);
  // root = insert(root, 100);
  // root = insert(root, 98);

  int a;
  do
  {
    cout << "Enter 1 to Insert a value" << endl
         << "Enter 2 to Search a value" << endl
         << "enter 3 to print In Order Traversial" << endl
         << "Enter 4 to print PreOrder Traversial" << endl
         << "Enter 5 to Print Post Order Traversial " << endl
         << "Enter 6 to find Minimum Node " << endl
         << "Enter 7 to Find Maximum Node" << endl
         << "Enter 8 to Delete a Node " << endl
         << "Enter 9 to Quit " << endl;
    cin >> a;
    if (a == 1)
    {
      int data;
      cout << "Enter value to Insert : ";
      cin >> data;
      root = insert(root, data);
    }
    else if (a == 2)
    {
      int toSearch;
      cout << "Enter value to Search for : ";
      cin >> toSearch;
      bool isAvailable = search(root, toSearch);
      isAvailable ? cout << "Value found in tree " << endl : cout << "Value not Found " << endl;
    }
    else if (a == 3)
    {
      inOrderTraversial(root);
      cout << endl;
    }
    else if (a == 4)
    {
      preOrderTraversial(root);
      cout << endl;
    }
    else if (a == 5)
    {
      postOrderTraversial(root);
      cout << endl;
    }
    else if (a == 6)
    {
      BSTNode *minNode = min(root);
      if (minNode == NULL)
      {
        cout << "Tree is Empty" << endl;
      }
      else
      {
        cout << minNode->data << endl;
      }
    }
    else if (a == 7)
    {
      BSTNode *maxNode = max(root);
      if (maxNode == NULL)
      {
        cout << "Tree is Empty" << endl;
      }
      else
      {
        cout << maxNode->data << endl;
      }
    }
    else if (a == 8)
    {
      int toDelete;
      cout << "Enter value you want to Delete : ";
      cin >> toDelete;
      root = deleteNode(root, toDelete);
    }
    else if (a == 9)
    {
      cout << "Quit Successfully!!!" << endl;
    }
    else
    {
      cout << "Invalid Number!!! " << endl;
    }
  } while (a != 9);
}