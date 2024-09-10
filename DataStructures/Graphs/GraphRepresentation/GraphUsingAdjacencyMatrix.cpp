#include <iostream>
using namespace std;
int main() {
    // n -> nodes
    // m -> edges
    int n, m;
    cin >> n >> m;
    // We are considering undirected graph
    // It is mandatory to traverse all the nodes
    // Time Complexity : O(n)
    int ** adjMatrix = new int * [n+1];
    for (int i=0; i<=n; i++){
        // each row i = 0,1,2,3,4
        adjMatrix[i] = new int [n+1];
        for (int j=0; j<=n; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        // Undirected graph
        adjMatrix[v][u] = 1;
        // for directed graph
        // adjMatrix[v][u] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
