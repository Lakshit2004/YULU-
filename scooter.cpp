#include "Scooter.h"

Scooter::Scooter(int serial, int battery, double timeConstant, int maxSpeed) {
    set_serial_number(serial);
    set_battery(battery);
    set_time_constant(timeConstant);
    set_max_speed(maxSpeed);
}

// double Scooter::cost_distance() const {
//     // Implement cost calculation for a scooter
//     // You can define the cost calculation logic here
//     return 0.0;
// }
