#include <iostream>
#include <vector>
using namespace std;
class Person {
public:
    string Name;
    int Age;
    Person(string name, int age){
        Name = name;
        Age = age;
    }
};
int main() {
    vector<Person> people;
    people.push_back(Person("Ashank", 27)); // Just a copy & no type // Extra Memory
    people.emplace_back("Saurav",36); // In place object with type -> Person

    for(auto person : people){
        cout << person.Name << " is " << person.Age << " years old." << endl;
    }
    return 0;
}
