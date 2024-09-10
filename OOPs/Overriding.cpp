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
    virtual void work(){
        cout << Name << " attends meetings, makes presentations, checks emails, etc." << endl;
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
    void work() override{
        cout << Name << " conducts lectures on " << Subject << " at " << College << " College." << endl;
    }
};
class SoftwareDeveloper : public Employee {
public:
    string FavProLang;
    string Domain;
    SoftwareDeveloper
    (string name, string email, double s, string phone, string favProLang, string domain)
    : Employee(name, email, s, phone){
        FavProLang = favProLang;
        Domain = domain;
    }
    void work() override{
        cout << Name << " makes " << Domain << " Applications using " << FavProLang << endl;
    }
};
int main() {
    Employee e1("Sachin", "sachu@gmail.com", 45000, "7654389723");
    Lecturer l1("Ramya", "ramya@gmail.com", 30000, "1234567890",
                "Mathematics", "DBIT");
    SoftwareDeveloper s1("Sahana", "sahana@gmail.com", 40000, "9876543210",
                         "Python", "AI");
    e1.employeeDetails();
    e1.work();
    l1.employeeDetails();
    l1.work();
    s1.employeeDetails();
    s1.work();
    return 0;
}
