#include <iostream>
using namespace std;
void countSort(int arr[], int size){
    // Step 1 : Find the max
    int k = arr[0];
    for (int i=1; i<size; i++){
        if (arr[i] > k){
            k = arr[i];
        }
    }
    // Count array of size = (k+1) elements
    int * count = new int[k+1];
    // Assign 0 to all the elements of the count array
    for (int i=0; i<k+1; i++){
        count[i] = 0;
    }
    // Count the occurrences of each element in the array
    for (int i=0; i<size; i++){
        count[arr[i]]++;
    }
    // Calculate the cumulative count of the array : curr = curr + prev
    for (int i=1; i<=k; i++){
        count[i] += count[i-1];
    }
    // Create the output array same size as the input array
    int output[size];
    // Start from R->L or end of the array
    for (int i=size-1; i>=0; i--){
        output[--count[arr[i]]] = arr[i];
    }
    // Copy output back to input
    for (int i=0; i<size; i++){
        arr[i] = output[i];
    }
}
int main() {
    int arr[] = {1,3,2,3,4,1,6,4,3};
    int size = sizeof(arr) / sizeof(arr[0]);
    countSort(arr, size);
    for (int x : arr){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
