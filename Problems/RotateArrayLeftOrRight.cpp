#include <iostream>
using namespace std;
void rotateArrayLeft(int * arr, int n, int k){
    // Normalize
    k = k % n;
    int * rotatedArray = new int[n];
    for (int i=0; i<n; i++){
        rotatedArray[(i+k)%n] = arr[i];
    }
    for (int i=0; i<n; i++){
        arr[i] = rotatedArray[i];
    }
}
void rotateArrayRight(int arr[], int n, int k){
    // Normalize
    k = k % n;
    int * rotatedArray = new int[n];
    for (int i=0; i<n; i++){
        rotatedArray[i] = arr[(i+k)%n];
    }
    for (int i=0; i<n; i++){
        arr[i] = rotatedArray[i];
    }
}
int main() {
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cin >> k;
    rotateArrayRight(arr,n, k);
    for (int x : arr){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
