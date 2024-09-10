#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // Deletion or Removal Complexity -> O(1)
    // Max heap
    priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(5);
    maxHeap.push(29);
    cout << "Max Heap: ";
    while (!maxHeap.empty()){
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;
    // Min Heap using greater<int>
    // greater<int> actually reverses the priority
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(5);
    minHeap.push(29);
    cout << "Min Heap: ";
    while (!minHeap.empty()){
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
    return 0;
}
