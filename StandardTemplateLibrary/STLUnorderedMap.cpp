#include <iostream>
#include <unordered_map> // Hashing Order // HashTable // Java
using namespace std;
int main() {
    unordered_map<string, string> stateLanguages;
    stateLanguages.insert(pair<string, string>("Karnataka", "Kannada"));
    stateLanguages.insert(pair<string, string>("Kerala", "Malayalam"));
    stateLanguages.insert(pair<string, string>("Bihar", "Bhojpuri"));
    stateLanguages.insert(pair<string, string>("West Bengal", "Bengali"));
    stateLanguages.insert(pair<string, string>("Assam", "Assamese"));
    stateLanguages.insert(pair<string, string>("Maharashtra", "Marathi"));
    // Insert a new data <K,V>
    // map_name["Key"] = "Value";
    stateLanguages["Goa"] = "Konkani";
    // Clearing all the data
    // stateLanguages.clear();
    // Erasing a particular <K,V> pair.
    stateLanguages.erase("Goa");
    // Traversal Of the Map
    for (auto pair : stateLanguages) {
        cout << "State: " << pair.first << " <-> Language: " <<
             pair.second << endl;
    }
    return 0;
}
