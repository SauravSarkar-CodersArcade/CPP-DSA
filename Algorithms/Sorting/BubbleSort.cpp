#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n){
    // Number of iterations : 1 to n-1
    for (int i=1; i<n; i++){
        for (int j=0; j<n-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
int main() {
    int arr[] = {5,1,3,9,6,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    for (int x : arr){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
