/*
    Graph Representation
    --------------------
    (Adjacency List) ---> Linked list/ C++ Vector (Directed & Weighted)

    0-----1
         / \
        2---3


   2
0 --> 1
   4
1 --> 2
   8
3 --> 2
   7
3 --> 1     here, 2, 4, 8, 7 are weights of edges.

# no of nodes = 4

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //This source code is on the basis of above sample problem__


    const int nodes = 4;
    vector< pair<int, int> > adj_list[nodes];

    
    adj_list[0].push_back({1,2});
    adj_list[1].push_back({2,4});
    adj_list[3].push_back({2,8}); 
    adj_list[3].push_back({1,7}); 

    for(int i=0; i<nodes; i++){
        cout<<i<<" -> ";
        for(int j=0; j<adj_list[i].size(); j++){
            cout<<"("<<adj_list[i][j].first<<" ,"<<adj_list[i][j].second<<")"<<", ";
        }
        cout<<"\n";
    }

    return 0;
}