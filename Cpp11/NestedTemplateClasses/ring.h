#include <iostream>
#include <vector>
using namespace std;

template <class T>
class ring {
private: 
    vector<T> values;
    int maxSize;
    int index;

public:
    ring(int size): values(size), maxSize(size), index(0) {

    }

    void add(T value) {
        if (index >= maxSize) {
            index = 0;
        }

        values[index++] = value;
    }

    const T get(int index) {
        if (index > values.size() - 1) {
            return nullptr;
        }

        return values[index];
    }

    const int size() {
        return values.size();
    }
};