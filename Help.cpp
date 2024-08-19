#include "Help.h"

 /**
  * @param iteration - number of iteration
  * @param firstFileName - the name of the first file
  * @param xMin - xMin value
  * @param yMin - yMin value
  * @param xMax - xMax value
  * @param yMax - yMax value
  * @return - target point
  * this function read from the first file the target point , the number of iteration and the bounders of the forest
  */
Point help::firstFileInput(int &iteration, string &firstFileName,int & xMin,int& yMin ,int& xMax, int& yMax) {
    ifstream firstFile(firstFileName);
    if(!firstFile.is_open()){printError();} // check if the first file is open
    string line;
    double targetX,targetYy;
    Point targetPoint;
    bool firstLine= false,secondLine = false;
    while (getline(firstFile,line)){ // read from the first file
        stringstream s(line);
        if(!firstLine && !secondLine){
            s >> xMin >> yMin >> xMax >> yMax;
            checkLimits(xMin,yMin,xMax,yMax); // check if the bounders are in the limit
            if(xMax < xMin || yMax < yMin){printError();}
            firstLine = true;
        }
        else if(firstLine && !secondLine){
            checkTargetPoint(line); // check if the target point input in the right format
            s >> targetX >> targetYy;
            targetPoint = *new Point(targetX,targetYy); // create the target point
            secondLine = true;
        }
        else if(firstLine && secondLine){
            checkNum(line); // check if the number of iteration input is a number
            s >> iteration;
        }
    }
    firstFile.close();
    return targetPoint;
}
// this function check if the bounders are out of the limits the forest can be
void help::checkLimits(int &xMin, int &yMin, int &xMax, int &yMax) {
    if(xMin < 0){xMin = 0;}
    if(yMin < 0){yMin = 0;}
    if(xMax > 72){xMax = 72;}
    if(yMax > 42){yMax =42;}
}
 /**
  *
  * @param secondFileName -the name of the second file
  * @param seed - int number to srand
  * @return - binary tree that contain drones
  * this function read from the second file the number of drone and the location and velocity coordinate of each drone
 * and then return a binary tree of drones
  */
BinaryTree* help::secondFileInput(string &secondFileName,int& seed) {
    ifstream secondFile(secondFileName);
    if(!secondFile.is_open()){printError();}
    string line;
    double locationX , locationY , velocityX , velocityY;
    bool flag = false;
    unsigned int droneNum = 0;
    BinaryTree* tree;
    char droneType;
    while(getline(secondFile,line)){ // read the second input file
        stringstream s(line);
        if(!flag){
            checkNum(line); // check if the number of drones input is a number
            s >> droneNum;
            flag = true;
            tree = new BinaryTree(); // create an array of drone in size of the input number of drones
        }
        else{
            // in this scope there is creation of drone and add the drone to the array of drones
            checkPointInput(line); // check if the drone coordinate input in the right format
            s >> droneType >>locationX >> locationY >> velocityX >> velocityY;
            Point velocity = *new Point(velocityX,velocityY);
            Point location = *new Point (locationX,locationY);
            location = Point::limit(location); // check if the location is in the borders of the forest
            Drone* drone = whichDrone(velocity,location,droneType,seed);
            if(drone == nullptr){printError();}
            drone->setPersonalBest(location);
            tree->insert(drone);
        }
    }
    if (droneNum != tree->size()){printError();} // check if the real number of drones is the same in the input
    secondFile.close();
    return tree;

}
 /**
  * @param targetPoint - target point
  * @param tree - binary tree of drones
  * @param xMin - xMin value
  * @param yMin - yMin value
  * @param xMax - xMax value
  * @param yMax - yMax value
  * @return forest
  * this function create the forest and them initialize the number of drones in each cell in the beginning,
  * and initialize the global best
  */
Forest *help::createForest(Point& targetPoint,BinaryTree* tree,int& xMin,int& yMin,int& xMax,int& yMax) {
    Forest* forest = new Forest(targetPoint,tree,xMin,yMin,xMax,yMax); // create the forest
    // this recursive function initiate the numbers of the drone in the cell and find the global best in the beginning
    recursiveCreateHelp(forest->getDroneTree()->getHead(),forest,targetPoint);
    Drone::setGlobalBest(Drone::getNewGlobalBest()); // initialize the global best to the new coordinate
    return forest;
}
// help recursive help to initialize the number of drones in each cell in the beginning and initialize the global best,
// inOrder scan
void help::recursiveCreateHelp(Node *root,Forest* forest,Point& targetPoint) {
    if(root != nullptr){
        recursiveCreateHelp(root->getLeftTree(),forest, targetPoint);
        int initX = floor(root->getData()->getLocation().getX());
        int initY = floor(root->getData()->getLocation().getY());
        forest->getForestArray()[initX][initY]++;
        Point tmpPersonal = root->getData()->getPersonalBest();
        if(Point::distance(targetPoint,tmpPersonal) < Point::distance(targetPoint,Drone::getGlobalBest())){
            Drone::setNewGlobalBest(tmpPersonal);
        }
        recursiveCreateHelp(root->getRightTree(),forest,targetPoint);
    }
}

// this function print the result to the output file .
// the function checks if there are digits after the decimal point other than zero .
void help::output(string &outputName, int numIteration, BinaryTree* droneTree) {
    ofstream outputFile(outputName,ofstream::trunc);
    if(!outputFile.is_open()){printError();}
    outputFile << numIteration << endl;
    recursiveOutput(outputFile,droneTree->getHead());
    outputFile.close();
}

