#include "station.h"
#include "User.h"
#include "User_database.h"
#include "vehicle.h"
#include "scooter.h"
#include "Cycle.h"
#include "Skateboard.h"
#include "Current_user.h"

#include<iostream>
#include<iomanip>
#include<chrono>

using namespace std;

void displayMenu();
void displayMenu2(User user);
void dst(Station station_a, Station station_b);
void display_station();

int main() {
    
    UserDatabase userDB;
    User user1("Ishan", "2k22/IT/75", 1000, 1, "abcd");
    User user2("Lakshit", "2k22/IT/94", 100, 2, "1234");
    userDB.addUser(user1);
    userDB.addUser(user2);

        //Station(const std::string& name, double x, double y, int scooters, int cycles, int skateboards);
    Station station1("Main Gate", 10.0, 2.3, 10, 5, 3);
    Station station2("Sports Complex", 1.5, 9.1, 3, 5, 0);
    Station station3("Boy's Hostel", 1.0, 2.2, 7, 10, 6);
    Station station4("Academic Block", 2.4, 3.0, 4, 1, 0);
    Station station5("OAT", 5.2, 5.6, 0, 2, 2);
    Station station6("Girl's Hostel", 8.0, 5.6, 3, 5, 1);

    // Scooter scooter;
    // Cycle cycle;
    // Skateboard skateboard;

    bool isRunning = true;
    Current_user current;
    


    while (isRunning) {
        displayMenu();

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string rollNumber, password;
                
                cout << "Enter your roll number: ";
                cin >> rollNumber;

                if (userDB.isRollNumberRegistered(rollNumber)) {
                    cout << "This roll number is already registered. Please choose a different one." << endl;
                } else {
                    cout<< "Enter Username: ";
                    string username;
                    cin>>username;
                    cout << "Enter your password: ";
                    cin >> password;
                    
                    cout << "Account created successfully." << endl;
                    User new_user(username, rollNumber, 0, 0, password);
                    userDB.addUser(new_user);
                }
                break;
            }
            case 2:{
                string roll, pass;
                cout<<endl<<"Enter your roll number: ";
                cin>>roll;
                cout<<"Enter your password: ";
                cin>>pass;

                bool is_logged_in = false;
                for(const User& user: userDB.get_users()){
                    if(user.get_roll_num() == roll && user.get_password()==pass){
                        is_logged_in = true;
                        break;
                    }
                }
                if(is_logged_in){
                    cout << endl << "Login successful" <<endl << endl;
                    vector<User> user = userDB.get_users();
                    for(auto i:user){
                        if(i.get_roll_num() == roll){
                            current.add_user(i);
                        }
                    }
                    
                    isRunning = false;
                }else{
                    cout<<"Login failed. Invalid username or password."<<endl;
                }

                break;
            }
            case 3:
                isRunning = false;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }

    

    User current_user = current.current_user.at(0);
    string name = current_user.get_username();
    //cout<<name<<endl;
    //displayMenu2(current_user);
    
    
    isRunning = true;
    while(isRunning){
        displayMenu2(current_user);

        int choice;
        cin>>choice;
        
        switch(choice){
            case 1:{
                current_user.purchase_subscription();
                break;
            }
            case 2:{
                    int sub = current_user.get_subscription();
                    if(sub == 1 || sub == 2 || sub == 3){
                    cout << left << setw(40) << "SELECT A STATION TO RENT FROM: " << endl;
                    cout << left << setw(40) << "Station 1: Main Gate" << endl;
                    cout << left << setw(40) << "Station 2: Sports Complex" << endl;
                    cout << left << setw(40) << "Station 3: Boy's Hostel" << endl;
                    cout << left << setw(40) << "Station 4: Academic Block" << endl;
                    cout << left << setw(40) << "Station 5: OAT" << endl;
                    cout << left << setw(40) << "Station 6: Girl's Hostel" << endl;
    
                    int a;
                    cin>>a;
                    Station station_a("none", 0, 0, 0, 0, 0);
                    switch(a){
                        case 1: {station_a = station1; break;}
                        case 2: {station_a = station2; break;}
                        case 3: {station_a = station3; break;}
                        case 4: {station_a = station4; break;}
                        case 5: {station_a = station5; break;}
                        case 6: {station_a = station6; break;}
                        default: {cout<<"Invalid option"<<endl; break;}
                    }
                    string name = station_a.get_station_name();
                    cout<<endl<<"Renting from " << name << " station" <<endl;
                    

                    cout << left <<setw(40) << "SELECT WHICH VEHICLE TO RENT: "<< endl;
                    cout << left << setw(40) << "1. Scooter" << endl;
                    cout << left << setw(40) << "2. Cycle" << endl;
                    cout << left << setw(40) << "3. Skateboard" << endl;
                    
                    bool rented = false;
                    int choice;
                    cin>>choice;
                    switch(choice){
                        case 1: { if(station_a.rent_vehicle("scooter")){rented = true;} break; }
                        case 2: { if(station_a.rent_vehicle("cycle")){rented = true;} break;}
                        case 3: {if(station_a.rent_vehicle("skateboard")){rented = true;} break;}
                        default: {cout << "Invalid choice"<<endl;break;}
                    }
                    if(rented){
                    auto startTime = chrono::high_resolution_clock::now();
                    cout<<"Timer started. Click enter ride ends."<<endl;
                    cin.ignore();//Clear the newline character from the previous input
                    cin.get(); //wait for enter key
                     
                    // Get the current time when the user stops the timer
                    auto endTime = chrono::high_resolution_clock::now();
    
                    // Calculate the elapsed time
                    chrono::duration<double> elapsed = endTime - startTime;
    
                    cout << "Duration of ride: " << elapsed.count() << " seconds" << endl;
                    }
                    }
                    else{
                        cout<<"Please purchase a subscription"<<endl;
                    }
                    break;

            }
            case 3:{
                display_station();
                int a, b;
                cin>>a;
                cin>>b;
                Station station_a("none", 0, 0, 0, 0, 0);
                Station station_b("none", 0, 0, 0, 0, 0);
                switch(a){
                    case 1: {station_a = station1; break;}
                    case 2: {station_a = station2; break;}
                    case 3: {station_a = station3; break;}
                    case 4: {station_a = station4; break;}
                    case 5: {station_a = station5; break;}
                    case 6: {station_a = station6; break;}
                    default: {cout<<"Invalid option"<<endl; break;}
                }
                switch(b){
                    case 1: {station_b = station1; break;}
                    case 2: {station_b = station2; break;}
                    case 3: {station_b = station3; break;}
                    case 4: {station_b = station4; break;}
                    case 5: {station_b = station5; break;}
                    case 6: {station_b = station6; break;}
                    default: {cout<<"Invalid option"<<endl; break;}
                }
                dst(station_a, station_b);
                
                break;
            }
            case 4:{
                cout<<"Goodbye...";
                isRunning = false;
                break;
            }
            default:{
                cout<<"Invalid choice"<<endl;
                break;
            }
        }
    }

    

    return 0;
}



