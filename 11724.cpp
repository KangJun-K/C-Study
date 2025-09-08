#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using Graph = vector<vector<int>>;
int n, m;
Graph G;
vector<int>visited;

void func(int a)
{
    queue<int> q;
    q.push(a);
    visited[a] = 1;
    while(!q.empty())
    {
        int current_node = q.front();
        q.pop();
        for(int next_node : G[current_node])
        {
            if(!visited[next_node])
            {
                visited[next_node] = 1;
                q.push(next_node);
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    G.resize(n + 1);
    visited.resize(n + 1, 0);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            cnt++;
            func(i);
        }
    }

    cout << cnt << endl;

    return 0;
}