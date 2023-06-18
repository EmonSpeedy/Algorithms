#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int visited[N];
int level[N];
vector<int> adj_list[N];

void bfs(int src) {
    queue<int> q;
    visited[src] = 1;
    level[src] = 0;
    q.push(src);
    while (! q.empty())
    {
        int head = q.front();
        q.pop();
        for(auto adj_nodes : adj_list[head]) {
            if(visited[adj_nodes] == 0) {
                visited[adj_nodes] = 1;
                level[adj_nodes] = level[head] + 1;
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

    int src = 0;
    bfs(src);

    for(int i = 0; i < nodes; i++) {
        cout<<"Node : "<<i<<" Level : "<<level[i]<<"\n";
    } 


    return 0;
}