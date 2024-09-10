#include <iostream>
using namespace std;
class Employee {
public:
    // Attributes // Properties
    string Name;
    string emailID;
    double salary;
    string phoneNumber;
    // Method -> It describes the behaviour of an object
    void employeeDetails(){
        cout << "Name: " << Name << endl;
        cout << "Email: " << emailID << endl;
        cout << "Salary: Rs." << salary << endl;
        cout << "Phone Number: " << phoneNumber << endl;
    }

};

int main() {
    // Creating objects / instances of a class
    // Syntax 1: Classname obj;
    Employee e1;
    e1.Name = "Anvitha";
    e1.emailID = "anvitha@gmail.com";
    e1.salary = 30000;
    e1.phoneNumber = "1234567890";

    e1.employeeDetails();
    // Syntax 2: Classname obj = Classname();
    Employee e2 = Employee();
    e2.Name = "Chaitanya";
    e2.emailID = "Chaitanya@gmail.com";
    e2.salary = 30000;
    e2.phoneNumber = "9876543210";

    e2.employeeDetails();
    return 0;
}
