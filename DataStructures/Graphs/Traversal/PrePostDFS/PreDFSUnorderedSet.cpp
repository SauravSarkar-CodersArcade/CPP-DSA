#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// O(1)
void dfs_preorder
(vector<vector<int>>& graph, int node, unordered_set<int>& visited){
    if (visited.find(node) == visited.end()){ // O(1) Constant
        cout << node << " ";
        visited.insert(node);
        for (int neighbor : graph[node]) {
            dfs_preorder(graph,neighbor,visited);
        }
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
    unordered_set<int> visited_pre;
    cout << "PreOrder DFS: ";
    dfs_preorder(graph,1,visited_pre);
    cout << endl;
    return 0;
}
