//danielcohen1717@gmail.com

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <string>
#include <sstream>

class Complex {
private:
    double real;  // Real part of the complex number
    double imag;  // Imaginary part of the complex number

public:
    Complex(double r = 0.0, double i = 0.0);  // Constructor with default values

    double get_real() const;  // Getter for the real part
    double get_imag() const;  // Getter for the imaginary part

    Complex operator+(const Complex& other) const;  // Addition of two complex numbers
    Complex operator-(const Complex& other) const;  // Subtraction of two complex numbers
    Complex operator*(const Complex& other) const;  // Multiplication of two complex numbers
    Complex operator/(const Complex& other) const;  // Division of two complex numbers

    bool operator==(const Complex& other) const;  // Equality comparison
    bool operator>(const Complex& other) const;  // Greater-than comparison
    bool operator<(const Complex& other) const;  // Less-than comparison

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);  // Output stream operator
    friend std::istream& operator>>(std::istream& is, Complex& c);  // Input stream operator
    
    std::string to_string() const;  // Convert complex number to string
};

#endif // COMPLEX_HPP
