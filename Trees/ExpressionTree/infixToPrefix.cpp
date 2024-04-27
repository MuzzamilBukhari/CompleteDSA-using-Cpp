#include <iostream>
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

string reverseEq(string eq)
{
  string reverseEq = "";
  for (int i = 0; i < eq.length(); i++)
  {
    if (eq[i] == '(')
    {
      reverseEq = ')' + reverseEq;
    }
    else if (eq[i] == ')')
    {
      reverseEq = '(' + reverseEq;
    }
    else
    {
      reverseEq = eq[i] + reverseEq;
    }
  }
  return reverseEq;
}

string infixToPrefix(string infixEq)
{
  string prefixEq;
  string revPrefixEq;
  string revInfixEq = reverseEq(infixEq);
  for (int i = 0; i < infixEq.length(); i++)
  {
    char currChar = revInfixEq[i];
    if ((currChar > 47 && currChar < 58) || (currChar > 64 && currChar < 123))
    {
      revPrefixEq += currChar;
    }
    else
    {
      if (top == NULL || checkPrecedence(currChar) >= checkPrecedence(top->value) || top->value == '(' || currChar == '(')
      {
        push(currChar);
      }
      else
      {
        do
        {
          revPrefixEq += pop();
        } while (top != NULL && checkPrecedence(currChar) < checkPrecedence(top->value) && top->value != '(');
        if (currChar == ')')
        {
          pop();
        }
        else
        {
          push(currChar);
        }
      }
    }
  }
  while (top != NULL)
  {
    revPrefixEq += pop();
  }
  prefixEq = reverseEq(revPrefixEq);
  return prefixEq;
}

int main()
{
  string infixEq1 = "a+b*c/d*x-f*d";
  string infixEq2 = "a+b*(c-d)<x&(c!y|x+y<5)";
  string prefixEq = infixToPrefix(infixEq2);
  cout << prefixEq << endl;
}
