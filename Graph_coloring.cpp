#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int visited[N];
int color[N];
vector<int> adj_list[N];

bool dfs(int src) {
    visited[src] = 1;

    for(auto adj_nodes : adj_list[src]) {
        if(visited[adj_nodes] == 0){
            if(color[src] == 1) color[adj_nodes] = 2;
            else color[adj_nodes] = 1;

            bool is_colorable = dfs(adj_nodes);
            if(! is_colorable){
                return false;
            }
        }
        else{
            if(color[src] == color[adj_nodes]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    for(int k=0; k<edges; k++) {
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bool is_bipartite = true;

    for(int i=1; i<=nodes; i++) {
        if(visited[i] == 0) {
            color[i] = 1;
            bool is_ok = dfs(i);
            if(!is_ok){
                is_bipartite = false;
            }
        }
    }

    if(!is_bipartite){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        for(int i=1; i<=nodes; i++){
            cout<<color[i]<<" ";
        }
    }

    return 0;
}