
#include "Node.h"

// default constructor
Node::Node():leftTree(nullptr),rightTree(nullptr),data(nullptr){}

// constructor
Node::Node(Drone* drone):leftTree(nullptr),rightTree(nullptr),data(drone){}

Node::~Node() {
    delete leftTree;
    delete rightTree;
    delete data;
}







