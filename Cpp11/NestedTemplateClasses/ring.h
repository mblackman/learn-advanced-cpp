#ifndef RING_H_
#define RING_H_

#include <iostream>
using namespace std;

template <typename T>
class ring {
private: 
    T* m_values;
    int m_size;
    int m_index;

public:
    class iterator;

    ring(int size): m_values(NULL), m_size(size), m_index(0) {
        m_values = new T[size];
    }

    ~ring() {
        delete [] m_values;
    }

    void add(T value) {
        m_values[m_index++] = value;

        if (m_index == m_size) {
            m_index = 0;
        }
    }

    const T get(int index) {
        if (index >= m_size) {
            return nullptr;
        }

        return m_values[index];
    }

    const int size() {
        return m_size;
    }
};

template <typename T>
class ring<T>::iterator {
public:
    void print() {
        cout << "Hello from iterator" << endl;
    }
};

#endif