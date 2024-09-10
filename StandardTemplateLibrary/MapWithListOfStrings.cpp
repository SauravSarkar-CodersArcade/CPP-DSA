#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;
int main() {
    map<string, list<string>> studentFavFood;
    list<string> Anvitha {"dose", "idli", "pizza"};
    list<string> Chaithanya {"rava idli", "paddu", "benne dose"};
    list<string> Sahana {"bread jam", "sandwich", "oats"};
    studentFavFood.insert(
            pair<string, list<string>>("Anvitha", Anvitha));
    studentFavFood.insert(
            pair<string, list<string>>("Chaithanya", Chaithanya));
    studentFavFood.insert(
            pair<string, list<string>>("Sahana", Sahana));
    // Traverse the map
    for(auto pair : studentFavFood){
        // This is for the first element in the pair
        cout << "Name: " << pair.first << " <--> Food: ";
        // This is for the second element(list) in the pair
        for (auto food : pair.second) {
            cout << food << ",";
        }
        cout << endl;
    }
    return 0;
}
