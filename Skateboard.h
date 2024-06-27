#ifndef SKATEBOARD_H
#define SKATEBOARD_H

#include "Vehicle.h"

class Skateboard : public Vehicle {
public:
    Skateboard(int serial, int battery, double timeConstant, int maxSpeed);
    // double cost_distance() const override;
};

#endif
