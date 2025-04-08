#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int findCelebrity(vector<vector<int>>& M, int n) {
    stack<int> st;

    // Step 1: Push everyone onto the stack
    for (int i = 0; i < n; ++i)
        st.push(i);

    // Step 2: Eliminate non-celebrities
    while (st.size() > 1) {
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();

        // If a knows b, then a can't be celebrity
        if (M[a][b] == 1)
            st.push(b);
        else
            st.push(a);
    }

    int candidate = st.top();

    // Step 3: Verify the candidate
    for (int i = 0; i < n; ++i) {
        if (i != candidate && (M[candidate][i] == 1 || M[i][candidate] == 0))
            return -1;
    }

    return candidate;
}

int main() {
    vector<vector<int>> M = {
            {0, 1, 1},
            {0, 0, 1},
            {0, 0, 0}
    };

    int celeb = findCelebrity(M, M.size());
    if (celeb == -1)
        cout << "No Celebrity\n";
    else
        cout << "Celebrity ID: " << celeb << "\n";

    return 0;
}
