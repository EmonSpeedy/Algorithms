/*
    Graph Representation
    --------------------
    (Adjacency matrix)

    A-----B
         / \
        C---D

A -> 0
B -> 1
c -> 2
D -> 3

0->1
1->0
1->2
1->3
2->1
2->3
3->2
3->1

# no of edge = 4, # no of nodes = 4;
Type :: Undirected and Unweighted
Matrix shape = 4*4
matrix[i][j] == 1; if and only if (i->j & j->i)

*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //This source code is on the basis of above sample problem__

    //Time complexity --> O(n^2)
    //Space complexity --> O(n^2)
    const int nodes = 4;
    int matrix[nodes][nodes] = {};

    matrix[0][1] = 1;// O(1) But for the worst case O(n^2)
    matrix[1][0] = 1;

    matrix[1][2] = 1;
    matrix[1][3] = 1;

    matrix[2][1] = 1;
    matrix[2][3] = 1;

    matrix[3][2] = 1;
    matrix[3][1] = 1;

    for(int i=0; i<nodes; i++){ //O(n^2)
        for(int j=0; j<nodes; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}