// 
#include<iostream>
#include<vector>

using namespace std;

bool isCyclicDFS(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &path){
    visited[node] = true;
    path[node] = true;

    // Visiting neighbors
    for(int nbr : adj[node]){
        if(not visited[nbr]){
            if(isCyclicDFS(nbr, adj, visited, path)) return true;
        }else{
            if(path[nbr]) return true;
        }
    }

    // Remove node from our path
    path[node] = false;
    return false;
}

int main(){
    vector<vector<int>> edgeList = {
        {0, 1},
        {1, 0},
        {0, 2},
        {1, 3},
        {2, 3},
        {1, 4},
        {2, 5},
        {2, 6},
        {4, 5}};

    int V = 7;

    vector<vector<int>> adjList(V);

    for (auto edge : edgeList)
    {
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);
    }

    vector<bool> visited(V, false);
    vector<bool> path(V, 0);

    bool cycleFound = false;

    // Necessary for disconnected graphs
    for (int i = 0; i < V; i++)
    {
        if (not visited[i])
        {
            if (isCyclicDFS(i, adjList, visited, path))
            {
                cycleFound = true;
                break;
            }
        }
    }

    if (cycleFound)
    {
        cout << "Cyclic graph!";
    }
    else
    {
        cout << "Acyclic graph";
    }
    return 0;
}