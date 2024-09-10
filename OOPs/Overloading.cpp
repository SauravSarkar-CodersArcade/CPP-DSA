#include <iostream>
using namespace std;
class Overloading { // Same Class
public:
    // Changing the number of parameters or the return type of the parameters
    static void add(int a, int b){
        cout << a+b << endl;
    }
    static void add(int a, int b, int c){
        cout << a+b+c << endl;
    }
    static void add(double a, float b){
        cout << a+b << endl;
    }
};
int main() {
    Overloading::add(1,2);
    Overloading::add(1,2,3);
    Overloading::add(1.23,2.5f);
    return 0;
}
