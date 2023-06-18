#include<bits/stdc++.h>
using namespace std;

int nodes, edges;
const int N = 1e5 + 10;
vector<int> adj_list[N];
int parent[N];
int visited[N];

bool detect_cycle(int node){
    visited[node] = 1;
    for(auto adj_node : adj_list[node]){
        if(visited[adj_node] == 0){
            parent[adj_node] = node;
            bool is_cycle = detect_cycle(adj_node);
            if(is_cycle){
                return true;
            }
        }
        else if(visited[adj_node] == 1){
            if(adj_node != parent[node]){
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin>>nodes>>edges;
    for(int i=1; i<=edges; i++){
        int edge1, edge2;
        cin>>edge1>>edge2;
        adj_list[edge1].push_back(edge2);
        adj_list[edge2].push_back(edge1);
    }

    bool cycle_found = false;

    for(int i=1; i<=nodes; i++){
        if(visited[i] == 0){
            parent[i] = -1;
            bool is_cycle = detect_cycle(i);
            if(is_cycle){
                cycle_found = true;
                break;
            }
        }
    }

    if(cycle_found){
        cout<<"Cycle Exists\n";
        return 0;
    }
    else{
        cout<<"No Cycle\n";
    }

    return 0;
}