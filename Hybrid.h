
#ifndef EX2_HYBRID_H
#define EX2_HYBRID_H
#include "SingleRotor.h"
#include "FixedWing.h"
// this class inherit from SingleRotor and FixedWing that inherit from the abstract class drone
class Hybrid :public SingleRotor, public FixedWing{

public:
    Hybrid(); // default constructor
    Hybrid(Point& vel , Point& loc,int& random); //  constructor
    Hybrid(const Hybrid& other);// copy constructor
     ~Hybrid() override = default; // destructor
    Hybrid& operator=(const Hybrid& other); // operator =

    ostream& print(ostream& os) override; // print function
     void nextLocation() override; // calculate next location
     void nextVelocity() override; // calculate next velocity


};


#endif //EX2_HYBRID_H
