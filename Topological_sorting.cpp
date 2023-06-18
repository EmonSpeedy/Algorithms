/*
5 3
1 2
3 1
4 5
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 2000;
vector<int> adj_list[N];
int visited[N];
stack<int> stc;

void dfs(int node){
    visited[node] = 1;

    for(auto adj_node : adj_list[node]){
        if(visited[adj_node] == 0){
            dfs(adj_node);
        }
    }
    stc.push(node);
}

int main() {
    int n, m;
    cin>>n>>m;

    for(int i=1; i<=m; i++) {
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
    }

    for(int i=1; i<=n; i++){
        if(visited[i] == 0){
            dfs(i);
        }
    }

    while(! stc.empty()){
        cout<<stc.top()<<" ";
        stc.pop();
    }
    cout<<"\n";

    return 0;
}