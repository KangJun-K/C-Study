#include <iostream>
#include "cmath"
using namespace std;

int main(void)
{
  int N, K, cnt = 0;
  cin >> N >> K;
  while(true)
  { 
    int target = round(N / K) * K;
    cnt += (N - target);
    N = target;

    if(N < K)
    {
      break;
    }
    cnt++;
    N = N / K;
  }
  cnt += (N - 1);
  cout << cnt << "\n";
  return 0;
}
