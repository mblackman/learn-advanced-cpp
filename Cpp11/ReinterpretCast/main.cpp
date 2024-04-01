#include<iostream>
using namespace std;

class Parent {
public:
    virtual void speak() {
        cout << "Parent" << endl;
    }
};

class Brother: public Parent {

};

class Sister: public Parent {

};

// Reinterpret cast changes the bits from one type to another. Very dangerous. Why even have this?
int main() {

    Parent parent;
    Brother brother;

    Sister *pbb = dynamic_cast<Sister *>(&brother);

    if (pbb == nullptr) {
        cout << "Invalid cast!" << endl;
    }
    else {
        cout << pbb << endl;
    }

    Sister *pbs = reinterpret_cast<Sister *>(&brother);

    if (pbs == nullptr) {
        cout << "Invalid cast!" << endl;
    }
    else {
        cout << pbs << endl;
    }

    return 0;
}