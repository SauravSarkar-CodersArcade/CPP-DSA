#include <iostream>
using namespace std;
void swapNumbers(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void reverseArrayBuiltIn(int arr[], int size){
    int s = 0;
    int e = size-1;
    while (s <= e){
        swap(arr[s], arr[e]);
        s++,
        e--;
    }
}
void reverseArrayUser(int arr[], int size){
    int s = 0;
    int e = size-1;
    while (s <= e){
        swapNumbers(&arr[s], &arr[e]);
        s++,
        e--;
    }
}
int main() {
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array: ";
    for (int x : arr){
        cout << x << " ";
    }
    cout << endl;
    cout << "Reversed Array: ";
    reverseArrayBuiltIn(arr, size);
    for (int x : arr){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
