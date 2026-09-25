// Topological Sorting using DFS for a DAG
// 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void topoLogicalDFS(int node, vector<vector<int>> &graph,vector<bool> &visited, vector<int> &result){
    visited[node] = true;

    for(int neighbor : graph[node]){
        if(!visited[neighbor]){
            topoLogicalDFS(neighbor, graph, visited, result);
        }
    }

    result.push_back(node);
}

int main(){
    vector<vector<int>> edgeList = {
        {0, 1},
        {0, 2},
        {1, 3},
        {1, 4},
        {2, 5},
        {2, 6},
        {4, 5}
    };

    int V = 7;
    vector<vector<int>> adjList(V);

    // Build the adjacency list
    for(const auto& edge : edgeList){
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
    }

    vector<bool> visited(V, false);
    vector<int> result;

    // Perform DFS for topological sorting
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            topoLogicalDFS(i, adjList, visited, result);
        }
    }

    // Reverse the result to get the correct topological order
    reverse(result.begin(), result.end());

    // Output the topological order
    cout << "Topological Sort (DFS): ";
    for(int node : result){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}