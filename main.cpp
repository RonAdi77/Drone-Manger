#include "Help.h"

int main(int argc , char** argv) {
    if(argc != 4 && argc != 5){// check if the send argument to the program different then 4 or 5
        help::printError();
    }
    string firstFileName = argv[1],secondFileName = argv[2],outputFileName = argv[3],seed ;
    int iteration = 0,numIteration = 0,xMin=0,yMin=0,xMax=0,yMax=0,random=0;
    if(argc == 5){ // check if there is a seed argument to srand function and convert to int
        seed = argv[4];
        random = help::checkSeed(seed);
    }
    Point targetPoint = help::firstFileInput(iteration,firstFileName,xMin,yMin,xMax,yMax); // create the target point
    BinaryTree* tree = help::secondFileInput(secondFileName,random); // create the drone array
    Forest* forest =  help::createForest(targetPoint,tree,xMin,yMin,xMax,yMax); // create the forest
    bool end = false;
    while (numIteration < iteration){
        help::nextMove(targetPoint,end,forest); // calculate next move to each drone
        numIteration++;
        if(end){ // if a drone is in the same cell of the target point
            break;
        }
    }
    help::output(outputFileName,numIteration,forest->getDroneTree()); // print the result to the output file
    return 0;
}





















