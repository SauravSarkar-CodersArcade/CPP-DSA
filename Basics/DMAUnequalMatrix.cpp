#include <iostream>
using namespace std;

int main() {
    int row;
    int col;
    cin >> row >> col;
    // rows
    int ** matrix = new int * [row]; // Whole matrix
    for (int i=0; i<row; i++){
        matrix[i] = new int [col]; // Each row
        for (int j=0; j<col; j++){ // Each column
            cin >> matrix[i][j];
        }
    }
    cout << "Matrix:" << endl;
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
