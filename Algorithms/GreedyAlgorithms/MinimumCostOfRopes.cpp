#include <bits/stdc++.h>
using namespace std;
class Solution {
    long long minCost(vector<long long> &arr) {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < arr.size(); ++i) {
            pq.push(arr[i]);
        }
        long long cost = 0;
        while (pq.size() > 1){
            long long first = pq.top();
            pq.pop();

            long long second = pq.top();
            pq.pop();

            long long mergedLength = first + second;
            cost += mergedLength;
            pq.push(mergedLength);
        }
        return cost;
    }
};