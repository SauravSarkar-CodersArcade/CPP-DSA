#include <iostream>
using namespace std;
class CodersArcade {
    double d;
    int i;
    char c;
    short s;
};
int main() {
    CodersArcade ca;
    cout << "Size of the class: " << sizeof(ca) << " Bytes." << endl;
    return 0;
}
