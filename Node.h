
#ifndef EX3_NODE_H
#define EX3_NODE_H
#include "Drone.h"

class Node {
private:
    Node* leftTree;
    Node* rightTree;
    Drone* data;
public:
    Node(); // default constructor
    explicit Node(Drone* drone); // constructor
    Node(const Node& other) = default; // copy constructor
    ~Node(); // destructor
    Node& operator=(const Node& other) = default; // operator =

    // getters and setters
    Node* getLeftTree() const{return leftTree;};
    Node* getRightTree() const{return rightTree;};
    Drone* getData() const {return data;};
    void setLeftTree(Node* other){this->leftTree = other;};
    void setRightTree(Node* other){this->rightTree = other;};
    void setData( Drone* other){this->data = other;};
};


#endif
