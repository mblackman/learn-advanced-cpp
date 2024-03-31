#include <iostream>
#include "ring.h"
using namespace std;

int main() {

    ring<string> textRing(3);

    textRing.add("one");
    textRing.add("two");
    textRing.add("three");
    textRing.add("four");
    textRing.add("five");

    for (string text: textRing) {
        cout << text << endl;
    }

    // Create using list initializer
    ring<string> initRing {"Apple", "Orange", "Banana", "Corn"};

    for (string text: initRing) {
        cout << text << endl;
    }

    initRing.add("Something else");
    initRing.add("Another one");

    for (string text: initRing) {
        cout << text << endl;
    }

    return 0;
}