#include <iostream>
#include <map>
using namespace std;

int main() {
    
    multimap<int, string> lookup;

    lookup.insert(make_pair(30, "Bob"));
    lookup.insert(make_pair(30, "Stewart"));
    lookup.insert(make_pair(31, "Kevin"));

    for (multimap<int, string>::iterator it=lookup.begin(); it!=lookup.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << "Find Test" << endl;

    for (multimap<int, string>::iterator it=lookup.find(30); it != lookup.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << "Find Filter" << endl;

    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);

    for (multimap<int, string>::iterator it=its.first; it!=its.second; it++) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << "Find Filter with C++11 help" << endl;

    auto its2 = lookup.equal_range(30);

    for (multimap<int, string>::iterator it=its2.first; it!=its2.second; it++) {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}