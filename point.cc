#include "point.h"
#include "fraction.h"

Point::Point(Fraction _x, Fraction _y){
    x = _x;
    y = _y;
}

Point::~Point(){}

Point Point::operator+(Point point){
    Fraction s, t;

    s = x + point.x;
    t = y + point.y;

    return Point(s,t);
}

Point Point::operator-(Point point){
    Fraction s, t;

    s = x - point.x;
    t = y - point.y;

    return Point(s,t);
}

Fraction Point::operator*(Point point){
    Fraction s;

    s = x * point.y - y * point.x;

    return s;
}

Point Point::operator*(Fraction scale){
    Fraction s, t;

    s = x * scale;
    t = y * scale;

    return Point(s,t);
}

bool Point::operator<(Point point){
    return (x < point.x) || (x == point.x && x < point.y);
}

Fraction Point::getX(){
    return x;
}

Fraction Point::getY(){
    return y;
}

std::istream &operator>>(std::istream &is, Point &p){
    Fraction s, t;
    char comma, oPen, cPen;

    is >> oPen >> s >> comma >> t >> cPen;

    p = Point(s,t);

    return is;
}


std::ostream &operator<<(std::ostream &os, Point p){

    os << "( " << p.getX() << " , " << p.getY() << " )";

    return os;
}