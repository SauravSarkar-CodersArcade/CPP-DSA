#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void kLargestElements(vector<int> arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-Heap

    for (int num : arr) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();  // Remove the smallest element
        }
    }

    // Print K largest elements
    cout << k << " Largest Elements: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
}

int main() {
    vector<int> arr = {20, 10, 60, 30, 50, 40};
    int k = 3;
    kLargestElements(arr, k);
    return 0;
}
