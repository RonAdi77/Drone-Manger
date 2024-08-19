
#ifndef EX2_MULTIROTOR_H
#define EX2_MULTIROTOR_H
#include "Drone.h"
// this class inherit  from the abstract class drone
class MultiRotor :virtual public Drone{
private:
    // const field to use in calculate the next velocity
    const double a = 0.05;
    const double b = 0.1;
    const double c = 0;
public:
    MultiRotor(); // default constructor
    MultiRotor(Point& vel , Point& loc,int& random);//  constructor
    MultiRotor(const MultiRotor& other);// copy constructor
    ~MultiRotor() override = default; //destructor
    MultiRotor& operator=(const MultiRotor& other); // operator =

    ostream& print(ostream& os) override;// print function
    void nextLocation() override; // calculate next location
    void nextVelocity() override; // calculate next velocity


};


#endif //EX2_MULTIROTOR_H
