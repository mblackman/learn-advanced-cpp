#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    vector<string> strings(5);

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");

    strings[3] = "dog";

    vector<string>::iterator it = strings.begin();

    for (; it != strings.end(); it++) {
        cout << *it << endl;
    }

    it = strings.end();

    for (; it != strings.begin(); it--) {
        cout << *it << endl;
    }

    return 0;
}