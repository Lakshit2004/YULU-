#ifndef CYCLE_H
#define CYCLE_H

#include "Vehicle.h"

class Cycle : public Vehicle {
public:
    Cycle(int serial, int battery, double timeConstant, int maxSpeed);
    // double cost_distance() const override;
};

#endif
