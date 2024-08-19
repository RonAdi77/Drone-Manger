
#include "Hybrid.h"
//default  constructor
Hybrid::Hybrid():Drone(){}
//  constructor
Hybrid::Hybrid(Point &vel, Point &loc, int &random) : Drone(vel, loc, 'H', random) {}
// copy constructor
Hybrid::Hybrid(const Hybrid &other):Drone(other){}
// operator =
Hybrid &Hybrid::operator=(const Hybrid &other) {
    if(this != &other){
        Drone::operator=(other);
    }
    return *this;
}
// call for SingleRotor print
ostream &Hybrid::print(ostream &os) {
    return SingleRotor::print(os);
}
// call for SingleRotor next location
void Hybrid::nextLocation() {
    SingleRotor::nextLocation();
}
// call for SingleRotor next velocity
void Hybrid::nextVelocity() {
    SingleRotor::nextVelocity();
}
























