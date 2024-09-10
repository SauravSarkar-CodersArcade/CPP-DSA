#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> numbers = {1,2,3,4,5};
    for(int num : numbers){
        cout << num << " ";
    }
    cout << endl;
    for (int i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Initialisation with size
    vector<int> vector1(5); // Vector with n elements initialized to 0
    vector<int> vector2(5,10); // Vector with n elements initialized to 10

    // Initialisation from array
    int arr[] = {1,2,3};
    vector<int> vector3(arr, arr+3); // Initialise from array
    for(int num : vector3){
        cout << num << " ";
    }
    cout << endl;
    // Important functions in Vectors
    vector3.push_back(4);
    vector3.push_back(5);
    for(int num : vector3){
        cout << num << " ";
    }
    cout << endl;
    vector3.pop_back();
    for(int num : vector3){
        cout << num << " ";
    }
    cout << endl;
    cout << "Size of vector: " << vector3.size() << endl;
    cout << "Capacity of vector: " << vector3.capacity() << endl;
    vector3.resize(10); // Resizes to contain 10 elements
    vector3.resize(15,100); // Resizes to contain 15 elements, initialised to 100
    for(int num : vector3){
        cout << num << " ";
    }
    cout << endl;
//    vector3.clear();
//    for(int num : vector3){
//        cout << num << " ";
//    }
//    cout << endl;
    cout << vector3.empty() << endl;
    // Insert
    // position, value
    // position, count, value
    // position, first, last
    vector3.insert(vector3.begin(), 0); // Insert a 0 at the beginning
    vector3.insert(vector3.begin() + 1, 3,7);
    for(int num : vector3){
        cout << num << " ";
    }
    cout << endl;
    // Erase
    vector3.erase(vector3.begin()); // Removes the first element
    vector3.erase(vector3.begin(), vector3.begin() + 2); // First two elements removed
    for(int num : vector3){
        cout << num << " ";
    }
    cout << endl;
    // front & back references
    cout << "First element: " << vector3.front() << endl;
    cout << "Last element: " << vector3.back() << endl;
    // data() -> It returns a pointer to the underlying array ->
    // which points to the first element in the array
    int * p = vector3.data();
    cout << "First element: " << *p << endl;
    // Swap function
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {4,5,6};
    v1.swap(v2);
    for(int x : v1){
        cout << x << " ";
    }
    cout << endl;
    for(int x : v2){
        cout << x << " ";
    }
    cout << endl;
    // Assign new values to the vector
    // If less than original size elements are assigned, the new vector extra elements are null
    vector3.assign(10,1);
    for(int num : vector3){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
