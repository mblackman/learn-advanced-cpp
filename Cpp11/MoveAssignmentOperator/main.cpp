#include <iostream>
#include <vector>
using namespace std;

class Test {
private:
    static const int SIZE=100;
    int *_pBuffer{nullptr};

public:
    Test() {
        _pBuffer = new int[SIZE]{}; // The empty curly parans sets all values to 0.

        // Old way to set all values in the buffer to 0.
        //memset(_pBuffer, 0, sizeof(int) * SIZE); // This sets all of the memory addresses in the buffer to 0.
    }

    Test(int i) {
        _pBuffer = new int[SIZE]{};

        for (int i=0; i<SIZE; i++) {
            _pBuffer[i] = 7*i;
        }
    }

    Test(const Test &other) {
        _pBuffer = new int[SIZE]{};

        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
    }

    // The move constructor. This steals resources for itself.
    Test(Test &&other) {
        cout << "Move ctor" << endl;
        _pBuffer = other._pBuffer;
        other._pBuffer = nullptr; // This ensures calling the destructor on other doesn't delete the buffer.
    }

    Test &operator=(const Test &other) {
        _pBuffer = new int[SIZE]{};

        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
        return *this;
    }

    // Move assignment ctor. This moves the data over to this object. You need to release your own memory.
    Test &operator=(Test &&other) {
        // This has already allocated memory, so we need to free it up.
        delete [] _pBuffer;
        _pBuffer = other._pBuffer;
        other._pBuffer = nullptr;

        cout << "Move assignment" << endl;

        return *this;
    }

    ~Test() {
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

    vector<Test> vec;
    vec.push_back(Test());

    Test test;
    test = getTest(); // Assigning an RValue invokes the move assignment operator.

    return 0;
}