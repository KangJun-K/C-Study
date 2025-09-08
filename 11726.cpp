#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int>v(N + 1, 0);
    for(int i = 1; i <= N; i++)
    {
        if(i == 1) v[1] = 1;
        else if(i == 2) v[2] = 2;
        else v[i] = (v[i-1] + v[i-2]) % 10007;
    }
    cout << v[N] << "\n";
    return 0;
}