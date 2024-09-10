#include <iostream>
using namespace std;
class Address {
public:
    int pinCode;
    string City;
    string state;
    string Country;
    Address(int p, string city, string s, string country){
        pinCode = p;
        City = city;
        state = s;
        Country = country;
    }
};
class Student {
const string college = "DBIT";
public:
    string name;
    int age;
    string email;
    Address address;
    Student(string n, int a, string e, Address add) : address(add), {
        name = n;
        age = a;
        email = e;
        address = add;
    }
    void studentDetails(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Email: " << email << endl;
        cout << "College: " << college << endl;
        cout << "State: " << address.state << endl;
        cout << "PinCode: " << address.pinCode << endl;
        cout << "City: " << address.City << endl;
        cout << "Country: " << address.Country << endl;
    }
};
int main(){
    Address address(560098,"Bangalore","Karnataka","India");
    Student s("Sahana", 23, "sahana@gmail.com", address);
    s.studentDetails();
    return 0;
}
