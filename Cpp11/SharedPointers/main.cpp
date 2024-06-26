#include <iostream>

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

int main() {

    shared_ptr<Test> pTest2(nullptr);
    
    {
        shared_ptr<Test> pTest1 = make_shared<Test>();
        pTest2 = pTest1;

        auto pTest3 = pTest1;
    }

    cout << "Finished" << endl;
    return 0;
}