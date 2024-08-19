
#ifndef EX2_DRONE_H
#define EX2_DRONE_H
#include "Point.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
class Drone {
private:
    static unsigned int id; // static id that increase every creation of drone object
    unsigned int personalId; // personal id of this drone
protected:
    Point location; // location point
    Point velocity; // velocity point
    Point personalBest; // personal best point
    Point prevLocation;  // help point to save the previous location
    static Point globalBest;
    static Point newGlobalBest; // help point to save the current global best at this point time
    char droneType; // the type of the inheritance drone class
    int random; // the seed number to the srand function
public:
    Drone(); // default constructor
    Drone(Point& vel , Point& loc,const char&  type,int& random); // constructor
    Drone(const Drone& other); // copy constructor
    virtual ~Drone()= default; // destructor

    Drone& operator=(const Drone& other); // operator =

    // getters and setters
    unsigned int getId()const{return this->personalId;}
    Point getVelocity()const{return this->velocity;}
    Point getLocation()const{return this->location;}
    Point getPrevLocation() const{return this->prevLocation;}
    Point getPersonalBest()const{return this->personalBest;}
    char getDroneType() const{return this->droneType;}
    int getRandom() const {return this->random;}
    void setPersonalBest(Point& p){this->personalBest = p;}
    void move() ; // call to nextLocation and nextVelocity

    // pure virtual functions , make this class to be abstract class
    virtual ostream& print(ostream& os) = 0;
    virtual void nextLocation() = 0; // calculate next location
    virtual void nextVelocity() = 0; // calculate next velocity

    // static functions
    static Point& getGlobalBest(){return Drone::globalBest;}
    static Point& getNewGlobalBest(){return Drone::newGlobalBest;}
    static void setGlobalBest(Point& point){globalBest = point; }
    static void setNewGlobalBest(Point& point){newGlobalBest = point;}

    // friend operator
    friend  bool operator<(const Drone& leftDrone , const Drone& rightDrone);
    friend ostream& operator<<(ostream& out, Drone& drone);

};






#endif
