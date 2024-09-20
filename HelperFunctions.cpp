#include <iostream>
#include <vector>
using namespace std;
int makeBeautiful(string str){
    int n = str.size();
    // Generate two target patterns
    string pattern1 = "", pattern2 = "";
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            pattern1 += '0';
            pattern2 += '1';
        } else {
            pattern1 += '1';
            pattern2 += '0';
        }
    }
    int m1 = 0, m2 = 0;
    for (int i=0; i<n; i++){
        if (str[i] != pattern1[i]){
            m1++;
        }
        if (str[i] != pattern2[i]){
            m2++;
        }
    }
    return min(m1,m2);
}
int solve(int n, int k){
    if (n == 1){
        return 0;
    }
    return (solve(n-1, k) + k) % n;
}
int josephus(int n, int k){
//    int lastPerson = solve(n, k) + 1;
//    return lastPerson;
    int lastPerson = 0;
    for (int i=2; i<=n; i++){
        lastPerson = (lastPerson + k) % i;
    }
    return lastPerson + 1;
}
void sumOfEvenOddDigits(int n){
    int evenSum = 0;
    int oddSum = 0;
    while (n > 0){
        int digit = n % 10;
        if (digit % 2 == 0){
            evenSum += digit;
        }else{
            oddSum += digit;
        }
        n = n / 10;
    }
    cout << evenSum << " " << oddSum << endl;
}

int findUnique(int * arr, int size){
    int unique = 0;
    for (int i=0; i<size; i++){
        unique ^= arr[i];
    }
    return unique;
}
bool checkPalindrome(string s){
    string cleaned;
    for (char c : s){
        if (isalnum(c)){
            cleaned += tolower(c);
        }
    }
    int left = 0;
    int right = cleaned.size() - 1;
    while (left < right){
        if (cleaned[left] != cleaned[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}




void reverseArray(vector<int> &arr , int m) {
    int s = m+1;
    int e = arr.size();
    while (s <= e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}
int sumOfMaxMin(int arr[], int n){
    // Write your code here.
    int mx = arr[0];
    int mn = arr[0];
    for (int i=1; i<n; i++){
        if (arr[i] > mx)
            mx = arr[i];
        if (arr[i] < mn)
            mn = arr[i];
    }
    int s = mx + mn;
    return s;
}
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    vector<int> ksl;
    sort(arr.begin(), arr.end());
    // k = 8 n = 4
    if (k-1 < arr.size()){
        ksl.push_back(arr[k-1]);
    }
    if (arr.size() - k >= 0){
        ksl.push_back(arr[arr.size()-k]);
    }
    return ksl;
}
void sort012(int *arr, int n)
{
    //   Write your code here
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;
    for (int i=0; i<n; i++){
        if (arr[i] == 0)
            c0++;
        else if (arr[i] == 1)
            c1++;
        else
            c2++;
    }
    int index = 0;
    while (c0 > 0){
        arr[index++] = 0;
        c0--;
    }
    while (c1 > 0){
        arr[index++] = 1;
        c1--;
    }
    while (c2 > 0){
        arr[index++] = 2;
        c2--;
    }
}
vector<int> separateNegativeAndPositive(vector<int> &nums){
    int index = 0;
    for (int i=0; i<nums.size(); i++){
        if (nums[i] < 0){
            swap(nums[i], nums[index]);
            index++;
        }
    }
    return nums;
}
int main() {
//    char ch;
//    cin >> ch;
//    // A -> 65 a = 97 32
//    // A - Z
//    // a - z
//    // -1
//    if (ch >= 'A' && ch <= 'Z'){
//        cout << 1 << endl;
//    }else if  (ch >= 'a' && ch <= 'z'){
//        cout << 0 << endl;
//    }else{
//        cout << -1 << endl;
//    }
    string str = "23";
    int number = str[0] - '0'; // Ascii values
    cout << number;
    return 0;
}
