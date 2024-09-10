#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int key){
    int s = 0;
    int e = n-1;
    int mid = (s+e)/2;
    while (s <= e){
        if (arr[mid] == key){
            return mid;
        }else if (arr[mid] < key){
            s = mid + 1;
        }else{
            e = mid -1;
        }
        mid = (s+e)/2;
    }
    return -1;
}
int main() {
    int arr[] = {0,1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    cout << "Enter the target value:\n";
    cin >> target;
    int index = binarySearch(arr, n,target);
    if (index != -1){
        cout << target << " is found at index " << index << endl;
    }else{
        cout << target << " was not found in the array." << endl;
    }
    return 0;
}
