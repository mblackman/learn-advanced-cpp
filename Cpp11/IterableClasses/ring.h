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

    iterator begin() {
        return iterator(0, *this);
    }

    iterator end() {
        return iterator(m_size, *this);
    }

    void add(T value) {
        m_values[m_index++] = value;

        if (m_index == m_size) {
            m_index = 0;
        }
    }

    T &get(int index) {
        return m_values[index];
    }

    const int size() {
        return m_size;
    }
};

template <typename T>
class ring<T>::iterator {
private:
    int m_index;
    ring &m_ring;

public:
    iterator(int index, ring &ring): m_index(index), m_ring(ring) {

    }

    // Declaring int here causes this to implement the postfix ++ operation.
    iterator &operator++(int) {
        m_index++;
        return *this;
    }

    iterator &operator++() {
        m_index++;
        return *this;
    }

    T &operator*() {
        return m_ring.get(m_index);
    }

    bool operator!=(const iterator &other) const {
        return m_index != other.m_index;
    }
};

#endif