#include<iostream>
#include<algorithm>

using namespace std;

int N, M, num;
int arr[8]={0, };
int visited[8] = {0,};
int result[8];
void print(int a)
{
    if(a == M)
    {
        for(int i = 0; i < M; i++)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < N; i++)
    {
        if(visited[i] == 0)
        {
            visited[i] = 1;
            result[a] = arr[i];
            print(a+1);
            visited[i] = 0;
        }
    }
}

int main(void)
{
   
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        arr[i] = num;
    }
    sort(arr, arr+N);
    print(0);
    return 0;
}