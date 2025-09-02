#include <iostream>

using namespace std;

int main(void)
{
  int N, K;
  cin >> N >> K;
  int arr[N];
  int i = N;
  while(i--)
  {
    cin >> arr[i];
  }
  int cnt = 0;
  for(int i = 0; i < N; i++)
  {
    if(arr[i] > K) continue;
    int target = (K / arr[i]) * arr[i];
    cnt += (target / arr[i]);
    K -= target;
    if(K <= 0)
    {
      cout << cnt << "\n";
      return 0;
    }
  }
  return 0;
}
