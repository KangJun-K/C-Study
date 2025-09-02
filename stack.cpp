#include "iostream"
#include "vector"
#include "string"
#define MAX_SIZE 10
using namespace std;
int top = -1;
vector<char>str(MAX_SIZE);
int full(){return top == MAX_SIZE;}
int empty(){return top == -1;}
void push(char ch)
{
  if(full())
  {
    cout << "overflow" << "\n";
    return;
  }
  str[++top] = ch;
}
char pop()
{
  if(empty())
  {
    cout << "underflow" << "\n";
    return 0;
  }
  return str[top--];
}

int main(void)
{
  string s;
  cin >> s;
  for(int i = 0; i < s.size(); i++)
  {
    if(s[i] == '(' || s[i] == '{' || s[i] == '[')
    {
      push(s[i]);
    }
    else{
      char tmp = pop();
      if(s[i] == ')' && tmp != '('){
        cout << "False" << "\n";
        return 0;
      }
      else if(s[i] == '}' && tmp != '{')
      {
        cout << "Fasle" << "\n";
        return 0;
      }
      else if(s[i] == ']' && tmp != '[')
      {
        cout << "False" << "\n";
        return 0;
      }
    }
  }
  if(empty())
    cout << "True\n";
  else
    cout << "False\n";
  return 0;
}
