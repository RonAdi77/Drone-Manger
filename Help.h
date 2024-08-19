
#ifndef EX2_HELP_H
#define EX2_HELP_H
#include "Forest.h"
#include "Hybrid.h"
#include "MultiRotor.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

namespace help{
    Point firstFileInput(int& iteration,string& firstFileName,int & xMin,int& yMin ,int& xMax, int& yMax); // read from the first file
    BinaryTree* secondFileInput(string& secondFileName,int& seed); // read from the second file
    Forest* createForest(Point& targetPoint,BinaryTree* tree,int& xMin,int& yMin,int& xMax,int& yMax); // create forest
    void output(string& outputName , int numIteration , BinaryTree* droneTree); // print to the output file the results
    void printError(); // print error and end the program
    void checkPointInput(string& line); // check function to point input
    void checkNum(string& line); // check function to numbers input
    void checkTargetPoint(string& line); // check function to target point;
    void nextMove( Point& target ,bool& end,Forest* forest); // calculate the next move of each drone
    int checkSeed(string& seed); // check function to seed number for srand
    Drone* whichDrone(Point& vel, Point& loc , char& type , int& rand); // function that create and return pointer to the drone type
    void recursiveCreateHelp(Node* root,Forest* forest,Point& targetPoint); // create forest recursive help function
    void recursiveOutput(ostream& outputFile,Node* root); // print to file help recursive function
    void recursiveNextMove(Node* root ,Point& target ,bool& end ,Forest* forest); // help recursive to calculate the next move
    void checkLimits(int& xMin,int& yMin,int& xMax,int& yMax); // check if the arguments in the limits bounders
}
#endif
