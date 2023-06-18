#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int visited[N];
vector<int> adj_list[N];

void bfs(int node) {
    queue<int> q;
    visited[node] = 1;
    q.push(node);
    while (! q.empty())
    {
        int head = q.front();
        q.pop();
        cout<<head<<" ";
        for(auto adj_nodes : adj_list[head]) {
            if(visited[adj_nodes] == 0) {
                visited[adj_nodes] = 1;
                q.push(adj_nodes);
            }
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

    bfs(4);


    return 0;
}