#include "station.h"
#include <cmath>
#include <iostream>
using namespace std;

Station::Station(const string& name, double x, double y, int scooters, int cycles, int skateboards)
    : station_name(name), x_coord(x), y_coord(y), num_scooters(scooters), num_cycles(cycles), num_skateboards(skateboards) {}

// Station::~Station(){
//     std::cout << "Station "<< station_name << " is being deleted." << std::endl;
//     delete station_name;
//     delete x_coord;
//     delete y_coord;
//     delete num_scooters;
//     delete num_cycles;
//     delete num_skateboards;
// }

const string& Station::get_station_name() const {
    return station_name;
}

double Station::get_x_coord() const {
    return x_coord;
}

double Station::get_y_coord() const {
    return y_coord;
}

bool Station::rent_vehicle(const string& vehicle_type) {
        if (vehicle_type == "scooter" && num_scooters > 0) {
            num_scooters--;
            cout << "Scooter rented from " << station_name << endl;
            return true;
        }
        else if (vehicle_type == "cycle" && num_cycles > 0) {
            num_cycles--;
            cout << "Cycle rented from " << station_name << endl;
            return true;
        }
        else if (vehicle_type == "skateboard" && num_skateboards > 0) {
            num_skateboards--;
            cout << "Skateboard rented from " << station_name << endl;
            return true;
        }
        else {
            cout << "No available " << vehicle_type << " at " << station_name << endl;
            return false;
        }
    }

void Station::return_vehicle(const string& vehicle_type) {
        if (vehicle_type == "scooter") {
            num_scooters++;
            cout << "Scooter returned to " << station_name << endl;
        }
        else if (vehicle_type == "cycle") {
            num_cycles++;
            cout << "Cycle returned to " << station_name << endl;
        }
        else if (vehicle_type == "skateboard") {
            num_skateboards++;
            cout << "Skateboard returned to " << station_name << endl;
        }
        else {
            cout << "Invalid vehicle type returned at " << station_name << endl;
        }
    }

double calculate_distance(const Station& station1, const Station& station2) {
    double x1 = station1.x_coord;
    double y1 = station1.y_coord;
    double x2 = station2.x_coord;
    double y2 = station2.y_coord;

    double dx = x2 - x1;
    double dy = y2 - y1;

    return sqrt(dx * dx + dy * dy);
}




// int main() {
//     Station station1("Station A", 1.0, 2.0, 10, 5, 3);
//     Station station2("Station B", 3.0, 4.0, 12, 4, 2);

//     double distance = calculate_distance(station1, station2);
//     std::cout << "Distance between " << station1.get_station_name() << " and " << station2.get_station_name() << ": " << distance << std::endl;

//     return 0;
// }
