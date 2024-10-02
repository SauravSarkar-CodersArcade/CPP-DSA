#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> calories(n);
    for (int i = 0; i < n; ++i) {
        cin >> calories[i];
    }
    // Sort in descending order
    sort(calories.begin(), calories.end(), greater<int>());
    long long total_miles = 0;

    for (int i = 0; i < n; ++i) {
        total_miles += pow(2,i) * calories[i]; // 2 ^ i * calories;
    }
    cout << total_miles << " miles." << endl;
    return 0;
}
