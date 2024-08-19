#ifndef EX2_BINARYTREE_H
#define EX2_BINARYTREE_H
#include "Node.h"
#include <iostream>

using namespace std;
class BinaryTree {
private:
    Node* head;
    unsigned int treeSize;

public:
    BinaryTree(); // default constructor
    BinaryTree(const BinaryTree& other)=default; // copy constructor ,there is only one instance of tree in the program
    ~BinaryTree(); // destructor
    BinaryTree& operator=(const BinaryTree& other) = default; // operator =, there is only one instance of tree in the program

    // public functions
    void insert(Drone* drone);
    void remove(Drone* drone);
    Node* search(Node* root,Drone* node) const;
    Node* min(Node* root) const;
    Node* max(Node* root) const;
    void clear();
    void print(Node* root) const;
    unsigned int size() const{return this->treeSize;}

    // getters and setters
    Node* getHead()const{return this->head;}
    void setHead(Node* root){this->head = root;}
    void setSize(unsigned int size){this->treeSize = size;}

private:
    // recursive help functions
    Node * insert(Node* node, Drone* drone);
    Node* remove(Node* root,Drone* drone);
    void clear(Node* node);
};
#endif //EX2_BINARYTREE_H
