#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// BFS for single connected component
vector<int> bfs(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<int> res;
    
    queue<int> q;
    
    int src = 0;
    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        // visit all the unvisited
        // neighbours of current node
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
    
    return res;
}


int main(){
    vector<vector<int>> edgeList = {
       {0,1},{0,2},{1,3},{1,4},{2,5},{2,6}
    };

    int V = edgeList.size() + 1;

    vector<vector<int>> adjList(V);

    for(auto edge : edgeList){
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // display_graph(adjList);
    vector<int> result = bfs(adjList);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}
