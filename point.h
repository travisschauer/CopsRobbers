#include <iostream>
#include <cstdint>
#include "fraction.h"

#ifndef _POINT_H

#define _POINT_H

class Point{
    public:
        Point(Fraction _x=Fraction(0), Fraction _y=Fraction(0));
        ~Point();

        Point operator+(Point point); 
        Point operator-(Point point);
        Fraction operator*(Point point);
        Point operator*(Fraction scale); // a point by fraction
        
        bool operator<(Point point);

        Fraction getX();
        Fraction getY();

    private:
        Fraction x, y;
};

std::istream &operator>>(std::istream &is, Point &p);
std::ostream &operator<<(std::ostream &os, Point p);

#endif
