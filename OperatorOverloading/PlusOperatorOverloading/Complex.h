#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

namespace  testproject {

class Complex {
private:
    double real;
    double imaginary;
    
public:
    Complex();
    Complex(double real, double imaginary);
    Complex(const Complex &other);
    const Complex &operator=(const Complex &other);

    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }
};

ostream &operator<<(ostream& out, const Complex& complex);

Complex operator+(const Complex &lhs, const Complex &rhs);

Complex operator+(const Complex &lhs, const double rhs);

Complex operator+(const double lhs, const Complex &rhs);

}

#endif