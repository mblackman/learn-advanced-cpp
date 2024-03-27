#include "Complex.h"

namespace  testproject {

Complex::Complex(): real(), imaginary() { 

};

Complex::Complex(double real, double imaginary): real(real), imaginary(imaginary) {

}

Complex::Complex(const Complex &other) {
    real = other.real;
    imaginary = other.imaginary;
}

const Complex &Complex::operator=(const Complex &other) {
    real = other.real;
    imaginary = other.imaginary;
    return *this;
}

ostream &operator<<(ostream &out, const Complex &complex) {
    out << "(" << complex.getReal() << ", " << complex.getImaginary() << ")";
    return out;
}

Complex operator+(const Complex &lhs, const Complex &rhs) {
    return Complex(lhs.getReal() + rhs.getReal(), lhs.getImaginary() + rhs.getImaginary());
}

Complex operator+(const Complex &lhs, const double rhs) {
    return Complex(lhs.getReal() + rhs, lhs.getImaginary() + rhs);
}

Complex operator+(const double lhs, const Complex &rhs) {
    return Complex(rhs.getReal() + lhs, rhs.getImaginary() + lhs);
}

Complex Complex::operator*() const {
    return Complex(real, -imaginary);
}

}