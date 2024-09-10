#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class GraphCycleDetectBFSUndirected {
private:
    bool detect(int src, vector<int> adjList[], vector<int>& visited){
        visited[src] = 1;
        queue<pair<int, int>> q;
        q.push({src,-1});
        // Traverse until the queue is not empty
        while (!q.empty()){
            int node = q.front().first; // 1
            int parent = q.front().second; // -1
            q.pop();
            // Go to all the adjacent nodes (neighbours) adjList
            for (auto adjacentNode : adjList[node]) {
                // If the node is unvisited
                if (!visited[adjacentNode]){
                    visited[adjacentNode] = 1;
                    q.push({adjacentNode,node});
                } else if (parent != adjacentNode){
                    // Yes it is a cycle
                    return true;
                }
            }
        }
        // There is no cycle
        return false;
    }
public:
    bool isCycle(int V, vector<int> adjList[]){
        vector<int> visited(V+1,0);
        // It will traverse & check all COMPONENTS
        for (int i = 0; i < V; ++i) {
            if (!visited[i]){
                if (detect(i,adjList,visited)) return true;
            }
        }
        return false;
    }
};
int main() {
    vector<int> adjList[8];
    adjList[1] = {2,3};
    adjList[2] = {1,5};
    adjList[3] = {1,4,6};
    adjList[4] = {3};
    adjList[5] = {2,7};
    adjList[6] = {3,7};
    adjList[7] = {5,6};
    GraphCycleDetectBFSUndirected obj;
    bool ans = obj.isCycle(7,adjList);
    if (ans){
        cout << "Yes.\n";
    } else{
        cout << "No.\n";
    }
    return 0;
}
