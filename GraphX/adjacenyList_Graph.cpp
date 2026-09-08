#include<iostream>
#include<vector>
using namespace std;

void display_graph(vector<vector<int>> adjList){
    for(int i=0; i<adjList.size(); i++){
        cout<<"Node: "<<i<<" Neighbors: ";
        for(auto x : adjList[i]) cout<<x<<" ";
        cout<<endl; 
    }
}

int main(){
    vector<vector<int>> edgeList = {
        {0,1},{0,2},{2,1},{1,3},{3,4},{4,2},{4,1},
    };

    int V = edgeList.size() + 1;

    vector<vector<int>> adjList(V);

    for(auto edge : edgeList){
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    display_graph(adjList);
    return 0;
}