void displayMenu() {
    cout << left << setw(40) << "Welcome to User Registration System" << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
    cout << left << setw(40) << "1. Create an Account" << endl;
    cout << left << setw(40) << "2. Login" << endl;
    cout << left << setw(40) << "3. Exit" << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
    cout << "Enter your choice: ";
}

void displayMenu2(User user) {
    int subscription = user.get_subscription();
    int wallet = user.get_wallet();
    string name = user.get_username();
    cout << endl << left << name <<endl;
    cout << left << "Current subscription: " << subscription  << "\t\t" << "Wallet: " << wallet <<  endl;
    cout << left << setw(40) << "Select an option: " << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
    cout << left << setw(40) << "1. Change subscription" << endl;
    cout << left << setw(40) << "2. Rent" << endl;
    cout << left << setw(40) << "3. Find distance between two stations (map to be icorporated soon)" << endl;
    cout << left << setw(40) << "4. Exit" << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
    cout << "Enter your choice: ";
}


void dst(Station station_a, Station station_b){
        double distance = calculate_distance(station_a, station_b);
        cout << "Distance between " << station_a.get_station_name() << " and " << station_b.get_station_name() << ": " << distance/10 << " kilometers" << endl;
    }

void display_station(){
    cout << left << setw(40) << "SELECT TWO STATIONS: " << endl;
    cout << left << setw(40) << "Station 1: Main Gate" << endl;
    cout << left << setw(40) << "Station 2: Sports Complex" << endl;
    cout << left << setw(40) << "Station 3: Boy's Hostel" << endl;
    cout << left << setw(40) << "Station 4: Academic Block" << endl;
    cout << left << setw(40) << "Station 5: OAT" << endl;
    cout << left << setw(40) << "Station 6: Girl's Hostel" << endl;
}



    // // DISPLAY LIST OF USERS
    // cout<<"List of users"<<endl;
    // vector<User> user = userDB.get_users();
    // for(auto i:user){
    //     string name = i.get_username();
    //     cout<< name <<endl;
    // }
