#include <iostream>
#include "ring.h"
using namespace std;

int main() {

    ring<string> textRing(3);

    textRing.add("one");
    textRing.add("two");
    textRing.add("three");
    textRing.add("four");

    for (int i=0; i<textRing.size(); i++) {
        cout << textRing.get(i) << endl;
    }

    return 0;
}