#include <iostream>
using namespace std;
int findMax(const int arr[], int size){
    int max = arr[0];
    for (int i=1; i<size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
void countSort(int arr[], int size, int exp){
    int output[size];
    int count[10] = {0};
    for (int i=0; i<size; i++){
        count[(arr[i]/exp)%10]++; // (325 / exp) % 10 = 5 because exp = 1
    }
    // Cumulative count
    for (int i=1; i<10; i++){ // curr = curr + prev
        count[i] += count[i-1];
    }
    // Start from the end of the array
    for (int i = size-1; i >= 0; i--){
        output[--count[(arr[i]/exp)%10]]= arr[i];
    }
    // Copy the output back to the input array
    for (int i=0; i<size; i++){
        arr[i] = output[i];
    }
}
void radixSort(int arr[], int size){
    // Find the max
    int max = findMax(arr, size);
    for (int exp = 1; max / exp > 0; exp *= 10){
        countSort(arr, size, exp);
    }
}
int main() {
    int arr[] = {325,92,247,82,0,432,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, size);
    for (int x : arr){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
