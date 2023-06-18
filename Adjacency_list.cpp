/*
    Graph Representation
    --------------------
    (Adjacency List) ---> Linked list/ C++ Vector (Undirected & Unweighted)

    0-----1
         / \
        2---3

0 -> 1
1 -> 0,2,3
2 -> 1,3
3 -> 1,2

# no of nodes = 4

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //This source code is on the basis of above sample problem__

    //Time complexity --> O(n^2)
    //Space complexity --> O(n^2)

    const int nodes = 4;//O(1)
    vector<int> adj_list[nodes];//O(n)

    //O(E) = O(n^2)
    adj_list[0] = {1};
    adj_list[1] = {0, 2, 3};
    adj_list[2] = {1, 3};
    adj_list[3] = {1, 2};

    for(int i=0; i<nodes; i++){ //O(n^2)
        cout<<i<<" -> ";
        for(int j=0; j<adj_list[i].size(); j++){
            cout<<adj_list[i][j]<<", ";
        }
        cout<<"\n";
    }

    return 0;
}