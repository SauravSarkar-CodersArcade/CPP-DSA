#include <iostream>
#include <list> // Doubly Linked List
using namespace std;
int main() {
    list<int> lst1; // Default Constructor
    list<int> lst2(3,10); // 10 10 10
    list<int> lst3(lst2); // Copy constructor -> 10 10 10
    lst1.push_back(10);
    lst1.push_front(20);
    lst1.insert(++lst1.begin(), 15);
    for (auto x : lst1) {
        cout << x << " ";
    }
    cout << endl;
    // Removing last & first
//    lst1.pop_back();
//    lst1.pop_front();
    // Store last & first
//    int last = lst1.back();
//    int first = lst1.front();
    // Traversals
    for (list<int>::iterator it = lst1.begin(); it != lst1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    for (auto it = lst1.begin(); it != lst1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    for (int & it : lst1) {
        cout << it << " ";
    }
    cout << endl;
    // Backward Traversal =? We use the rbegin() & rend() functions
    for (auto it = lst1.rbegin(); it != lst1.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
