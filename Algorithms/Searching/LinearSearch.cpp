#include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int target){
    for (int i=0; i<n; i++){
        if (arr[i] == target){
            return i;
        }
    }
    return -1;
}
int main() {
    int arr[] = {-5,1,0,2,4,6,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    cout << "Enter the target value:\n";
    cin >> target;
    int index = linearSearch(arr, n,target);
    if (index != -1){
        cout << target << " is found at index " << index << endl;
    }else{
        cout << target << " was not found in the array." << endl;
    }
    return 0;
}
