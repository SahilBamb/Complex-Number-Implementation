/*
 *
 *  C++ version
 *
 */

/* complex.h */

/*#ifndef RATIONAL_H
#define RATIONAL_H
*/

#include <iostream>
#include <cmath>

using std::ostream;
using std::cout;
using std::endl;
using std::abs;

struct complex {

    complex(double = 0, double = 0);

    complex operator++(int) const;
    complex operator++() const;
    complex operator--(int) const;
    complex operator--() const;

    complex operator+(const complex &) const;
    complex operator-(const complex &) const;
    complex operator*(const complex &) const;
    complex operator/(const complex &) const;

    complex operator+(double) const;
    complex operator-(double) const;
    complex operator*(double) const;
    complex operator/(double) const;
    complex operator=(double) const;

    friend complex operator+(double, const complex &);
    friend complex operator-(double, const complex &);
    friend complex operator*(double, const complex &);
    friend complex operator/(double, const complex &);

    friend ostream &operator<<(ostream &, const complex &);

private:

    double img;
    double real;
};


complex::complex(double real, double img) : real(real), img(img) {}

complex complex::operator=(double n) const {

    return complex(n);
}

complex complex::operator++(int xi) const {

    if (xi!=0) {
        return complex(real+xi,img);}

    else {
        return complex(real+1.0,img);
    }
    
}

complex complex::operator--(int xi) const {

    if (xi!=0) {
        return complex(real-xi,img);}
    else {
        return complex(real-1.0,img);
    }
    
}

complex complex::operator++() const {

    return complex(real+1.0,img);
    
}

complex complex::operator--() const {

    return complex(real-1.0,img);
    
}

complex complex::operator-(const complex &o) const {

    return complex(real - o.real, img - o.img);
}

complex complex::operator-(double n) const {

    return complex(real - n, img);
}

complex complex::operator*(const complex &o) const {

    return complex( (real * o.real) - (img * o.img), (real*o.img + o.real*img));
}

complex complex::operator*(double n) const {

    return complex(real * n, img * n);
}

complex complex::operator/(const complex &o) const {

    double r = ( (real * o.real) + (img * o.img) ) / (pow(o.real,2) + pow(o.img,2));
    double i = ((img*o.real) - (real*o.img)) / (pow(o.real,2) + pow(o.img,2));
    return complex(r,i);
}

complex complex::operator/(double n) const {

    return complex(real/n, img/n);
}

complex complex::operator+(const complex &o) const {

    return complex(real + o.real, img + o.img);
}

complex complex::operator+(double n) const {

    return complex(real + n, img);
}

complex operator+(double n, const complex &o) {

    return o + n;
}

complex operator-(double n, const complex &o) {

    return complex(n) - o;
}

complex operator*(double n, const complex &o) {

    return complex(n) * o;
}

complex operator/(double n, const complex &o) {

    return complex(n) / o;
}


ostream &operator<<(ostream &out, const complex &o) {


    if (o.img>=0) 
        {out << "(" << o.real << " + " << o.img << "i)";}
    else
        {out << "(" << o.real << " - " << abs(o.img) << "i)";}
    
    return out;
}



int main(void) {

    complex a(1.0, 2.0);
    complex b(1.0, 3.0);

    double i = 5.0;

    complex c = i;

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    cout << "------------------------------------" << endl;    
    cout << b << " + " << a << " = " << b + a << endl;
    cout << b << " - " << a << " = " << b - a << endl;
    cout << b << " * " << a << " = " << b * a << endl;
    cout << b << " / " << a << " = " << b / a << endl;
    cout << "------------------------------------" << endl;
    cout << a << " + " << i << " = " << a + i << endl;
    cout << a << " - " << i << " = " << a - i << endl;
    cout << a << " * " << i << " = " << a * i << endl;
    cout << a << " / " << i << " = " << a / i << endl;
    cout << "------------------------------------" << endl;
    cout << i << " + " << a << " = " << i + a << endl;
    cout << i << " - " << a << " = " << i - a << endl;
    cout << i << " * " << a << " = " << i * a << endl;
    cout << i << " / " << a << " = " << i / a << endl;
    cout << "------------------------------------" << endl;
    cout << a << "++ =" << a++ << endl;
    cout << a << "-- =" << a-- << endl;
    cout << "++" << a << " = " << ++a << endl;
    cout << "--" << a << " = " << --a << endl;
    cout << "------------------------------------" << endl;
    cout << "complex c" << " = " << i << " -> " << c << endl;

    return 0;
}