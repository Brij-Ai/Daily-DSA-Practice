#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isCyclicBFS(
    int src,
    vector<vector<int>> &adj,
    vector<int> &visitedAndParent)
{
    queue<int> q;

    q.push(src);
    visitedAndParent[src] = src;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int nbr : adj[node])
        {
            // Neighbor is not visited
            if (visitedAndParent[nbr] == -1)
            {
                q.push(nbr);
                visitedAndParent[nbr] = node;
            }
            // Neighbor is visited and is not the parent
            else if (visitedAndParent[node] != nbr)
            {
                return true;
            }
        }
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

    vector<int> visitedAndParent(V, -1);

    bool cycleFound = false;

    // Necessary for disconnected graphs
    for (int i = 0; i < V; i++)
    {
        if (visitedAndParent[i] == -1)
        {
            if (isCyclicBFS(i, adjList, visitedAndParent))
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