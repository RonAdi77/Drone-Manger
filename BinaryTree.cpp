
#include "BinaryTree.h"

// default constructor
BinaryTree::BinaryTree():head(nullptr),treeSize(0){}

// destructor
BinaryTree::~BinaryTree(){
    clear();
    delete this->head;
}

/**
 * insert function get drone to insert and than call to recursive insert
 * @param drone - the drone to be insert to the binary tree
 */
void BinaryTree::insert(Drone *drone) {
    this->head = insert(this->head,drone);
}
/**
 * this function recursively insert the drone to the tree in the place he need to be
 * @param node - a node in the tree , at first call the node is the head/root of the tree
 * @param drone - the drone to be insert to the binary tree
 * @return the pointer to the head of tree after the insertion of the drone to the tree
 */
Node * BinaryTree::insert(Node *node, Drone* drone) {
    if(node == nullptr){
        this->treeSize++;
        return new Node(drone);
    }
    else if(*drone < *node->getData()){
        node->setLeftTree(insert(node->getLeftTree(),drone));
    }
    else if(*node->getData() < *drone){
        node->setRightTree(insert(node->getRightTree(),drone));
    }
    return node;
}

/**
 * this function search if the drone is in the tree
 * @param node - a node in the tree , at first call the node is the head/root of the tree
 * @param drone - the drone to be search to the binary tree
 * @return pointer to node that contain the drone or nullptr
 */
Node *BinaryTree::search(Node* node,Drone* drone) const {
    if(node == nullptr){
        return nullptr;
    }
    else if( drone < node->getData() ){
        search(node->getLeftTree(),drone);
    }
    else if(drone < node->getData()){
        search(node->getRightTree(),drone);
    }
    return node;
}
/**
 * this function return pointer to the node with the minimum value in the tree (also can find successor of nodes)
 * @param root - a node in the tree
 * @return pointer to the node with the minimum value in the tree
 */
Node *BinaryTree::min(Node *root) const {
    if( root->getLeftTree()== nullptr){
        return root;
    }
    return min(root->getLeftTree());
}
/**
 * thi function return pointer to the node with the maximum value in the tree
 * @param root -a node in the tree
 * @return pointer to the node with the maximum value in the tree
 */
Node *BinaryTree::max(Node *root) const {
    if(root->getRightTree() == nullptr ){
        return root;
    }
    return max(root->getRightTree());
}

/**
 * this function get a drone to be removed from the tree , and then call to the recursive remove function
 * @param drone - the drone to be removes from the tree
 */
void BinaryTree::remove(Drone *drone) {
    this->head = remove(this->head,drone);
}
/**
 * this function get node in the tree , drone to be remove and remove the drone from the tree
 * @param node -  a node in the tree , at first call the node is the head/root of the tree
 * @param drone - the drone to be removes from the tree
 * @return pointer to the head of the tree after remove the drone
 * at first the function find the node to be remove and then check if the node is leaf or has one child,
 * and the remove but if the node has 2 child the function find the successor of the node and then replace them and remove the successor
 */
Node* BinaryTree::remove(Node *node, Drone *drone) {
    if(node == nullptr){
        return node;
    }
    else if(drone < node->getData()){
        node->setLeftTree(remove(node->getLeftTree(),drone));
    }
    else if(drone < node->getData()){
        node->setRightTree(remove(node->getRightTree(), drone));
    }
    else{
        // node with only one child or without child
        if(node->getLeftTree() == nullptr){
            Node* tmp = node->getRightTree();
            delete node;
            this->treeSize--;
            return tmp;
        }
        else if(node->getRightTree() == nullptr){
            Node* tmp = node->getLeftTree();
            delete node;
            this->treeSize--;
            return tmp;
        }
        // node with two children
        Node* successor = min(node->getRightTree()); // find the successor of node
        node->setData(successor->getData()); // set the data of the node to be removed to the successor data
        node->setRightTree(remove(node->getRightTree(),successor->getData())); // remove the successor from the tree
    }
    return node;
}

/**
 * this function call to the recursive clear function
 * make the head of the tree nullptr and the size to be 0
 */
void BinaryTree::clear() {
    clear(this->head);
    this->head = nullptr;
    this->treeSize = 0;
}
/**
 * this function recursively delete all the nodes in the tree
 * @param node - a node in the tree , at first call the node is the head/root of the tree
 */
void BinaryTree::clear(Node *node) {
    if(node != nullptr){
        clear(node->getLeftTree());
        clear(node->getRightTree());
        delete node;
    }
}
/**
 * this function print the drones to the standard output in inOrder scan (in sorted from the minimum to the maximum)
 * @param root - a node in the tree , at first call the node is the head/root of the tree
 */
void BinaryTree::print(Node* root) const {
    if(root != nullptr){
        print(root->getLeftTree());
        cout << *root->getData();
        print(root->getRightTree());
    }

}


























