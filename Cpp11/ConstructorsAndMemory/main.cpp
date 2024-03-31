#include <iostream>
#include <vector>
using namespace std;

class Test {
private:
    static const int SIZE=100;
    int *_pBuffer;

public:
    Test() {
        cout << "Ctor" << endl;
        _pBuffer = new int[SIZE]{}; // The empty curly parans sets all values to 0.

        // Old way to set all values in the buffer to 0.
        //memset(_pBuffer, 0, sizeof(int) * SIZE); // This sets all of the memory addresses in the buffer to 0.
    }

    Test(int i) {
        cout << "Parameter ctor" << endl;
        _pBuffer = new int[SIZE]{};

        for (int i=0; i<SIZE; i++) {
            _pBuffer[i] = 7*i;
        }
    }

    Test(const Test &other) {
        cout << "Copy constructor" << endl;
        _pBuffer = new int[SIZE]{};

        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
    }

    Test &operator=(const Test &other) {
        cout << "Assignment" << endl;
        _pBuffer = new int[SIZE]{};

        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
        return *this;
    }

    ~Test() {
        cout << "Destructor" << endl;
        delete [] _pBuffer;
    }

    friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test) {
    out << "Hello from test";
    return out;
}

Test getTest() {
    return Test();
}

int main() {

    Test test1 = getTest();

    cout << test1 << endl;

    vector<Test> vec;
    vec.push_back(Test());

    return 0;
}