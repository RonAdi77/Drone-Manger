
#include "Point.h"

Point::Point():x(0.0),y(0.0){}

Point::Point(double x, double y):x(x),y(y){}

Point::Point(const Point &other):x(other.getX()),y(other.getY()){}

Point &Point::operator=(const Point &other) {
    if(this == &other){
        return *this;
    }
    this->setX(other.getX());
    this->setY(other.getY());
    return *this;
}

Point Point::operator+(const Point &other) const {
    return {getX()+other.getX(),getY()+other.getY()};
}

Point Point::operator-(const Point &other) const {
    return {getX()-other.getX(),getY()-other.getY()};
}

Point Point::operator*(double mult) const {
    return {mult*getX(),mult*getY()};
}

bool operator!=(const Point &p1, const Point &p2) {
    return p1.getX()!=p2.getX() || p1.getY()!=p2.getY();
}

/**
 * static limit function to calculate if some point is not in the bounds of x[0,72] y[0,42]
 * @param other - the point that the function check
 * @return point in the bounds
 */
Point &Point::limit(Point &other) {
    if(other.getX() > MAX_X){ other.setX(MAX_X);}
    if(other.getY() > MAX_Y){ other.setY(MAX_Y);}
    if(other.getX() < MIN_X){other.setX(MIN_X);}
    if(other.getY() < MIN_Y){other.setY(MAX_Y);}
    return other;
}
/**
 * function that calculate euclidean distance between two points
 * @param p1 - first point
 * @param p2 - second point
 * @return - the distance between two points in double
 */
double Point::distance(Point &p1, Point &p2) {
    double x = p1.getX()-p2.getX();
    double y = p1.getY()-p2.getY();
    x = pow(x,2);
    y = pow(y,2);
    return pow(x+y,0.5);
}





