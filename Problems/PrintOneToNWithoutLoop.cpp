#include <iostream>
#include <vector>
using namespace std;
void helperFunction(int x, vector<int>& ans){
    if (x == 0) return;
    helperFunction(x-1, ans);
    ans.push_back(x);
}
vector<int> printNos(int x) {
    // Write Your Code Here
    vector<int> ans;
    helperFunction(x, ans);
    return ans;
}
int main() {
    vector<int> ans;
    ans = printNos(10);
    for (int x : ans){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
