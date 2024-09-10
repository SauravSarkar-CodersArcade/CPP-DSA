#include <iostream>
using namespace std;
void insertionSortWhileLoop(int arr[], int n){
    for (int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i-1;
        while (arr[j] > temp && j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i-1;
        for (; j >= 0; j--){
            if (arr[j] > temp){
                // Shift operation
                arr[j+1] = arr[j];
            } else{ // Stop
                break;
            }
        }
        arr[j+1] = temp; // Update the temp to check for the next index
    }
}
int main() {
    int arr[] = {5,1,3,9,6,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSortWhileLoop(arr, n);
    for (int x : arr){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
