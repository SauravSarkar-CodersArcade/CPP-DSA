#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static string largestNumber(vector<int>& nums){
        // Convert the integers to strings for custom sorting
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }
        // Custom sort
        sort(strNums.begin(), strNums.end(), [](string &a, string &b){
            return a+b > b+a;
        });
        // After sorting, the largest number is "0", return "0"
        if (strNums[0] == "0") return "0";
        string result;
        for (string &s : strNums){
            result += s;
        }
        return result;
    }
};
int main() {
    vector<int> nums = {10,2};
    cout << Solution::largestNumber(nums) << endl;
    return 0;
}
