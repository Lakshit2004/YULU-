#ifndef _VEHICLE_H_
#define _VEHICLE_H_
#include <iostream>
using namespace std;

class Vehicle {
protected:
    
    int serial_numeber;
    int battery;
    double time_constant;
    int max_speed;
    

public:
    
    int get_serial_number();
    int get_max_speed();
    int get_battery();
    double get_time_constant();

    void set_serial_number(int s);
    void set_max_speed(int m);
    void set_battery(int b);
    void set_time_constant(int t);
    

    // virtual double cost_distatance() const = 0;
    
    // // Virtual destructor (recommended for polymorphic base classes)
    // virtual ~Vehicle() = default;
};





#endif