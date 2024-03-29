#include <iostream>
#include "ring.h"
using namespace std;

int main() {

    // Basic OOP approach.
    ring<string> textRing(3);

    textRing.add("one");
    textRing.add("two");
    textRing.add("three");
    textRing.add("four");

    for (int i=0; i<textRing.size(); i++) {
        cout << textRing.get(i) << endl;
    }

    // Custom iterator
    ring<string>::iterator it;

    it.print();
    
    return 0;
}