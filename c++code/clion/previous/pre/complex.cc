#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Complex
{
private:
    double real, image;

public:
    Complex(double r = 0, double i = 0)
    {
        real = r;
        image = i;
    }
    Complex operator+(const Complex &b);
    Complex operator-(const Complex &b);
    Complex operator*(const Complex &b);
    Complex operator/(const Complex &b);
    bool operator==(const Complex &b);
    bool operator!=(const Complex &b);
    Complex operator-();
    friend ostream &operator<<(ostream &os, const Complex &c);
    friend istream &operator>>(istream &is, Complex &c);
};
Complex Complex::operator+(const Complex &b)
{
    return Complex(real + b.real, image + b.image);
}
Complex Complex::operator-(const Complex &b)
{
    return Complex(real - b.real, image - b.image);
}
Complex Complex::operator*(const Complex &b)
{
    return Complex(real * b.real - image * b.image, real * b.image + image * b.real);
}
Complex Complex::operator/(const Complex &b)
{
    return Complex((real * b.real + image * b.image) / (pow(b.real, 2) + pow(b.image, 2)), (image * b.real - real * b.image) / (pow(b.real, 2) + pow(b.image, 2)));
}
bool Complex::operator==(const Complex &b)
{
    if ((real == b.real) && (image == b.image))
        return 1;
    else
        return 0;
}
bool Complex::operator!=(const Complex &b)
{
    if ((real != b.real) || (image != b.image))
        return 1;
    else
        return 0;
}
Complex Complex::operator-()
{
    return Complex(-real, -image);
}
ostream &operator<<(ostream &os, const Complex &c)
{
    os << c.real << "+" << c.image << "i";
    return os;
}
istream &operator>>(istream &is, Complex &c)
{
    string s;
    is >> s;
    int pos = s.find("+", 0);
    string sTmp = s.substr(0, pos);
    c.real = stof(sTmp.c_str());
    sTmp = s.substr(pos + 1, s.length() - pos - 2);
    c.image = atof(sTmp.c_str());
    return is;
}
int main()
{
    Complex a, b;
    cin >> a >> b;
    cout << "a+b= " << a + b << endl;
    cout << "a-b= " << a - b << endl;
    cout << "a*b= " << a * b << endl;
    cout << "a/b= " << a / b << endl;
    cout << "a==b: " << (a == b) << endl;
    cout << "-a= " << -a << endl;
    cout << "a!=b:" << (a != b) << endl;
}
