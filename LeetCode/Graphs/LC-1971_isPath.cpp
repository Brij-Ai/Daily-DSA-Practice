// Problem: 1971. Find if Path Exists in Graph
#include <bits/stdc++.h>
using namespace std;

// Approach: DFS and BFS
// Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
class Solution {
public:
// DFS traversal
    void dfs(int src, int dst, vector<bool> &visited, vector<vector<int>> &adj){
        visited[src] = true;

        for(auto nbr : adj[src]){
            if(not visited[nbr]) dfs(nbr, dst, visited, adj);
        }

    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

    // Formation of adjacency list
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Dfs call
        // vector<bool> vis(n, false);
        // return dfs(source, destination, vis, adj);
        // return vis[destination]; 

        // BFS traversal
        queue<int> que;
        que.push(source);

        vector<bool> vis(n, false);
        vis[source] = true;

        while(not que.empty()){
            int node = que.front();
            que.pop();

            // Reached at the destinatio
            if(node == destination) return true;
            // Mark as visited
            vis[node] = true;

            // travers its all neighbor
            for(auto nbr : adj[node]){
                if(not vis[nbr]){
                    if(nbr == destination) return true;
                    que.push(nbr);
                }
            }
        }

        return false;
    }
};