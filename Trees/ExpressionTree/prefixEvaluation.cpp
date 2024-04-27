#include <iostream>
#include <stdlib.h>
using namespace std;

struct StNode
{
  int value;
  StNode *next;
};

StNode *top = NULL;

void push(int value)
{
  StNode *ptr = (StNode *)malloc(sizeof(StNode));
  ptr->value = value;
  ptr->next = top;
  top = ptr;
}

char pop()
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

string reverseStr(string str)
{
  string revStr;
  for (int i = 0; i < str.length(); i++)
  {
    revStr = str[i] + revStr;
  }
  return revStr;
}

int prefixEvaluation(string prefixEq)
{
  string revPrefixEq = reverseStr(prefixEq);
  for (int i = 0; i < revPrefixEq.length(); i++)
  {
    char currChar = revPrefixEq[i];
    // cout << currChar << endl;
    if (currChar > 47 && currChar < 58)
    {
      int value = currChar - 48;
      push(value);
    }
    else
    {
      int lop = pop();
      int rop = pop();
      // cout << lop << rop << currChar;
      int tmp;
      switch (currChar)
      {
      case '*':
        tmp = lop * rop;
        break;
      case '/':
        tmp = lop / rop;
        break;
      case '%':
        tmp = lop % rop;
        break;
      case '+':
        tmp = lop + rop;
        break;
      case '-':
        tmp = lop - rop;
        break;
      case '<':
        tmp = lop < rop;
        break;
      case '>':
        tmp = lop > rop;
        break;
      case '=':
        tmp = lop == rop;
        break;
      case '!':
        tmp = lop != rop;
        break;
      case '&':
        tmp = lop && rop;
        break;
      case '|':
        tmp = lop || rop;
        break;
      default:
        break;
      }
      push(tmp);
    }
  }
  return pop();
}

int main()
{
  string infixEq1 = "a+b*c/d*x-f*d";
  string prefixEq1 = "-+a*/*bcdx*fd";
  // let values a = 2, b = 1, c = 3, d = 1, f = 2, x = 2
  // int result = prefixEvaluation("-+2*/*1312*21");

  string infixEq2 = "a+b*(c-d)<x&(c!y|x+y<5)";
  string prefixEq2 = "&<+a*b-cdx|!cy<+xy5";
  // let values a = 2, b= 1, c = 3, d = 1, x = 2, y = 4
  int result = prefixEvaluation("&<+2*1-312|!34<+245");

  cout << "Answer is " << result << endl;
  cout << "Note :- 1 and 0 also indicates true and false!!! " << endl;
}