#include <bits/stdc++.h>
using namespace std;
int fibonacciMemo(int n, vector<int>& dp){
    if (n == 0 || n == 1){
        return n;
    }
    // Step 3: If you have the answer, don't do it again, return
    if (dp[n] != -1){
        return dp[n];
    }
    // Step 2: Store the values into the dp array
    dp[n] = fibonacciMemo(n - 1, dp) + fibonacciMemo(n - 2, dp);
    return dp[n];
}
int main() {
    int n;
    cin >> n;
    // Step 1 : Create a dp array and initialize it to -1
    vector<int> dp(n+1, -1);
    cout << fibonacciMemo(n, dp) << endl;
    return 0;
}
