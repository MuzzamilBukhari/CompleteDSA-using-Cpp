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

int postfixEvaluation(string postfixEq)
{
  int result;
  for (int i = 0; i < postfixEq.length(); i++)
  {
    char currChar = postfixEq[i];
    if (currChar > 47 && currChar < 58)
      push(currChar - 48);
    else
    {
      int tmp;
      int rop = pop();
      int lop = pop();
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
  result = pop();
  return result;
}
int main()
{
  string infixEq1 = "a+b*c/d*x-f*d";
  string postfixEq1 = "abc*d/x*+fd*-";
  // let values a = 2, b = 1, c = 3, d = 1, f = 2, x = 2
  //  int result = postfixEvaluation("213*1/2*+21*-");

  string infixEq2 = "a+b*(c-d)<x&(c!y|x+y<5)";
  string postfixEq2 = "abcd-*+x<cy!xy+5<|&";
  // let values a = 2, b= 1, c = 3, d = 1, x = 2, y = 4
  int result = postfixEvaluation("2131-*+2<34!24+5<|&");

  cout << "Answer is " << result << endl;
  cout << "Note :- 1 and 0 also indicates true and false!!! " << endl;
}