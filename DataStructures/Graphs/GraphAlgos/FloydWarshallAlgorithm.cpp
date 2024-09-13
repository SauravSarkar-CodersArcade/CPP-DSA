#include <bits/stdc++.h>
using namespace std;
class FloydWarshall {
public:
    void shortest_distance(vector<vector<int>> &matrix){
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == -1){
                    matrix[i][j] = 1e9;
                }
                if (i == j) matrix[i][j] = 0;
            }
        }
        for (int via = 0; via < n; ++via) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    matrix[i][j] = min(matrix[i][j],
                                       matrix[i][via] + matrix[via][j]);
                }
            }
        }
        /*
         To detect negative cycle
         for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][i] < 0){
                    cout << "cycle detected." << endl;
                }
            }
        }
         */
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1e9){
                    matrix[i][j] = -1;
                }
                if (i == j) matrix[i][j] = 0;
            }
        }

    }
};
int main() {
    int V = 4;
    vector<vector<int>> matrix(V, vector<int>(V,-1));
    matrix[0][1] = 2;
    matrix[1][0] = 1;
    matrix[1][2] = 3;
    matrix[3][0] = 3;
    matrix[3][1] = 5;
    matrix[3][2] = 4;
    FloydWarshall obj;
    obj.shortest_distance(matrix);
    for (const auto& row: matrix) {
        for (auto cell : row) {
            cout << cell << "\t";
        }
        cout << endl;
    }
    return 0;
}
