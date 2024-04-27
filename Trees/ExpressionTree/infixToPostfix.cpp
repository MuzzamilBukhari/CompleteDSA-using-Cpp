#include <iostream>
#include <stdlib.h>
using namespace std;

struct StNode
{
  char value;
  StNode *next;
};

StNode *top = NULL;

void push(char value)
{
  StNode *ptr = (StNode *)malloc(sizeof(StNode));
  ptr->value = value;
  ptr->next = top;
  top = ptr;
}

int pop()
{
  if (top == NULL)
  {
    return -1;
  }
  int value = top->value;
  StNode *tmp = top;
  top = top->next;
  free(tmp);
  return value;
}

int checkPrecedence(char ch)
{
  if (ch == '|')
    return 1;
  else if (ch == '&')
    return 2;
  else if (ch == '=' || ch == '!')
    return 3;
  else if (ch == '<' || ch == '>')
    return 4;
  else if (ch == '+' || ch == '-')
    return 5;
  else if (ch == '*' || ch == '/' || ch == '%')
    return 6;
  else
    return -1;
}

string infixToPostfix(string infixEq)
{
  string postfixEq = "";
  for (int i = 0; i < infixEq.length(); i++)
  {
    char currChar = infixEq[i];
    if ((currChar > 47 && currChar < 58) || (currChar > 64 && currChar < 123))
    {
      postfixEq += currChar;
    }
    else
    {
      if (top == NULL || checkPrecedence(currChar) > checkPrecedence(top->value) || currChar == '(' || top->value == '(')
      {
        push(currChar);
      }
      else
      {
        do
        {
          postfixEq += pop();
        } while (top != NULL && top->value != '(' && checkPrecedence(currChar) <= checkPrecedence(top->value));
        if (top != NULL && top->value == '(')
          pop();
        if (currChar != ')')
          push(currChar);
      }
    }
  }
  while (top != NULL)
    postfixEq += pop();
  return postfixEq;
}

int main()
{
  string infixEq = "a+b*(c-d)<x&(c!y|x+y<5)";
  string infixEq2 = "a+b*c/d*x-f*d";
  string postfixEq = infixToPostfix(infixEq);
  cout << "Postfix eq is " << postfixEq << endl;
}