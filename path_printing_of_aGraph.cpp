#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N];
int level[N];
int parent[N];
vector<int> adjlist[N];

void bfs(int src) {
    visited[src] = 1;
    level[src] = 1;
    queue<int> q;
    q.push(src);
    while (! q.empty())
    {
        int head = q.front();
        q.pop();
        for(auto adjnode : adjlist[head]){
            if(visited[adjnode] == 0){
                parent[adjnode] = head;
                level[adjnode] = level[head] + 1;
                visited[adjnode] = 1;
                q.push(adjnode);
            }
        }
    }
    
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    int src = 1;
    bfs(src);

    if(visited[n] == 0){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    else{
        cout<<level[n]<<"\n";
    }

    int sel_node = n;
    vector<int> path;
    while(true){
        path.push_back(sel_node);
        if(sel_node == 1) break;
        sel_node = parent[sel_node];
    }

    reverse(path.begin(), path.end());

    for(auto nodes : path){
        cout<<nodes<<" ";
    }
    cout<<"\n";

    return 0;
}