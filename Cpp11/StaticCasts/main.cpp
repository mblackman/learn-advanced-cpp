#include<iostream>
using namespace std;

class Parent {
public:
    void speak() {
        cout << "Parent" << endl;
    }
};

class Brother: public Parent {

};

class Sister: public Parent {

};

// Static cast in a compile time check and not runtime. Be wary of runtime issues.
int main() {

    Parent parent;
    Brother brother;

    Parent *pp = &brother;

    Brother *pb = static_cast<Brother *>(&parent);

    Parent *ppb = &brother;

    Brother *pbb = static_cast<Brother *>(ppb);

    cout << pbb << endl;

    cout << pb << endl;

    Parent &&p = Parent();
    Parent &&p1 = static_cast<Parent &&>(parent);
    p.speak();
    p1.speak();

    float value = 3.23;

    cout << value << endl;
    cout << (int)value << endl;
    cout << int(value) << endl;
    cout << static_cast<int>(value) << endl; // This is useful in most situations. 

    return 0;
}