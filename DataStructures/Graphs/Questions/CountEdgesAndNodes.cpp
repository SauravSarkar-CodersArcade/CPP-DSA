#include <bits/stdc++.h>
using namespace std;
int countNodes(vector<vector<int>> &adjList){
    return adjList.size();
}
int countEdges(vector<vector<int>> &adjList){
    int edges = 0;
    for (const auto& neighbors : adjList){
        edges += neighbors.size();
    }
    // Since it's an undirected graph, each edge will be counted twice
    return edges/2;
}
int main() {
    vector<vector<int>> adjList = {
            {1, 2},
            {0, 2, 3},
            {0, 1, 4},
            {1, 4},
            {2, 3}
    };
    int nodes = countNodes(adjList);
    int edges = countEdges(adjList);
    cout << "Number of nodes: " << nodes << endl;
    cout << "Number of edges: " << edges << endl;
    return 0;
}
