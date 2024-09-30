#include <iostream>
using namespace std;
class CodersArcade {
    double d; // 8
    int i; // 4
    short s; // 2
    char c; // 1
};
int main() {
    CodersArcade obj;
    cout << "Size of the class: " << sizeof(obj) << " Bytes." << endl;
    return 0;
}
