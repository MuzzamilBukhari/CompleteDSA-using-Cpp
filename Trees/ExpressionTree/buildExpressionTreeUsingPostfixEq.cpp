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

ETNode *buildExpressionTree(string postfixEq)
{
  for (int i = 0; i < postfixEq.length(); i++)
  {
    char currChar = postfixEq[i];
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
      node->right = pop();
      node->left = pop();
      push(node);
    }
  }
  ETNode *root = pop();
  return root;
}

void postOrderTraversial(ETNode *root)
{
  if (root == NULL)
  {
    return;
  }
  postOrderTraversial(root->left);
  postOrderTraversial(root->right);
  cout << root->value << " ";
}

int main()
{
  string postfixEq1 = "abc*d/x*+fd*-";
  string postfixEq2 = "abcd-*+x<cy!xy+5<|&";
  ETNode *root = buildExpressionTree(postfixEq2);
  postOrderTraversial(root);
}