
#ifndef EX2_FIXEDWING_H
#define EX2_FIXEDWING_H
#include "Drone.h"

// this class inherit in virtual inheritance from the abstract class drone
class FixedWing :virtual public Drone{
private:
    // const field to use in calculate the next velocity
    const double a = 0.25;
    const double b = 1;
    const double c = 1;

public:
    FixedWing(); // default constructor
    FixedWing(Point& vel , Point& loc,int& random); // constructor
    FixedWing(const FixedWing& other); // copy constructor
     ~FixedWing() override = default; // destructor
    FixedWing& operator=(const FixedWing& other); // operator =

    ostream& print(ostream& os) override; // print function
    void nextLocation() override; // calculate next location
    void nextVelocity() override; // calculate next velocity

};


#endif //EX2_FIXEDWING_H
