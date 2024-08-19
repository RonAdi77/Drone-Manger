
#include "Forest.h"

Drone* Forest::leader = nullptr;

// constructor , create the forest with the bounders , tree and target point
Forest::Forest(Point &target, BinaryTree *tree, int &xMin, int &yMin, int &xMax, int &yMax)
:droneTree(new BinaryTree()),xMin(xMin),yMin(yMin),xMax(xMax),yMax(yMax){
    forestArr = new Cell*[this->xMax+1];
    for (int i = this->xMin; i <= this->xMax; ++i) {
        forestArr[i] = new Cell[this->yMax+1];
        for (int j = this->yMin; j <= this->yMax; ++j) {
            forestArr[i][j].setPoint((double )i,(double )j);
            if(i == floor(target.getX()) && j == floor(target.getY())){ // mark the cell of the target point as the target cell
                forestArr[i][j].setTarget(true);
            }
        }
    }
    this->droneTree->setHead(tree->getHead());
    this->droneTree->setSize(tree->size());
    this->targetPoint = target;
}

// destructor
Forest::~Forest() {
    delete droneTree;
    for (int i = MIN_X; i <= MAX_X; ++i) {
        delete[] forestArr[i];
    }
    delete[] forestArr;
}

// copy constructor create the same way as the constructor create
Forest::Forest(const Forest &other):droneTree(new BinaryTree()),xMin(other.getXMin()),
yMin(other.getYMin()),xMax(other.getXMax()),yMax(other.yMax){
    forestArr = new Cell*[this->xMax+1];
    for (int i = this->xMin; i <= this->xMax; ++i) {
        forestArr[i] = new Cell[this->yMax+1];
        for (int j = this->yMin; j <= this->yMax; ++j) {
            forestArr[i][j] = other.getForestArray()[i][j];
        }
    }
    this->droneTree->setHead(other.getDroneTree()->getHead());
    this->droneTree->setSize(other.getDroneTree()->size());
    this->targetPoint = other.targetPoint;
}



// operator () return the number of drones in the cell of the coordination x,y
int Forest::operator()(int x, int y) const {
    return forestArr[x][y].getNumberDrones();
}

// operator =
Forest &Forest::operator=(const Forest &other) {
    if(this == &other){
        return *this;
    } else{
        // delete the current forest array
        for (int i = this->xMin; i < this->xMax ; ++i) {
            delete[] this->forestArr[i];
        }
        delete[] forestArr;
        this->xMin = other.getXMin();
        this->yMin = other.getYMin();
        this->xMax = other.getXMax();
        this->yMax = other.getYMax();
        // create new array and assign the cells of other
        this->forestArr = new Cell*[this->xMax+1];
        for (int i = this->xMin; i <= this->xMax; ++i) {
            this->forestArr[i] = new Cell[this->yMax +1];
            for (int j = this->yMin; j <= this->yMax ; ++j) {
                forestArr[i][j] = other.getForestArray()[i][j];
            }
        }
        delete droneTree;
        this->droneTree->setHead(other.getDroneTree()->getHead());
        this->droneTree->setSize(other.getDroneTree()->size());
        this->targetPoint = other.getTargetPoint();
    }
    return *this;
}


