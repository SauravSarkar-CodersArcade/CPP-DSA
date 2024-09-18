#include <iostream>
using namespace std;
// We will create a function to check
// if a given cell / position is safe to move or not..!!
bool isPathSafe(int** arr, int x, int y, int n){
    if (x < n && y < n && arr[x][y] == 1){
        return true;
    }
    return false;
}
// Recursive function to find the path for the rat in the maze
bool ratInMaze(int** arr, int x, int y, int n, int** resultantArray){
    // Base Case: If the rat has already reached the destination
    if (x == (n-1) && y == (n-1)){
        resultantArray[x][y] = 1; // Mark the destination as reached. [1]
        return true;
    }
    // Check if the current position is safe to stand/move
    if (isPathSafe(arr,x,y,n)){
        resultantArray[x][y] = 1; // Mar the current position in the res array

        // Move forward/right to check if a path is found
        if (ratInMaze(arr,x+1,y,n,resultantArray)){
            return true;
        }
        // Move downward to check if a path is found
        if (ratInMaze(arr,x,y+1,n,resultantArray)){
            return true;
        }
        // We are traversing back because no path was found
        // So, we update the path to [x][y] = 0
        resultantArray[x][y] = 0; // Back Tracking
        // If no path is found, it is invalid
        return false;
    }
    return false;
}
int main() {
    int n;
    cout << "Enter the value of n:" << endl;
    cin >> n;
    // Dynamically Allocate memory for the 2D Maze Array
    int ** arr = new int * [n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[n];
    }
    // Input the maze array values
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    // Dynamically allocate memory for the resultant array and assign 0 values
    int** resultantArray = new int*[n];
    for (int i = 0; i < n; ++i) {
        resultantArray[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            resultantArray[i][j] = 0;
        }
    }
    // Call the rat in maze function to find path in the maze
    if (ratInMaze(arr,0,0,n,resultantArray)){
        // Print the resultant array having the path in the maze for the rat
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << resultantArray[i][j] << " ";
            }
            cout << endl;
        }
    } else{
        cout << "No path for the rat in the maze exists....!!!" << endl;
    }
    // Deallocate the memory after use
    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
        delete[] resultantArray[i];
    }
    delete[] arr;
    delete[] resultantArray;
    return 0;
}
