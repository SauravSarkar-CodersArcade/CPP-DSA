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
class Lecturer : public Employee {
public:
    string Subject;
    string College;
    Lecturer(string name, string email, double s, string phone, string sub, string college)
    : Employee(name, email, s, phone){
        Subject = sub;
        College = college;
    }
};
int main() {
    Lecturer l1("Ramya", "ramya@gmail.com", 30000, "1234567890",
                "Java", "DBIT");
    l1.employeeDetails();
    return 0;
}
