#include <iostream>
#include <exception>
using namespace std;

void goesWrong() {
    bool error1Detected = true;
    bool error2Detected = false;

    if (error1Detected) {
        throw bad_alloc();
    }

    if (error2Detected) {
        throw exception();
    }
}

int main() {

    try {
        goesWrong();
    }
    catch (bad_alloc &e) {
        // Subclasses need to get caught before more general exceptions or else they will be skipped.
        cout << e.what() << endl;
    }
    catch(exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}