// this function print the drones to the output file in the order they were created and this is why this is in preOrder
void help::recursiveOutput(ostream& outputFile, Node *root) {
    if(root != nullptr){
        outputFile << *root->getData();
        recursiveOutput(outputFile,root->getLeftTree());
        recursiveOutput(outputFile,root->getRightTree());
    }
}
// this function print to the standard error if there is error on the input and end the program
void help::printError() {
    cerr << "Error; invalid input" << endl;
    exit(0);
}
// this function check if the drone number and iteration number input is a string of digits
void help::checkNum(string &line) {
    if(line.size() == 1){
        if(!isdigit(line[0])){
            printError();
        }
    }
    else{
        for (char i : line) {
            if(!isdigit(i)){
                printError();
            }
        }
    }
}


// this function check if the coordination of the drones are in the right format
void help::checkPointInput(string &line) {
    line.erase(0,2);
    int numSpace =0;
    for (unsigned int i = 0; i < line.size() - 1; ++i) {
        if(line[i] == ' '){
            numSpace++;
        }
        if(line[i] == ' ' && !isdigit(line[i+1]) && line[i+1] != '-'){
            printError();
        }
        if(line[i] == '-' && !isdigit(line[i+1])){
            printError();
        }
        if(isdigit(line[i]) && !isdigit(line[i+1]) && line[i+1] !=' ' && line[i+1] != '.'){
            printError();
        }
    }
    if(numSpace != 3){
        printError();
    }
}

// this function check if the coordination of the target point are in the right format
void help::checkTargetPoint(string &line) {
    int numSpace =0;
    for (unsigned int i = 0; i < line.size(); ++i) {
        if(line[i] == ' '){
            numSpace++;
        }
        if(line[i] == ' ' && !isdigit(line[i+1])){
            printError();
        }
        if(line[i] != ' ' && !isdigit(line[i]) && line[i] != '.'){
            printError();
        }
    }
    if(numSpace != 1){
        printError();
    }
}

 /**
  * this function calculate the next move of every drone
  * @param target - point target
  * @param end - help boolean if drone is in the cell of the target point
  * @param forest - the forest
  */
void help::nextMove(Point &target, bool &end, Forest* forest) {
    recursiveNextMove(forest->getDroneTree()->getHead(),target,end,forest);
    Drone::setGlobalBest(Drone::getNewGlobalBest()); // update the global best to the new coordinate
}

//this function calculate the next move of each drone in the tree in preOrder
void help::recursiveNextMove(Node *root, Point &target, bool &end,Forest* forest) {
    if(root != nullptr){
        root->getData()->move(); // calculate the next velocity and location of the current drone
        Point tmpPersonal = root->getData()->getPersonalBest();
        Point tmpLocation = root->getData()->getLocation();
        // check if current location of the current is the personal best of the drone
        if(Point::distance(target,tmpLocation) < Point::distance(target,tmpPersonal)){
            root->getData()->setPersonalBest(tmpLocation);
        }
        tmpPersonal = root->getData()->getPersonalBest();
        // check if the current personal best of the current drone is the global best and update the leader drone
        if(Point::distance(target,tmpPersonal) < Point::distance(target,Drone::getGlobalBest())){
            Drone::setNewGlobalBest(tmpPersonal);
            Forest::setLeader(root->getData());
        }
        int x = floor(root->getData()->getLocation().getX());
        int y = floor(root->getData()->getLocation().getY());
        if(forest->getForestArray()[x][y].getIsTarget()){ // check if the drone is in the cell of the target point
            end = true;
            return;
        }
        forest->getForestArray()[x][y]++; // increase the number of drones in the cell the current drone move to him
        // check if the new location is different from the previous location
        if(root->getData()->getLocation() != root->getData()->getPrevLocation()){
            int prevX = floor(root->getData()->getPrevLocation().getX());
            int prevY = floor(root->getData()->getPrevLocation().getY());
            forest->getForestArray()[prevX][prevY]--; // decrease the number of drones in the cell the current drone move to him
        }
        recursiveNextMove(root->getLeftTree(),target,end,forest); // call to the left tree
        recursiveNextMove(root->getRightTree(),target,end,forest); // call to the right tree
    }
}
// this function check if the seed input is integer number
int help::checkSeed(string &seed) {
    for(unsigned int i = 0; i < seed.size()-1 ; i++){
        if(seed[i] == '-' && !isdigit(seed[i+1])){
            return 0;
        }
        if(isdigit(seed[i]) && !isdigit(seed[i+1])){
            return 0;
        }
    }
    return stoi(seed);
}
/**
 * @param vel - velocity
 * @param loc - location
 * @param type - type of drone
 * @param rand - the random seed
 * @return returns a pointer to one of the classes inheriting from drone
 */
Drone *help::whichDrone(Point &vel, Point &loc, char &type, int &rand) {
    switch (type) {
        case 'S':
            return new SingleRotor(vel,loc,rand);
        case 'M':
            return new MultiRotor(vel,loc,rand);
        case 'W':
            return new FixedWing(vel,loc,rand);
        case 'H':
            return new Hybrid(vel,loc,rand);
        default:
            return nullptr;
    }
}

