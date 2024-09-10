#include <iostream>
#include <stack>
using namespace std;
void printStackElements(stack<int> s){
    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main() {
    // push, pop, size, empty, top
    stack<int> numbers;
    numbers.push(1);
    numbers.push(2);
    numbers.push(3);
    numbers.push(4);
    numbers.push(5);
    cout << "Top element: " << numbers.top() << endl;
    numbers.pop();
    cout << "Top element: " << numbers.top() << endl;
    printStackElements(numbers);
    return 0;
}
