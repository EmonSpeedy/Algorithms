/*
5 8
########
#.A#...#
#.##.#B#
#......#
########
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m;
int maze[N][N];
int visited[N][N];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0}; 
int level[N][N]; 

bool is_inside(pair<int, int> coord) {
    int x,y;
    x = coord.first;
    y = coord.second;
    if(x>=0 && x<n && y>=0 && y<m)
        return true;
    return false;
}

bool is_safe(pair<int, int> coord) {
    int x, y;
    x = coord.first;
    y = coord.second;
    if(maze[x][y] == -1)
        return false;
    return true;
}

void bfs(pair <int, int>src) {
    queue<pair <int,int>> q;
    level[src.first][src.second] = 0;
    visited[src.first][src.second] = 1;
    q.push(src);
    while(! q.empty()) {
        pair<int, int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;
        for(int i=0; i<4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            pair <int, int> adj_node = {new_x,new_y};
            if(is_inside(adj_node) && is_safe(adj_node) && visited[new_x][new_y] == 0){
                visited[new_x][new_y] = 1;
                level[new_x][new_y] = level[x][y] + 1;
                q.push(adj_node);
            }
        }

    }
}

int main() {
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            level[i][j] = -1;
        }
    }
    pair<int, int> src, dest;
    for(int i=0; i<n; i++) {
        string str;
        cin>>str;
        for(int j=0; j<m; j++) {
            if(str[j] == '#') {
                maze[i][j] = -1;
            }
            else if(str[j] == 'A') {
                src = {i, j};
            }
            else if(str[j] == 'B') {
                dest = {i, j};
            }
        }
    }

    bfs(src);

    if(level[dest.first][dest.second] == -1) {
        cout<<"NO\n";
    }
    else {
        cout<<"YES\n";
        cout<<level[dest.first][dest.second]<<"\n";
    }
    return 0;

}