#include <iostream>
using namespace std;
void countSort(int arr[], int size){
    // Max
    int k = arr[0];
    for(int i=1; i<size; i++){
        if (arr[i] > k)
            k = arr[i];
    }
    int * count = new int[k+1];
    for (int i = 0; i <=k; ++i) {
        count[i] = 0;
    }
    for (int i = 0; i < size; ++i) {
        count[arr[i]]++;
    }
    for (int i = 1; i <= k; ++i) {
        count[i] += count[i-1]; // curr = curr + prev
    }
    int output[size];
    // start from the end of the array // right side
    for (int i = size-1; i >= 0; --i) {
        output[--count[arr[i]]] = arr[i];
    }
    for (int i = 0; i < size; ++i) {
        arr[i] = output[i];
    }
}
int main() {
    int arr[] = {3,1,3,2,1,4,4,6,3};
    int size = sizeof (arr) / sizeof (arr[0]);
    countSort(arr,size);
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
