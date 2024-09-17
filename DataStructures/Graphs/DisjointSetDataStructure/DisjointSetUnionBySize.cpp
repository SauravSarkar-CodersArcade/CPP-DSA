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
int main() {
    DisjointSet disjointSet(7);
    disjointSet.unionBySize(1,2);
    disjointSet.unionBySize(2,3);
    disjointSet.unionBySize(4,5);
    disjointSet.unionBySize(6,7);
    disjointSet.unionBySize(5,6);
    // Let's check whether 3 & 7 belong to the same component or not
    if (disjointSet.findUPar(3) == disjointSet.findUPar(7)){
        cout << "Belong to the same component." << endl;
    }else{
        cout << "Don't belong to the same component." << endl;
    }
    disjointSet.unionBySize(3,7);
    // Check again after adding
    if (disjointSet.findUPar(3) == disjointSet.findUPar(7)){
        cout << "Belong to the same component." << endl;
    }else{
        cout << "Don't belong to the same component." << endl;
    }
    return 0;
}
