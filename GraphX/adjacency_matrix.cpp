#include<iostream>
#include<vector>
using namespace std;

void print_Graph(vector<vector<int>> adj){
    for(int i=0; i<adj.size(); i++){
        cout<<"Node : "<<i<<", Neighbours: ";
        for(int j=0; j<adj[i].size(); j++){
            if(adj[i][j] == 1)cout<<j<<" ";
        }cout<<endl;
    }
}

int main(){

    vector<vector<int>> edgeList = {
        {0,1},{0,2},{0,3},{3,2}
    };

    int V = edgeList.size(); // Number of vertices 
    // Adjacency matrix
    vector<vector<int>> adj_matrix(V, vector<int>(V,0));

    for(int i=0; i<V; i++){
        int u = edgeList[i][0];
        int v = edgeList[i][1];

        // mark cell as '1' where edge between u <--> v
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }

    // Display Node and Its Neighbors
    print_Graph(adj_matrix);
}