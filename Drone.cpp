
#include "Drone.h"

unsigned int Drone::id = 0; // initialization of the static id
Point Drone::globalBest = Point(); // initialization of the global best
Point Drone::newGlobalBest = Point(); // initialization of the new global best

// default constructor
Drone::Drone():personalId(id++),location(Point()),velocity(Point()),personalBest(Point()),prevLocation(Point()),droneType('\0'),random(0){}

// constructor
Drone::Drone(Point& vel, Point& loc,const char &type,int& random):personalId(id++),location(loc),velocity(vel),personalBest(Point())
,prevLocation(Point()),droneType(type),random(random){}

// copy constructor
Drone::Drone(const Drone &other):personalId(other.getId()),location(other.getLocation()),velocity(other.getVelocity())
,personalBest(other.getPersonalBest()),prevLocation(other.getPrevLocation()),droneType(other.getDroneType()),random(other.getRandom()){}

// operator =
Drone &Drone::operator=(const Drone &other) {
    if(this == &other){
        return *this;
    }
    this->personalId = other.getId();
    this->velocity = other.getVelocity();
    this->location = other.getLocation();
    this->personalBest = other.getPersonalBest();
    this->droneType = other.getDroneType();
    this->random = other.getRandom();
    return *this;
}

 /** this function  calculate the next location and velocity
 */
void Drone::move(){
    this->nextLocation();
    this->nextVelocity();
}

// return true if the id of the left drone is lower than the id of the right drone
bool operator<(const Drone &leftDrone, const Drone &rightDrone) {
    return leftDrone.getId() < rightDrone.getId();
}

// print the drone to the ostream
ostream &operator<<(ostream &out, Drone& drone) {
    return drone.print(out);
}













