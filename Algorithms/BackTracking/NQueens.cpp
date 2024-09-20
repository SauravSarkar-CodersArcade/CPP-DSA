#include <bits/stdc++.h>
using namespace std; // Q = 1 Unplaced = 0
void addSolution
(vector<vector<int>> &ans, vector<vector<int>>&board, int n){
    vector<int> temp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp); // Each row is added to the 2D array
}
bool isSafe(int row, int col, vector<vector<int>>& board, int n){
    int x = row;
    int y = col;
    // Check in the same row
    while (y >= 0){
        if (board[x][y] == 1){
            return false;
        }
        y--;
    }
    // Check for the upper back diagonal
    x = row;
    y = col;
    while (x>=0 && y>=0){
        if (board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }
    // Check for the lower back diagonal
    x = row;
    y = col;
    while (x<n && y>=0){
        if (board[x][y] == 1){
            return false;
        }
        x++;
        y--;
    }
    return true;
}
void solve
(int col, vector<vector<int>>&ans, vector<vector<int>>&board, int n){
    // Base case : Suppose we have already reached the last column
    if (col == n){
        addSolution(ans, board, n);
        return;
    }
    // Solve one case, the rest will be taken care by recursion
    for (int row = 0; row < n; ++row) {
        if (isSafe(row,col,board,n)){
            board[row][col] = 1;
            // Go to the next column
            solve(col+1, ans,board,n);
            // Couldn't solve track back
            board[row][col] = 0; // Backtracking
        }
    }
}
vector<vector<int>> nQueens(int n){
    vector<vector<int>> board(n, vector<int>(n,0));
    vector<vector<int>> ans;
    solve(0,ans,board,n);
    return ans;
}
int main() {
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        int n;
        cin >> n;  // Input size of the chessboard (N)

        vector<vector<int>> solutions = nQueens(n);  // Solve the N-Queens problem

        // If no solutions exist, print -1
        if (solutions.empty()) {
            cout << -1 << endl;
        } else {
            // Print each solution as an n x n matrix
            for (int sol = 0; sol < solutions.size(); sol++) {
                cout << "Solution " << sol + 1 << ":" << endl;

                // Each solution is represented as a 1D vector of size n * n
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        // Print 1 or 0 based on the solution vector
                        cout << solutions[sol][i * n + j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;  // Separate different solutions by an empty line
            }
        }
    }
    return 0;
}
