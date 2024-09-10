#include <bits/stdc++.h>
#include <iostream>
#include <forward_list> // No insertions allowed at end/tail
using namespace std;

int main() {
    forward_list<int> fList = {10,20,30};
    // Adding elements to the front
    fList.push_front(5);
    fList.push_front(0);
    // Traversal 1 -> for each loop
    for (int x : fList) {
        cout << x << " ";
    }
    cout << endl;
    // Traversal 2 -> iterator
    for (auto it = fList.begin(); it != fList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    // Traversal 3 -> range based for loop
    for (int & it : fList) {
        cout << it << " ";
    }
    cout << endl;
    // Traversal using a normal loop
    for (forward_list<int>::iterator it = fList.begin(); it != fList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    // Traversal 5 -> for each loop
    for (auto x : fList) {
        cout << x << " ";
    }
    cout << endl;
    // It is not allowed to insert element at end / tail.
    // How do we do it manually?
    // By traversing till the end
    auto it = fList.begin();
    while (next(it) != fList.end()){
       ++it;
    }
    fList.insert_after(it, 50);
    fList.insert_after(it, 40);
    for (auto x : fList) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
