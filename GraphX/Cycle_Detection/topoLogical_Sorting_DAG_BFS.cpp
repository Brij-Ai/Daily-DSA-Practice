// Topological sorting of a Directed Acyclic Graph (DAG) using Kahn's algorithm
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

std::vector<int> topologicalSort(const std::vector<std::vector<int>>& graph,vector<int>& inDegree) {
    std::queue<int> q;
    std::vector<int> result;

    // Add all nodes with in-degree 0 to the queue
    for (int i = 0; i < inDegree.size(); i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);

        // Reduce the in-degree of all neighbors
        for (int neighbor : graph[current]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return result;
}

int main() {
    std::vector<std::vector<int>> edgeList = {
        {0, 1},
        {0, 2},
        {1, 3},
        {1, 4},
        {2, 5},
        {2, 6},
        {4, 5}
    };

    int V = 7;
    std::vector<std::vector<int>> adjList(V);
    std::vector<int> inDegree(V, 0);

    // Build the adjacency list and in-degree array
    for (const auto& edge : edgeList) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        inDegree[v]++;
    }

    std::vector<int> sortedOrder = topologicalSort(adjList, inDegree);

    // Output the topological order
    std::cout << "Topological Sort Order: ";
    for (int node : sortedOrder) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    return 0;
}
