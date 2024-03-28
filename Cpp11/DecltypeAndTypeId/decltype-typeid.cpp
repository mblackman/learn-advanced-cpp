#include <iostream>
#include <typeinfo>
using namespace std;

int main() {

    string value;
    int intVal;

    // Because string is a C++ type, this returns more information about the class and function call.
    // The compiler adds characters to this string in a process called name mangling. 
    // This printed: NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
    cout << typeid(value).name() << endl;

    cout << typeid(intVal).name() << endl; // This prints the value i for an integer.

    decltype(value) name = "Bob";

    cout << typeid(name).name() << endl;
    cout << name << endl;

    return 0;
}