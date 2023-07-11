#include <iostream>
using namespace std;

struct Complex {
    double real;
    double imaginary;
};

Complex addComplex(Complex c1, Complex c2) {
    Complex sum;
    sum.real = c1.real + c2.real;
    sum.imaginary = c1.imaginary + c2.imaginary;
    return sum;
}

Complex subtractComplex(Complex c1, Complex c2) {
    Complex diff;
    diff.real = c1.real - c2.real;
    diff.imaginary = c1.imaginary - c2.imaginary;
    return diff;
}

Complex multiplyComplex(Complex c1, Complex c2) {
    Complex product;
    product.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    product.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;
    return product;
}

Complex divideComplex(Complex c1, Complex c2) {
    Complex quotient;
    double denominator = c2.real * c2.real + c2.imaginary * c2.imaginary;
    quotient.real = (c1.real * c2.real + c1.imaginary * c2.imaginary) / denominator;
    quotient.imaginary = (c1.imaginary * c2.real - c1.real * c2.imaginary) / denominator;
    return quotient;
}

void displayComplex(Complex c) {
    cout << c.real << " + " << c.imaginary << "i" << endl;
}

Complex getComplexInput() {
    Complex c;
    cout << "Enter the real part: ";
    cin >> c.real;
    cout << "Enter the imaginary part: ";
    cin >> c.imaginary;
    return c;
}

int main() {
    cout << "Enter the first complex number:" << endl;
    Complex c1 = getComplexInput();

    cout << "\nEnter the second complex number:" << endl;
    Complex c2 = getComplexInput();

    cout << "\nComplex Numbers:" << endl;
    cout << "c1 = ";
    displayComplex(c1);
    cout << "c2 = ";
    displayComplex(c2);
    cout << endl;

    Complex sum = addComplex(c1, c2);
    Complex diff = subtractComplex(c1, c2);
    Complex product = multiplyComplex(c1, c2);
    Complex quotient = divideComplex(c1, c2);

    cout << "Addition: ";
    displayComplex(sum);
    cout << "Subtraction: ";
    displayComplex(diff);
    cout << "Multiplication: ";
    displayComplex(product);
    cout << "Division: ";
    displayComplex(quotient);

    return 0;
}