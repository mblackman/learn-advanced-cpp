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

// Dynamic casts happen at runtime and can catch errors from invalid casts.
int main() {

    Parent parent;
    Brother brother;

    Brother *pbb = dynamic_cast<Brother *>(&brother);

    if (pbb == nullptr) {
        cout << "Invalid cast!" << endl;
    }
    else {
        cout << pbb << endl;
    }

    Brother *ppb = dynamic_cast<Brother *>(&parent);

    if (ppb == nullptr) {
        cout << "Invalid cast!" << endl;
    }
    else {
        cout << ppb << endl;
    }

    return 0;
}