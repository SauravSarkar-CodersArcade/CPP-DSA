#include <iostream>
#include <vector>
using namespace std;
int main() {
    // n -> Nodes - Vertices
    // m -> Edges
    // Undirected Graph
    int n, m;
    cin >> n >> m;
    vector<int> adjList[n+1];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // Directed graph u --> v
        adjList[u].push_back(v);
    }
    for (int i = 1; i <=n ; ++i) {
        cout << "Node " << i << ": ";
        for (int v : adjList[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
