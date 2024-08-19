
#ifndef EX2_CELL_H
#define EX2_CELL_H
#include "Point.h"

class Cell {
private:
    Point point; // this point determines the cell coordinates
    int numberDrones;
    bool isTarget; // boolean field to mark if the target point in this cell

public:
    Cell(); // default constructor
    Cell(const Cell& other); // copy constructor
    ~Cell() = default; // destructor

    // operators ( = , ++(prefix,postfix), --(prefix,postfix)
    Cell& operator=(const Cell& other);
    Cell& operator++();
    const Cell operator++(int);
    Cell& operator--();
    const Cell operator--(int);

    // getters and setters
    int getNumberDrones()const{return this->numberDrones;}
    bool getIsTarget()const{return this->isTarget;}
    Point getPoint()const{return this->point;}
    void setPoint(double x,double y);
    void setTarget(bool target){this->isTarget = target;}
};
#endif
