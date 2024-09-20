#include <iostream>
using namespace std;
template <typename T>
void user_swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}
void reverseString(string& str, int s, int e){
    // Base case : One character or start beyond end
    if (s >= e){
        return;
    }
    user_swap(str[s], str[e]);
    reverseString(str,s+1,e-1);

}
int main() {
    string str = "AYNAHTIAHC-AHTIVNA";
    reverseString(str,0,str.length()-1);
    cout << str << endl;
    return 0;
}
