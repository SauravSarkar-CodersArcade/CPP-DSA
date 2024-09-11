#include <bits/stdc++.h>
using namespace std;
class TopologicalSortBFSKahnCycleDetection {
public:
    bool isCyclic(int V, vector<int> adj[]){
        int indegree[V] = {0};
        for (int i = 0; i < V; ++i) {
            for (auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            // Reduce the indegree
            for (auto it : adj[node]){
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        // If topo-sort has all nodes, no cycle present
        if (count == V) return false;
        // cycle present
        return true;
    }
};
int main() {
    vector<int> adj[6] = {{},{2},{3},{4,5},{2},{}};
    int V = 6;
    TopologicalSortBFSKahnCycleDetection obj;
    bool ans = obj.isCyclic(V, adj);
    if (ans) cout << "True";
    else cout << "False";
    cout << endl;
    return 0;
}
