
#ifndef EX2_FOREST_H
#define EX2_FOREST_H
#include "Cell.h"
#include "Drone.h"
#include "BinaryTree.h"


class Forest {
private:
    Cell** forestArr; // this field is the forest cells
    BinaryTree* droneTree; // drone binary tree
    Point targetPoint;
    static Drone* leader;
    // these fields are the limits of the forest
    int xMin;
    int yMin;
    int xMax;
    int yMax;
public:
    Forest(Point& target, BinaryTree* tree,int& xMin, int& yMin ,int& xMax, int& yMax ); // constructor
    Forest(const Forest& other); // copy constructor
    ~Forest(); // destructor

    // operators (=, ())
    Forest& operator=(const Forest& other);
    int operator()(int x , int y) const;

    // getters and setters
    Point getTargetPoint()const{return this->targetPoint;}
    BinaryTree* getDroneTree() const{return this->droneTree;}
    Cell** getForestArray()const{return this->forestArr;}
    int getXMin() const{return this->xMin;}
    int getYMin() const{return this->yMin;}
    int getXMax() const{return this->xMax;}
    int getYMax() const {return this->yMax;}
    static Drone* getLeader() {return leader;}
    static void setLeader(Drone* drone){leader = drone;}
};

#endif
