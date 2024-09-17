#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for (int i = 0; i <= n ; ++i) { // If 0 is not provided, it will be skipped
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if (node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        } else{
            // Equal rank -> Also increase the rank
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
int main() {
    DisjointSet disjointSet(7);
    disjointSet.unionByRank(1,2);
    disjointSet.unionByRank(2,3);
    disjointSet.unionByRank(4,5);
    disjointSet.unionByRank(6,7);
    disjointSet.unionByRank(5,6);
    // Let's check whether 3 & 7 belong to the same component or not
    if (disjointSet.findUPar(3) == disjointSet.findUPar(7)){
        cout << "Belong to the same component." << endl;
    }else{
        cout << "Don't belong to the same component." << endl;
    }
    disjointSet.unionByRank(3,7);
    // Check again after adding
    if (disjointSet.findUPar(3) == disjointSet.findUPar(7)){
        cout << "Belong to the same component." << endl;
    }else{
        cout << "Don't belong to the same component." << endl;
    }
    return 0;
}
