#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const long long INF = 1e18;

vector< pair<int, int> > adj_list[N];
long long d[N];

int par[N];

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

    bool detect = false;
    int last_updated_node;

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
                    par[v] = u;
                    if(i == n){
                        detect = true;
                        last_updated_node = v;
                    }
                }
            }
        }
    }

    if(detect){
        cout<<"YES\n";
        int sel_node = last_updated_node;

        for(int i=1; i<=n-1; i++)
        {
            sel_node = par[sel_node];
        }
        int first_node = sel_node;

        vector<int> cycle;
        cycle.push_back(sel_node);

        while (true)
        {
            sel_node = par[sel_node];
            cycle.push_back(sel_node);
            if(sel_node == first_node)
            {
                break;
            }
        }
        reverse(cycle.begin(), cycle.end());
        
        for(auto nodes: cycle)
        {
            cout<<nodes<<" ";
        }
        cout<<"\n";
        return 0;
    }
    else{
        cout<<"NO\n";
    }



    return 0;
}