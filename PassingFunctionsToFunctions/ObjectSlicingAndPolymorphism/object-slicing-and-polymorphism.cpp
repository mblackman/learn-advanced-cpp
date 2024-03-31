#include <iostream>
using namespace std;

class Parent {
private:
    int one;
public:
    Parent(): one() {

    }

    Parent(const Parent &other): one() {
        cout << "Copy parent" << endl;
    }

    virtual void print() {
        cout << "Parent" << endl;
    }

    virtual ~Parent() {

    }
};

class Child: public Parent {
private:
    int two;

public:
    Child(): two() {

    }

    void print() {
        cout << "Child" << endl;
    }
};

int main() {

    Child c1;
    Parent &p1 = c1; // Store the child in a Parent address to keep underlying type
    Parent p2 = c1; // This copies the values from child into the parent into a type of parent.
    Parent p3 = Child(); // This is the same as above. The copy constructor in parent is being called.

    p1.print();
    p2.print();
    p3.print();

    return 0;
}