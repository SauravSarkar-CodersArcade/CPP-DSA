#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for (int i = 0; i <= n ; ++i) { // If 0 is not provided, it will be skipped
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node){
        if (node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class KruskalAlgo {
public:
    int minimumSpanningTreeSum(int V, vector<tuple<int,int,int>>& edges){
        // Sort the edges by weight in ascending order for the MST
        sort(edges.begin(), edges.end());
        DisjointSet ds(V); // Initialize the disjoint set with V vertices
        int mstWt = 0;
        // Kruskal's Algorithm
        for (auto [wt , u, v] : edges){
            if (ds.findUPar(u) != ds.findUPar(v)){
                mstWt += wt;
                ds.unionBySize(u,v);
            }
        }
        return mstWt;
    }
};
int main() {
    int V = 6;
    // List of edges in the form of {weight, u, v}
    vector<tuple<int,int,int>> edges = {
            {1,1,4},
            {2,1,2},
            {3,2,3},
            {3,2,4},
            {4,1,5},
            {5,4,3},
            {7,2,6},
            {8,3,6},
            {9,4,5}
    };
    KruskalAlgo obj;
    int mstWt = obj.minimumSpanningTreeSum(V,edges);
    cout << "The sum of all the edges in the MST: " << mstWt << endl;
    return 0;
}
