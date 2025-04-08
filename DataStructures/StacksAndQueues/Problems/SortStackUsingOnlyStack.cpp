#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int>& s) {
    stack<int> temp;
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        while (!temp.empty() && temp.top() > top) {
            s.push(temp.top());
            temp.pop();
        }
        temp.push(top);
    }
    s = temp;
}

int main() {
    stack<int> s;
    s.push(34);
    s.push(3);
    s.push(31);
    s.push(98);
    s.push(92);
    s.push(23);

    sortStack(s);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
