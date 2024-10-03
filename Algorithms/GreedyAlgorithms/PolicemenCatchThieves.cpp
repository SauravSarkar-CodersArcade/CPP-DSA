#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int maxThievesCaught(vector<char>& arr, int n, int k){
    deque<int> police, thief;
    int result = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 'P'){
            police.push_back(i);
        }else if (arr[i] == 'T'){
            thief.push_back(i);
        }
        while (!police.empty() && !thief.empty()){
            if (abs(police.front() - thief.front()) <= k){
                result++;
                police.pop_front();
                thief.pop_front();
            } else if (police.front() < thief.front()){
                police.pop_front();
            } else{
                thief.pop_front();
            }
        }
    }
    return result;
}
int main() {
    vector<char> arr = {'T', 'T', 'P', 'P', 'T', 'P'};
    int k = 2;
    int n = arr.size();
    cout << "Max Thieves Caught: " << maxThievesCaught(arr,n,k) << endl;
    return 0;
}
