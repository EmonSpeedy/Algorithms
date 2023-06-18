#include<bits/stdc++.h>
using namespace std;

const int N = 20009;
const int BLACK = 1;
const int RED = 2;
const int WHITE = 0;

vector<int>adj[N];
int ans=0 , color[N] , vampire=0 , lykan=0;

void adj_clear()
{
    for(int i=0; i<N; i++)
    {
        adj[i].clear();
    }
}

void BFS(int s)
{
    queue<int>Q;
    color[s] = BLACK; 
    vampire++;
    Q.push(s);

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(color[v] == WHITE)
            {
                Q.push(v);

                if(color[u] == BLACK)
                {
                    color[v] = RED;
                    lykan++;
                }

                else
                {
                    color[v] = BLACK;
                    vampire++;
                }
            }
        }
    }
}

int main()
{
    int t , tc=0 , u , n , v , i=0;
    cin >> t;
    while(t--)
    {
        adj_clear();
        memset(color , 0 , sizeof color);

        vampire = 0;
        lykan = 0;
        ans = 0;

        cin >> n;

        for(i=0; i<n; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(i=0; i<N; i++)
        {
            if(!adj[i].empty() and color[i] == WHITE)
            {
                vampire = 0;
                lykan = 0;
                BFS(i);
                ans += max(vampire , lykan);
            }
        }
        cout << "Case "<<++tc << ": " <<ans<<"\n";
    }

    return 0;
}