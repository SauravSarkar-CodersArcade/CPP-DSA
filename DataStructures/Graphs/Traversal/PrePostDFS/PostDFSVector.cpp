#include <iostream>
#include <vector>
using namespace std;
// O(n)
void dfs_preorder
        (vector<vector<int>>& graph, int node, vector<bool>& visited){
    if (!visited[node]){ // O(n)
        visited[node] = true;
        for (int neighbor : graph[node]) {
            dfs_preorder(graph,neighbor,visited);
        }
        cout << node << " ";
    }
}
int main() {
    vector<vector<int>> graph = {
            {},
            {2,3},
            {4,5},
            {6},
            {},
            {},
            {}
    };
    vector<bool> visited_pre(graph.size(), false);
    cout << "PreOrder DFS: ";
    dfs_preorder(graph,1,visited_pre);
    cout << endl;
    return 0;
}
