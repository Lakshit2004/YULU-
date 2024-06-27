#ifndef _STATION_H_
#define _STATION_H_
#include <string>
using namespace std;

class Station {
public:
    string station_name;
    double x_coord;
    double y_coord;
    int num_scooters;
    int num_cycles;
    int num_skateboards;

public:
    Station(const string& name, double x, double y, int scooters, int cycles, int skateboards);

    const string& get_station_name() const;
    double get_x_coord() const;
    double get_y_coord() const;

    bool rent_vehicle(const string& vehicle_type);
    void return_vehicle(const string& vehicle_type);

    friend double calculate_distance(const Station& station1, const Station& station2);


    //~Station();
};

#endif
