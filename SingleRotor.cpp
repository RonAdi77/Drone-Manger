#include "SingleRotor.h"
// default constructor
SingleRotor::SingleRotor():Drone(){}
//  constructor
SingleRotor::SingleRotor(Point &vel, Point &loc, int &random) : Drone(vel, loc, 'S', random) {}
// copy constructor
SingleRotor::SingleRotor(const SingleRotor &other):Drone(other) {}
// operator =
SingleRotor &SingleRotor::operator=(const SingleRotor &other) {
    if(this != &other){
        Drone::operator=(other);
    }
    return *this;
}
// print function to ostream
ostream &SingleRotor::print(ostream &os) {
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
void SingleRotor::nextLocation() {
    this->prevLocation = this->location;
    this->location = this->location + this->velocity;
    this->location= Point::limit(this->location);
}

// calculate the next velocity
void SingleRotor::nextVelocity() {
    srand(random == 0? time(nullptr):random);
    double r1 = (double)rand() / (double)RAND_MAX ;
    double r2 = (double)rand() / (double)RAND_MAX ;
    this->velocity = (this->velocity*a) + (this->personalBest-this->prevLocation)*r1*b
                     + (getGlobalBest() - this->prevLocation)*r2*c;
}














