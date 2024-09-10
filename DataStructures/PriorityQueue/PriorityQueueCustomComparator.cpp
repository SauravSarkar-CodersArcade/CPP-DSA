#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct CustomCompare {
    bool operator() (const int& lhs, const int& rhs){
        return lhs > rhs; // Ascending
        return lhs < rhs; // Descending
    }
};
int main() {
    priority_queue<int, vector<int>, CustomCompare> customHeap;
    customHeap.push(10);
    customHeap.push(20);
    customHeap.push(5);
    cout << "Custom Heap: ";
    while (!customHeap.empty()){
        cout << customHeap.top() << " ";
        customHeap.pop();
    }
    cout << endl;
    return 0;
}
