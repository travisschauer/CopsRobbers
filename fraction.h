#include <iostream>
#include <cstdint>

#ifndef _FRACTION_H

#define _FRACTION_H

class Fraction{
    public:
        Fraction(int32_t _num=0,int32_t _den=1);
        ~Fraction();

        Fraction operator+(Fraction rhs);
        Fraction operator-(Fraction rhs);
        Fraction operator*(Fraction rhs);
        Fraction operator/(Fraction rhs);
        Fraction operator=(Fraction rhs);

        bool operator==(Fraction rhs);
        bool operator!=(Fraction rhs);
        bool operator<=(Fraction rhs);
        bool operator>=(Fraction rhs);
        bool operator<(Fraction rhs);
        bool operator>(Fraction rhs);

        int32_t getNum();
        int32_t getDen();


    private:
        int32_t
            num,
            den;
};

std::istream &operator>>(std::istream &is, Fraction &f);
std::ostream &operator<<(std::ostream &os,Fraction f);

#endif

