#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[node] = true;
    cout << node << " ";

    for (int x : adj[node]) {
        if (!vis[x]) {
            dfs(x, adj, vis);
        }
    }
}

int main(){
    
    vector<vector<int>> edgeList = {
        {0,1},{0,2},{3,4},{4,3}
    };

    int V = edgeList.size() + 1;

    vector<vector<int>> adjList(V);

    for(auto edge : edgeList){
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(V, false);
    dfs(0, adjList, visited);

    return 0;
}