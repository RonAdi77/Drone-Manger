
#include "Cell.h"


 //default constructor
Cell::Cell():point(Point()),numberDrones(0),isTarget(false){}

/**
 * copy constructor
 * @param other - other cell to copy
 */
Cell::Cell(const Cell &other):point(other.getPoint()),numberDrones(other.getNumberDrones()),isTarget(getIsTarget()){}

// operator =
Cell &Cell::operator=(const Cell &other){
    if(this == &other){
        return *this;
    }
    this->point = other.getPoint();
    this->numberDrones = other.getNumberDrones();
    this->isTarget = other.isTarget;
    return *this;
}

// operator ++(prefix)
Cell& Cell::operator++() {
    this->numberDrones++;
    return *this;
}
// operator ++(postfix)
const Cell Cell::operator++(int) {
    Cell tmp(*this);
    ++(*this);
    return tmp;
}
// operator --(prefix)
Cell& Cell::operator--() {
    this->numberDrones--;
    return *this;
}

// operator ++(postfix)
const Cell Cell::operator--(int) {
    Cell tmp = *this;
    --(*this);
    return tmp;
}
// setter to field point
void Cell::setPoint(double x,double y) {
    this->point.setX((double )x);
    this->point.setY((double )y);
}









