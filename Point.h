
#ifndef EX2_POINT_H
#define EX2_POINT_H
#include "Const.h"
#include <cmath>

class Point {
private:
    double x; // coordinate x
    double y; // coordinate y
public:
    Point(); // default constructor
    Point(double x , double y); // constructor
    Point(const Point& other); // copy constructor
    ~Point() = default; // destructor

    // operators (= , - , + , * , !=)
    Point& operator=(const Point& other);
    Point operator+(const Point& other) const;
    Point operator-(const Point& other) const;
    Point operator*(double mult) const;
    friend bool operator!=(const Point& p1,const Point& p2);

    // getters and setters
    double getX() const{return this->x;}
    double getY() const{return this->y;}
    void setX(double newX){this->x=newX;}
    void setY(double newY){ this->y=newY;}

    // static functions
    static Point& limit(Point& other); // check if the point in the borders
    static double distance(Point& p1,Point& p2); // calculate the Euclidean distance between two points
};
#endif
