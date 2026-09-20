#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<vector<int>> floydWarshall(int V, vector<vector<int>> &graph) {
    vector<vector<int>> dist = graph; // Initialize distance matrix with graph weights
    // Floyd-Warshall algorithm
    // Iterate through all vertices as intermediate vertices
    for (int k = 0; k < V; k++) {
        // Iterate through all pairs of vertices (i, j)
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // source i to destination j through intermediate vertex k
                // Check if the current distance is not infinity to avoid overflow
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) { // Check for overflow
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    return dist;
}

int main(){
    int INF = INT_MAX;
    int V = 4;
    vector<vector<int>> graph(V, vector<int>(V, INF));

    vector<vector<int>> edges = {
        {0, 1, 5},
        {0, 3, 10},
        {1, 2, 3},
        {2, 3, 1}
    };

    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        graph[u][v] = weight;
    }

    vector<vector<int>> dist = floydWarshall(V, graph);

    cout << "Shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

}