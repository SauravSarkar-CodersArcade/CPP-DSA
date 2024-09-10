#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adjList[n+1];
    for (int i = 0; i < m; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        // Directed - You can use push_back or emplace back
        adjList[u].emplace_back(make_pair(v,w));
    }
    // Printing the list
    for (int i = 1; i <= n ; ++i) {
        cout << "Node: " << i << ": ";
        for (auto it : adjList[i]) {
            cout << "(" << it.first << ", " << it.second << ") ";
        }
        cout << endl;
    }
    return 0;
}
