#include <iostream>
#include <vector>
using namespace std;

bool isCyclicDFS(int node, int parent, vector<vector<int>> &adj, vector<int> &visited)
{
    visited[node] = true;

    for (int x : adj[node])
    {
        if (not visited[x])
        {
            if (isCyclicDFS(x, node, adj, visited))
                return true;
        }
        else if (x != parent)
            return true;
    }

    return false;
}

int main()
{
    vector<vector<int>> edgeList = {
        {0, 1},
        {0, 2},
        {1, 3},
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
        adjList[v].push_back(u);
    }

    vector<int> visited(V, false);

    bool cycleFound = false;

    // Necessary for disconnected graphs
    for (int i = 0; i < V; i++)
    {
        if (not visited[i])
        {
            if (isCyclicDFS(i, -1, adjList, visited))
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