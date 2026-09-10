#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void display_Graph(unordered_map<int, vector<int>> graph){
    for(auto x : graph){
        cout<<"Node: "<<x.first<<" Neighbor: ";
        for(auto ne : x.second) cout<<ne<<" ";
        cout<<endl;
    }
}
int main(){
    vector<vector<int>> edgeList = {
        {0,1},{0,2},{2,1},{1,3},{3,4},{4,2},{4,1},
    };

    unordered_map<int, vector<int>> graph;
    for(auto edge : edgeList){
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    display_Graph(graph);
    return 0;
}