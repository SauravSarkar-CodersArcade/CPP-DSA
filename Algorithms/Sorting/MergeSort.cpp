#include <iostream>
using namespace std;
void merge(int * arr, int s, int e){
    int mid = s + (e-s)/2;
    int l1 = mid - s + 1;
    int l2 = e - mid;
    // Create two arrays for copying the contents of left and right
    // parts of the array
    int * first = new int[l1];
    int * second = new int[l2];
    int k = s;
    for (int i=0; i<l1; i++){
        first[i] = arr[k++];
    }
    k = mid + 1;
    for (int i=0; i<l2; i++){
        second[i] = arr[k++];
    }
    int i = 0;
    int j = 0;
    k = s;
    while (i < l1 && j < l2){
        if (first[i] < second[j]){
            arr[k++] = first[i++];
        }else{
            arr[k++] = second[j++];
        }
    }
    // Remaining elements if any
    // First part
    while (i < l1){
        arr[k++] = first[i++];
    }
    // Second part
    while (j < l2){
        arr[k++] = second[j++];
    }
    // Delete the resources
    delete []first;
    delete []second;
}
void mergeSort(int * arr, int s, int e){
    // Base case
    if (s >= e){
        return;
    }
    int mid = s + (e-s)/2;
    // left part
    mergeSort(arr, s, mid);
    // right part
    mergeSort(arr, mid+1, e);
    // Merge both the parts
    merge(arr, s, e);
}
int main() {
    int arr[] = {2,9,8,6,4,1,3,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size-1);
    for (int x : arr){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
