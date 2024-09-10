#include <iostream>
using namespace std;
template <typename T>
T findMax(T arr[], int n){
    T mx = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}
int main() {
    int intArr[] = {1,2,3,4,5};
    cout << findMax(intArr, 5) << endl;
    float floatArr[] = {1.3f,2.5f,3.5f,4.2f,5.1f};
    cout << findMax(floatArr, 5) << endl;
    double doubleArr[] = {1.3,2.5,3.5,4.2,5.9};
    cout << findMax(doubleArr, 5) << endl;
    return 0;
}
