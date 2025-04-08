#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    stack<int> st;
    vector<int> res(nums.size(), -1);

    for (int i = nums.size() - 1; i >= 0; --i) {
        while (!st.empty() && st.top() <= nums[i])
            st.pop();
        if (!st.empty()) res[i] = st.top();
        st.push(nums[i]);
    }
    return res;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> result = nextGreaterElement(arr);
    for (int x : result) cout << x << " ";
    return 0;
}
