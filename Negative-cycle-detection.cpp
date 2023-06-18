#include<bits/stdc++.h>
using namespace std;

//Time complexity ==> O(n*m)
//Space complexity ==> O(n)

const int N = 100;
const int INF = 1e9;
vector< pair<int, int> > adj_list[N];
int d[N];

int main(){
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++)
    {
        d[i] = INF;
    }

    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin>> u >> v >> w;
        adj_list[u].push_back({v, w});
    }

    int src = 1;
    d[src] = 0;

    bool detect = false;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(auto nodes : adj_list[j])
            {
                int u = j; 
                int v = nodes.first;
                int w = nodes.second;
                if(d[u] + w < d[v]){
                    d[v] = d[u] + w;
                    if(i == n){
                        detect = true;
                    }
                }
            }
        }
    }

    if(detect){
        cout<<"Graph has negative cycle\n";
        return 0;
    }
    else{
        for(int k=1; k<=n; k++)
        {
            cout<<d[k]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}