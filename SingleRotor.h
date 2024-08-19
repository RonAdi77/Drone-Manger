#ifndef EX2_SINGLEROTOR_H
#define EX2_SINGLEROTOR_H
#include "Drone.h"
// this class inherit in virtual inheritance from the abstract class drone
class SingleRotor :virtual public Drone{
private:
    // const field to use in calculate the next velocity
    const double a = 0.01;
    const double b = -0.1;
    const double c = -0.25;

public:
    SingleRotor();// default constructor
    SingleRotor(Point& vel , Point& loc,int& random);//  constructor
    SingleRotor(const SingleRotor& other);// copy constructor
     ~SingleRotor() override= default; // destructor
    SingleRotor& operator=(const SingleRotor& other); // operator =

    ostream& print(ostream& os) override; // print function
    void nextLocation() override; // calculate next location
    void nextVelocity() override; // calculate next velocity
};

#endif //EX2_SINGLEROTOR_H
