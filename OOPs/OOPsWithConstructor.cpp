#include <iostream>
using namespace std;
class Employee {
public:
    // Attributes // Properties
    string Name;
    string emailID;
    double salary;
    string phoneNumber;
    // Constructor
    Employee(string name, string email, double s, string phone){
        Name = name;
        emailID = email;
        salary = s;
        phoneNumber = phone;
    }
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
    Employee e1("Anvitha","anvitha@gmail.com",30000,"1234567890");
    e1.employeeDetails();
    // Syntax 2: Classname obj = Classname();
    Employee e2 = Employee("Chaitanya","Chaitanya@gmail.com",30000,"9876543210");
    e2.employeeDetails();
    return 0;
}
