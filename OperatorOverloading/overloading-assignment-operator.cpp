#include <iostream>
using namespace std;

// The rule of three dictates that if you overload one of the copy methods, that you must
// implement the other two. These are the copy constructor, = operator, and destructor.
class Test {
private:
    int id;
    string name;

public:
    Test() : id(0), name("") {

    }

    Test(int id, string name) : id(id), name(name) {

    }

    Test(const Test &other) {
        cout << "Copy constructor running" << endl;

        id = other.id;
        name = other.name;
    }

    void print() {
        cout << id << ": " << name << endl;
    }

    const Test &operator=(const Test& other) {
        cout << "Assignment running" << endl;

        id = other.id;
        name = other.name;
        return *this;
    }
};

int main() {

    Test test1(10, "Mike");
    test1.print();

    Test test2(20, "Bob");

    test2 = test1; // This is a shallow copy of this object. It copies the values in memory to new pointers. 
    test2.print();

    Test test3;
    test3 = test2 = test1; // This demonstrates chaining operators.

    test3.operator=(test2); // This is the same as test3 = test2.

    test3.print();

    cout << endl;

    Test test4 = test1; // The assignment operator isn't run here. This uses copy initialization. 
    // This calls the implicit copy constructor.
    test4.print();

    return 0;
}