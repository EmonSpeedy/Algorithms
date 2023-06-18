#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int visited[N];
vector<int> adj_list[N];

void dfs(int node) {
    cout<<node<<" ";
    visited[node] = 1;
    for(auto adj_nodes : adj_list[node]) {
        if(visited[adj_nodes] == 0) {
            dfs(adj_nodes);
        }
    }
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

    dfs(1);


    return 0;
}