// Problem: 547. Number of Provinces
#include <bits/stdc++.h>
using namespace std;

// Approach: DFS
// Time Complexity: O(V^2) where V is the number of vertices in the graph
// Space Complexity: O(V) for the visited array
// Time Complexity: O(V^2) for the adjacency matrix representation of the graph

class Solution {
public:
    void dfs(int node, vector<bool> &visited, vector<vector<int>>& isConnected){
        // Mark the node as visited in array
        visited[node] = true;
        // Check its neighbours, if not visited
        for(int i=0; i<isConnected.size(); i++){
            if(isConnected[node][i] == 1 and !visited[i]) dfs(i, visited, isConnected);
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int countOf_Groups = 0;
        vector<bool> visited(n, false);

        // Check how many nodes are not visited till
        for(int i=0; i<n; i++){
            if(not visited[i]){
                dfs(i,visited, isConnected);
                countOf_Groups++;
            }
        }

        return countOf_Groups;
    }
};