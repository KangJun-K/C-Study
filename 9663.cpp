#include <iostream>
#include "stdlib.h"
using namespace std;

int cnt= 0;
int n;
int board[15];


int promising(int cdx)
{
  for(int i = 0; i < cdx; i++)
  {
    if(board[cdx] == board[i] || cdx - i == abs(board[cdx] - board[i]))
    {
      return 0;
    }
  }
  return 1;
}

void nqueen(int cdx)
{
  if(cdx == n)
  {
    cnt++;
    return;
  }
  for(int i = 0; i < n; i++)
  {
    board[cdx] = i;
    if(promising(cdx)) 
    {
      nqueen(cdx + 1);
    }
  }
}

int main(void)
{
  cin >> n;
  nqueen(0);
  cout << cnt << "\n";

  return 0;
}
