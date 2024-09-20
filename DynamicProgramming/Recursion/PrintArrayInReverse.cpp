#include <iostream>
using namespace std;
void printReverseArray(int arr[], int size){
    // Base case
    if (size == 0){
        return;
    }
    cout << arr[size-1] << " ";
    printReverseArray(arr,size-1);
}
int main() {
    int arr[] = {1,2,3,4,5,6,7,8};
    int size = sizeof(arr) / sizeof (arr[0]);
    cout << "Reversed Array: ";
    printReverseArray(arr,size);
    return 0;
}
