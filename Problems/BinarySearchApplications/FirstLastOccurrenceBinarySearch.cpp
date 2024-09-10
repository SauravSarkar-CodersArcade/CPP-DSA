#include <iostream>
using namespace std;
int firstOccurrence(int arr[], int n, int key){
    int s = 0;
    int e = n-1;
    int ans = -1;
    while (s <= e){
        int mid = s + (e-s)/2;
        if (arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }else if (arr[mid] < key){
            s = mid + 1;
        }else {
            e = mid - 1;
        }
    }
    return ans;
}
int lastOccurrence(int arr[], int n, int key){
    int s = 0;
    int e = n-1;
    int ans = -1;
    while (s <= e){
        int mid = s + (e-s)/2;
        if (arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }else if (arr[mid] < key){
            s = mid + 1;
        }else {
            e = mid - 1;
        }
    }
    return ans;
}
int totalOccurrences(int arr[], int n, int key){
    int fo = firstOccurrence(arr,n,key);
    int lo = lastOccurrence(arr,n,key);
    int totalOccurrences = lo - fo + 1;
    return totalOccurrences;
}
int main() {
    int arr[] = {1,2,3,3,3,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int fo = firstOccurrence(arr,n,3); // 2
    int lo = lastOccurrence(arr,n,3); // 5
    cout << "First Occurrence: " << fo << endl;
    cout << "Last Occurrence: " << lo << endl;
    int totalOcc = totalOccurrences(arr,n, 3);
    cout << "Total Occurrences: " << totalOcc << endl;
    return 0;
}
