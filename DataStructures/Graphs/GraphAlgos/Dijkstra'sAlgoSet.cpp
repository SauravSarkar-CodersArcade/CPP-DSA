#include <bits/stdc++.h>
using namespace std;
class DijkstraSet {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        st.insert({0,S});
        dist[S] = 0;
        while (!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            // Check all the adjacent neighbours
            // If Prev distance is larger than the current distance
            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgW = it[1];
                if (dis + edgW < dist[adjNode]){
                    // if it wss already visited at a greater cost/dist
                    if (dist[adjNode] != 1e9)
                        st.erase({dist[node],adjNode});
                    // if the current distance is smaller
                    // push it into the stack
                    dist[adjNode] = dis + edgW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        // return the distance array containing the list of the shortest
        // distances
        return dist;
    }
};
int main() {
    int V = 6, S = 0;
    // Adj List
    vector<vector<int>> adj[V];
    // Add all the edges of the graph serially node by node
    adj[0].push_back({1,4});
    adj[0].push_back({2,4});
    adj[1].push_back({0,4});
    adj[1].push_back({2,2});
    adj[2].push_back({0,4});
    adj[2].push_back({1,2});
    adj[2].push_back({3,3});
    adj[2].push_back({5,6});
    adj[2].push_back({4,1});
    adj[3].push_back({2,3});
    adj[3].push_back({5,2});
    adj[4].push_back({2,1});
    adj[4].push_back({5,3});
    adj[5].push_back({2,6});
    adj[5].push_back({3,2});
    adj[5].push_back({4,3});
    DijkstraSet obj;
    vector<int> ans = obj.dijkstra(V, adj, S);
    for (int i = 0; i < V; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
