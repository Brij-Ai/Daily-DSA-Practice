#include<vector>
#include<iostream>
#include<climits>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int source){
    vector<int> distance(V, INT_MAX);
    distance[source] = 0;

    for(int i=0; i<V-1; i++){
        for(auto edge : edges){
            int u = edge[0]; // starting vertex of the edge
            int v = edge[1]; // ending vertex of the edge
            int weight = edge[2]; // weight of the edge
            if(distance[u] != INT_MAX && distance[u] + weight < distance[v]){ // Relaxation step
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Check for negative weight cycles
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        if(distance[u] != INT_MAX && distance[u] + weight < distance[v]){
            cout << "Graph contains negative weight cycle" << endl;
            return {};
        }
    }
    return distance;
}

int main(){
    int V = 5;
    vector<vector<int>> edges = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
    int source = 0;
    vector<int> distance = bellmanFord(V, edges, source);
    for(int i=0; i<V; i++){
        cout << "Distance from source to vertex " << i << " is " << distance[i] << endl;
    }
    return 0;
}