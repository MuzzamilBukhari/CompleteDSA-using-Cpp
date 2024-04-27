#include <iostream>
#include <stdlib.h>
using namespace std;

struct ETNode
{
  char value;
  ETNode *left;
  ETNode *right;
};

struct StNode
{
  ETNode *node;
  StNode *next;
};

StNode *top = NULL;

void push(ETNode *node)
{
  StNode *ptr = (StNode *)malloc(sizeof(StNode));
  ptr->node = node;
  ptr->next = top;
  top = ptr;
}

ETNode *pop()
{
  if (top == NULL)
  {
    return NULL;
  }
  ETNode *node = top->node;
  StNode *tmp = top;
  top = top->next;
  free(tmp);
  return node;
}

string reverseStr(string str)
{
  string revStr;
  for (int i = 0; i < str.length(); i++)
  {
    revStr = str[i] + revStr;
  }
  return revStr;
}

ETNode *buildExpressionTree(string prefixEq)
{
  string revPrefixEq = reverseStr(prefixEq);
  for (int i = 0; i < revPrefixEq.length(); i++)
  {
    char currChar = revPrefixEq[i];
    if ((currChar > 47 && currChar < 58) || (currChar > 64 && currChar < 123))
    {
      ETNode *node = (ETNode *)malloc(sizeof(ETNode));
      node->value = currChar;
      node->left = node->right = NULL;
      push(node);
    }
    else
    {
      ETNode *node = (ETNode *)malloc(sizeof(ETNode));
      node->value = currChar;
      node->left = pop();
      node->right = pop();
      push(node);
    }
  }
  ETNode *root = pop();
  return root;
}

void preOrderTraversial(ETNode *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->value << " ";
  preOrderTraversial(root->left);
  preOrderTraversial(root->right);
}

int main()
{
  string prefixEq1 = "-+a*/*bcdx*fd";
  string prefixEq2 = "&<+a*b-cdx|!cy<+xy5";
  ETNode *root = buildExpressionTree(prefixEq1);
  preOrderTraversial(root);
}