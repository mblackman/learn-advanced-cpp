#include <iostream>
#include <memory>

using namespace std;

class Test {
public:
    Test() {
        cout << "Empty Ctor" << endl;
    }

    void greet()  {
        cout << "Hello" << endl;
    }

    ~Test() {
        cout << "Destructor" << endl;
    }
};

class Temp {
private:
    unique_ptr<Test[]> pTest;

public:
    Temp(): pTest(new Test[2]) {

    }
};

// Don't use autoptr anymore because compatibility issues.
int main() {

    unique_ptr<int> pTest(new int);

    *pTest = 7;

    cout << *pTest << endl;

    unique_ptr<Test> pointTest(new Test);

    pointTest->greet();

    // Memory gets cleaned up after going out of this scope.
    {
        unique_ptr<Test> scopeTest(new Test);
        scopeTest->greet();
    }

    Temp temp; // This shows how we don't need a destructor for Test since the unique_ptr cleans up the memory.

    cout << "Finished" << endl;
    return 0;
}