#include <iostream>
#include <vector>
using namespace std;
// Min Heap
class PriorityQueue {
public:
    vector<int> heap;
    void heapifyUp(int index){
        if (index == 0){
            return;
        }
        int parent = (index - 1)/2;
        if (heap[index] < heap[parent]){
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }
    void heapifyDown(int index){
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;
        if (leftChild < heap.size() && heap[leftChild] < heap[smallest]){
            smallest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] < heap[smallest]){
            smallest = rightChild;
        }
        if (smallest != index){
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }
public:
    void push(int val){
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }
    void pop(){
        if (heap.size() == 0){
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
    int top(){
        if (heap.size() == 0) {
            throw out_of_range("Heap Is Empty");
        }
            return heap[0];
    }
    bool empty(){
        return heap.size() == 0;
    }
};
int main() {
    PriorityQueue priorityQueue;
    priorityQueue.push(10);
    priorityQueue.push(15);
    priorityQueue.push(20);
    priorityQueue.push(17);
    priorityQueue.push(8);
    cout << "Top Element: " << priorityQueue.top() << endl;
    priorityQueue.pop();
    cout << "Top Element: " << priorityQueue.top() << endl;
    return 0;
}
