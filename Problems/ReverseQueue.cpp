#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void printQueueElements(queue<int> q){
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
queue<int >reverseQueue(queue<int>& q){
    stack<int> s;
    while (!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }
    while (!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
}
int main() {
    // front, back, push, pop, size, empty
    queue<int> numbers;
    numbers.push(1);
    numbers.push(11);
    numbers.push(12);
    numbers.push(21);
    numbers.push(31);
    numbers.push(13);
    cout << "Original PriorityQueue: ";
    printQueueElements(numbers);
    reverseQueue(numbers);
    cout << "Reverse PriorityQueue: ";
    printQueueElements(numbers);
    return 0;
}
