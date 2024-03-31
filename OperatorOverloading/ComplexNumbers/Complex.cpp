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

}