#include <iostream>
using namespace std;
int lowerBound(int arr[], int n, int target){
    int s = 0;
    int e = n-1;
    int result = -1;
    while (s <= e){
        int mid = s + (e-s)/2;
        if (arr[mid] >= target){
            result = mid; // Probable answer
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    return result;
}
int upperBound(int arr[], int n, int target){
    int s = 0;
    int e = n-1;
    int result = -1;
    while (s <= e){
        int mid = s + (e-s)/2;
        if (arr[mid] <= target){
            result = mid; // Probable answer
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return result;
}
int main() {
    int arr[] = {2,4,10,19,23,45,87};
    int n = sizeof(arr) / sizeof(arr[0]);
    int lowerBoundIndex = lowerBound(arr, n, 20);
    cout << "The lower bound element is: " << arr[lowerBoundIndex] << endl;
    int upperBoundIndex = upperBound(arr,n,20);
    cout << "The upper bound element is: " << arr[upperBoundIndex] << endl;
    return 0;
}
