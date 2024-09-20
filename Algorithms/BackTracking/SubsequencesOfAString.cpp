#include <bits/stdc++.h>
using namespace std;
void solve(string str, string output, int index, vector<string>& ans){
    // Base case
    // This is if we are considering empty string as well
//    if (index >= str.length()){
//        ans.push_back(output);
//        return;
//    }
    // This is if we are not considering the empty string
    if (index >= str.length()){
        if (output.length() > 0) {
            ans.push_back(output);
        }
        return;
    }
    // Exclude case
    solve(str,output,index+1,ans);
    // Include case
    char element = str[index];
    output.push_back(element);
    solve(str,output,index+1,ans);
}
vector<string> subsequences(string str){
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, output, index, ans);
    return ans;
}
int main() {
    return 0;
}
