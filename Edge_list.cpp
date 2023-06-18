/*
    Graph Representation
    --------------------
    (Edge List) ---> 

    0-----1
         / \
        2---3
[ 
    [0, 1]
    [1, 2]
    [2, 3]
    [1, 3]
]
# no of nodes = 4

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //Time complexity -> O(E) for worst case O(n^2)
    //Space complexity -> O(n^2)
    vector<vector<int> > edge_list;
    edge_list.push_back({0, 1});
    edge_list.push_back({1, 2});
    edge_list.push_back({1, 3});
    edge_list.push_back({2, 3});

    for(int i = 0; i < edge_list.size(); i++){
        cout<<edge_list[i][0]<<" "<<edge_list[i][1]<<'\n';
    }
    
    return 0;
}