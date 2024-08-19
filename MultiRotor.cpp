
#include "MultiRotor.h"

// default constructor
MultiRotor::MultiRotor():Drone(){}
//  constructor
MultiRotor::MultiRotor(Point &vel, Point &loc,int& random) : Drone(vel, loc, 'M',random){}
// copy constructor
MultiRotor::MultiRotor(const MultiRotor &other):Drone(other){}
// operator =
MultiRotor &MultiRotor::operator=(const MultiRotor &other) {
    if(this != &other ){
        Drone::operator=(other);
    }
    return *this;
}
// print function to ostream
ostream &MultiRotor::print(ostream &os) {
    double x = this->getLocation().getX();
    double y = this->getLocation().getY();
    os << this->getDroneType() << " ";
    if(fmod(x*100,100) != 0){ // check if there is digits after decimal point
        if(fmod(x*100,10) != 0){ // check if there is two digit after decimal point
            os << fixed << setprecision(2) << x << " ";
        }
        else{
            os << fixed << setprecision(1) << x << " ";
        }
    }
    else{
        os << (int) x << " ";
    }
    if(fmod(y*100,100) != 0){ // check if there is digits after decimal point
        if(fmod(y*100,10) != 0){ // check if there is two digit after decimal point
            os << fixed << setprecision(2) << y << endl;
        } else{
            os << fixed << setprecision(1) << y << endl;
        }
    }
    else{
        os << (int) y << endl;
    }
    return os ;
}
// calculate the next location
void MultiRotor::nextLocation() {
    this->prevLocation = this->location;
    this->location = this->location + this->velocity;
    this->location= Point::limit(this->location);
}
// calculate the next velocity
void MultiRotor::nextVelocity() {
    srand(random == 0? time(nullptr):random);
    double r1 = (double)rand() / (double)RAND_MAX ;
    double r2 = (double)rand() / (double)RAND_MAX ;
    this->velocity = (this->velocity*a) + (this->personalBest-this->prevLocation)*r1*b
            + (getGlobalBest() - this->prevLocation)*r2*c;
}










