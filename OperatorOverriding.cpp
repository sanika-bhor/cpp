/*
PROBLEM STATEMENT 1:
Implement a class Complex which represents the Complex Number data type.Implement the following
1. Constructor(including a default constructor which creates the complex number 0 + 0i).
2. Overload operator+ to add two complex numbers.
3. Overload operator* to multiply two complex numbers.
4. Overload operators << and >> to print and read Complex Numbers.
*/

#include <iostream>
using namespace std;

class Complex
{
    int real, img;

public:
    Complex()
    {
        real = 0;
        img = 0;
    }

    // Overload the >> operator for input
    friend istream &operator>>(istream &input, Complex &c)
    {
        cout << "Enter real & imaginary parts: ";
        input >> c.real >> c.img;
        return input;
    }

    // Overload the << operator for output
    friend ostream &operator<<(ostream &output, const Complex &c)
    {
        output << c.real << "+j" << c.img;
        return output;
    }

    // Overload the + operator for addition
    Complex operator+(const Complex &c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }

    // Overload the * operator for multiplication
    Complex operator*(const Complex &c)
    {
        Complex temp;
        temp.real = real * c.real;
        temp.img = img * c.img;
        return temp;
    }
};

int main()
{
    Complex c1, c2, c3;

    // Input for the first complex number
    cin >> c1;

    // Input for the second complex number
    cin >> c2;

    // Add two complex numbers
    c3 = c1 + c2;
    cout << "Addition: " << c3 << endl;

    // Multiply two complex numbers
    c3 = c1 * c2;
    cout << "Multiplication: " << c3 << endl;

    return 0;
}
