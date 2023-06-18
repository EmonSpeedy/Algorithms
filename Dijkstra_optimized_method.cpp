#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const long long INF = 1e18;
int n, m;
vector<pair<int,int>> adj_list[N];
int visited[N];
long long d[N];

void dijkstra(int src){
    for(int i=0; i<=n; i++){
        d[i] = INF;
    }

    d[src] = 0;

    priority_queue< pair< long long, int> > pq;
    pq.push({0, src});

    while( !pq.empty() ){
        
        pair<long long, int> head = pq.top();
        pq.pop();

        int selected_node = head.second;

        if(visited[selected_node] == 1){
            continue;
        }
        visited[selected_node] = 1;

        for(auto adj_entry : adj_list[selected_node]){
            int adj_node = adj_entry.first;
            int cost = adj_entry.second;
            if(d[selected_node] + cost < d[adj_node]){
                d[adj_node] = d[selected_node] + cost;
                pq.push({-d[adj_node], adj_node});
            }
        }
    }

}

int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int src = 1;
    dijkstra(src);

    for(int i=1;i<=n;i++){
        cout<<d[i]<<" ";
    }

    return 0;
}