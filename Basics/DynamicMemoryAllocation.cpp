#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    // new -> allocation delete -> de-allocation
    // 1D Array -> Linear Array of size n, 1,2,3,4,5,etc
    int n;
    cout << "Enter the size of the array:\n";
    cin >> n;
    int * arr = new int[n];
    cout << "Enter the " << n << " array elements:\n";
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "The array elements are: ";
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    int ** matrix = new int * [n]; // 2D array -> rows & columns
    cout << "\nEnter the matrix elements: " << endl;
    for (int i=0; i<n; i++){
        // each row i = 0,1,2,3,4
        matrix[i] = new int [n];
        for (int j=0; j<n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "The matrix elements are: " << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    delete[]arr;
    delete[]matrix;
    arr = nullptr; // Not mandatory
    matrix = nullptr; // Not mandatory
    return 0;
}
