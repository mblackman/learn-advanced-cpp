#include <iostream>
#include <vector>
using namespace std;

class Test {
public:
    Test() {
        cout << "Ctor" << endl;
    }

    Test(int i) {
        cout << "Parameter ctor" << endl;
    }

    Test(const Test &other) {
        cout << "Copy constructor" << endl;
    }

    Test &operator=(const Test &other) {
        cout << "Assignment" << endl;
        return *this;
    }

    ~Test() {
        cout << "Destructor" << endl;
    }

    friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test) {
    out << "Hello from test";
    return out;
}

// C++ uses eliding to get rid of extra copies of an object. You'd expect this method to 
// invoke the copy ctor and assignment ctor in an outer scope, because we're returning a 
// Test by value instead of reference. C++ is able to get rid of copies.
Test getTest() {
    return Test();
}

int main() {

    Test test1 = getTest();

    cout << test1 << endl;

    vector<Test> vec;
    vec.push_back(Test());

    return 0;
}