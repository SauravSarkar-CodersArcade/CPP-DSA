#include <iostream>

void findTwoUniqueNumbers(int arr[], int n) {
    int xorAll = 0;

    // Step 1: XOR all elements to get xorAll = a ^ b
    for (int i = 0; i < n; i++) {
        xorAll ^= arr[i];
    }

    // Step 2: Find the rightmost set bit in xorAll
    int rightmostSetBit = xorAll & -xorAll;

    // Step 3: Divide numbers into two groups and find unique numbers
    int num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] & rightmostSetBit) {
            num1 ^= arr[i];  // Group where bit is 1
        } else {
            num2 ^= arr[i];  // Group where bit is 0
        }
    }

    // Step 4: Output the two unique numbers
    std::cout << "The two non-repeating elements are: " << num1 << " and " << num2 << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    findTwoUniqueNumbers(arr, n);

    return 0;
}
