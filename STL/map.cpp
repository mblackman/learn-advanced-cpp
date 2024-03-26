#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> ages;
    
    ages["Mike"] = 40;
    ages["Raj"] = 20;
    ages["Viki"] = 30;

    pair<string, int> addToMap("George", 55);
    ages.insert(addToMap);
    ages.insert(make_pair("Peter", 70)); // This is a nice shorthand to create a typed pair.

    cout << ages["Raj"] << endl;

    if (ages.find("Viki") != ages.end()) {
        cout << "Found Viki" << endl;
    }
    else {
        cout << "Key not found" << endl;
    }

    for (map<string, int>::iterator it=ages.begin(); it!=ages.end(); it++) {
        pair<string, int> age = *it;
        cout << "Name: " << age.first << ": " << age.second << endl;
    }

    for (map<string, int>::iterator it=ages.begin(); it!=ages.end(); it++) {
        cout << "Name: " << it->first << ": " << it->second << endl;
    }

    return 0;
}