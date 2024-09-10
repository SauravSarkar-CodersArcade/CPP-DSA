#include <iostream>
using namespace std;
int recursive_binary_search(int * arr, int n, int s, int e, int key){
    if (s <= e){
        int mid = s + (e-s)/2;
        if (arr[mid] == key){
            return mid;
        }else if (arr[mid] > key){
            return recursive_binary_search(arr,n,s,mid-1,key);
        }else{
            return recursive_binary_search(arr,n,mid+1,e,key);
        }
    }
    return -1;
}
int main() {
//    cout << INT_MAX + 1 << endl; // INT_MIN
//    cout << INT_MIN - 1 << endl; // INT_MAX
    int arr[] = {0,1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    cout << "Enter the target value:\n";
    cin >> target;
    int index = recursive_binary_search(arr, n,0,n-1,target);
    if (index != -1){
        cout << target << " is found at index " << index << endl;
    }else{
        cout << target << " was not found in the array." << endl;
    }
    return 0;
}
