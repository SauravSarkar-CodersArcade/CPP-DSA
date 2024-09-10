#include <iostream>
#include <unordered_set> // Hashing
using namespace std;
int main() {
    // Create a set of integers
    unordered_set<int> s;
    s.insert(5);
    s.insert(15);
    s.insert(51);
    s.insert(25);
    s.insert(53);
    s.insert(5); // Duplicate, will not be added, ignored.
    // Display
    cout << "Elements in the unordered_set: ";
    for(int x : s){
        cout << x << " ";
    }
    cout << endl;
    // Search an element
    int searchElement = 531;
    auto it = s.find(searchElement);
    if (it != s.end()){
        cout << "Element " << searchElement << " found." << endl;
    } else{
        cout << "Element " << searchElement << " not found." << endl;
    }
    // Removing an element
    s.erase(15);
    cout << "Elements in the unordered_set after removing 15: ";
    for(int x : s){
        cout << x << " ";
    }
    cout << endl;
    // Size
    cout << "Size of the unordered_set is: " << s.size() << endl;
    return 0;
}
