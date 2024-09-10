#include <iostream>
#include <cmath>
using namespace std;
bool armstrongNumber(int n){
    int original = n;
    int noOfDigits = 0;
    int temp = 0;
    while (n > 0){
        noOfDigits++;
        n = n / 10;
    }
    n = original;
    while (n > 0){
        int digit = n % 10;
        temp = temp + pow(digit, noOfDigits);
        n = n / 10;
    }
    if (original == temp){
        return true;
    }else {
        return false;
    }
}
int main() {
    cout << armstrongNumber(153);
    return 0;
}
