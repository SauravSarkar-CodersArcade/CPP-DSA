#include <iostream>
#include <vector>
using namespace std;
class Graph {
private:
    int V; // number of nodes or vertex
    vector<vector<int>> adjMatrix;
public:
    Graph(int vertices){
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0));
    }
    void addEdge(int u, int v){
        // Undirected Graph
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    void printAdjMatrix(){
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    Graph graph(5);
    graph.addEdge(0,2);
    graph.addEdge(0,3);
    graph.addEdge(2,3);
    graph.addEdge(0,4);
    graph.addEdge(3,4);
    graph.addEdge(3,1);
    graph.addEdge(2,1);
    graph.printAdjMatrix();
    return 0;
}
