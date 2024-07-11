//danielcohen1717@gmail.com

#include "Complex.hpp"

Complex::Complex(double r, double i) : real(r), imag(i) {}  // Constructor initializes real and imag

double Complex::get_real() const {
    return real;  // Return real part
}

double Complex::get_imag() const {
    return imag;  // Return imaginary part
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);  // Add complex numbers
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);  // Subtract complex numbers
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);  // Multiply complex numbers
}

Complex Complex::operator/(const Complex& other) const {
    double denom = other.real * other.real + other.imag * other.imag;  // Calculate denominator
    return Complex((real * other.real + imag * other.imag) / denom, (imag * other.real - real * other.imag) / denom);  // Divide complex numbers
}

bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;  // Check for equality
}

bool Complex::operator>(const Complex& other) const {
    return (real > other.real) || (real == other.real && imag > other.imag);  // Check for greater-than
}

bool Complex::operator<(const Complex& other) const {
    return (real < other.real) || (real == other.real && imag < other.imag);  // Check for less-than
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real;
    if (c.imag >= 0) os << "+";
    os << c.imag << "i";  // Output complex number
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
    is >> c.real >> c.imag;  // Input complex number
    return is;
}

std::string Complex::to_string() const {
    std::ostringstream oss;
    oss << *this;  // Convert complex number to string
    return oss.str();
}
