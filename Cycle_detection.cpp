/*
4 5
1 3
2 1
3 2
2 4
3 4
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int> adj_list[N];
int visited[N];

bool detect_cycle(int node){
    visited[node] = 1;
    for(auto adj_node : adj_list[node]) {
        if(visited[adj_node] == 0) {
            bool is_cycle = detect_cycle(adj_node);
            if(is_cycle){
                return true;
            }
        }
        else if(visited[adj_node] == 1) {
            return true;
        }
    }
    visited[node] = 2;
    return false;
}

int main() {
    int n, m;
    cin>>n>>m;

    for(int i=1; i<=m; i++) {
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
    }

    bool cycle_exist = false;

    for(int i=1; i<=n; i++) {
        if(visited[i] == 0){
            bool is_cycle = detect_cycle(i);
            if(is_cycle){
                cycle_exist = true;
                break;
            }
        }
    }
    if(cycle_exist) {
        cout<<"Cycle exists\n";
    }
    else
        cout<<"No cycle detected\n";

    return 0;
}
