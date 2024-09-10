#include <iostream>
using namespace std;
int missingElement(int arr[], int size){
    int s = 0;
    int e = size - 1;
    while (s <= e){
        int mid = s + (e-s)/2;
        if (arr[mid] != mid + 1){
            // Left Part
            if (mid == 0 || arr[mid-1] == mid){
                return mid + 1;
            }
            e = mid - 1;
        } else{
            // Right Part
            s = mid + 1;
        }
    }
    return size + 1;
}
int main() {
    int arr1[] = {1,2,3,5,6,7};
    int arr2[] = {1,2,3,4,5,6,7};
    cout << missingElement(arr1, 6) << endl; // 4
    cout << missingElement(arr2,7) << endl; // 8
    return 0;
}
