#include <iostream>
using namespace std;
class Employee {
    string Name;
    int Age;
    string Company;
public:
    // Setters
    void setName(string name){
        Name = name;
    }
    void setAge(int age){
        Age = age;
    }
    void setCompany(string company){
        Company = company;
    };
    // Getters - Fetchers
    string getName(){
        return Name;
    }
    int getAge(){
        return Age;
    }
    string getCompany(){
        return Company;
    }
};
int main() {
    Employee e1;
    // Setters
    e1.setName("Anvitha");
    e1.setAge(21);
    e1.setCompany("Wipro");
    // Getters
    cout << "Name: " << e1.getName() << endl;
    cout << "Age: " << e1.getAge() << endl;
    cout << "Company: " << e1.getCompany() << endl;
    return 0;
}
