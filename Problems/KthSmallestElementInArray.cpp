#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int kthSmallestElement(vector<int> arr, int k) {
    priority_queue<int> maxHeap; // Max-Heap

    for (int num : arr) {
        maxHeap.push(num);
        if (maxHeap.size() > k) {
            maxHeap.pop();  // Remove the largest element
        }
    }
    return maxHeap.top();
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << "Kth Smallest Element: " << kthSmallestElement(arr, k);
    return 0;
}
