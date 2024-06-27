#include "User.h"
#include "User_database.h"
#include<iostream>
#include<string>
#include <iomanip>

using namespace std;


//CONSTRUCTOR
User::User(string u, string r, int w, int s, string p)
    :username{u}, roll_num{r}, wallet{w}, subscription{s}, password{p}{}
    
//SETTERS
void User::set_username(string s){
    username = s;
}
void User::set_roll_num(string r){
    roll_num = r;
}
void User::set_wallet(int w){
    wallet = w;
}
void User::set_subscription(int s){
    subscription = s;
}
void User::set_password(string p){
    password = p;
}

//GETTERS
string User::get_username() const{
    return username;
}
string User::get_roll_num() const{
    return roll_num;
}
int User::get_wallet() const{
    return wallet;
}
int User::get_subscription() const{
    return subscription;
}
string User::get_password() const{
    return password;
}

//Displays the table of different tiers of subscriptions.
void User::display_subscription() {
    cout << left << setw(15) << "Subscription"
              << left << setw(25) << "Total Hours"
              << left << setw(20) << "Total Cost (Monthly)" << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

    cout << left << setw(15) << "Tier 1"
              << left << setw(25) << 2
              << left << setw(20) << "Rs 200" << endl;
    cout << left << setw(15) << "Tier 2"
              << left << setw(25) << 5
              << left << setw(20) << "Rs 400" << endl;
    cout << left << setw(15) << "Tier 3"
              << left << setw(25) << 8
              << left << setw(20) << "Rs 500" << endl;
}

//display sub, setter for sub, setter of wallet(deducting amount)->all functions are called inside this function
void User::purchase_subscription(){
    User::display_subscription();
    int option{0};
    cout<<"Select subscription tier(1/2/3): ";
    cin>>option;
    switch(option){
        case 1:{
            if(wallet>=200){
            cout<<"Tier 1 subscription choosen"<<endl;
            subscription = 1;
            wallet-=200;
            break;
            }else{
                cout<<"ERROR: Insufficient funds."<<endl;
                break;
            }
        }

        case 2:{
            if(wallet>=400){
            cout<<"Tier 2 subscription choosen"<<endl;
            subscription = 2;
            wallet-=400;
            break;
            }else{
                cout<<"ERROR: Insufficient funds."<<endl;
                break;
            }
        }
        
        case 3:{
            if(wallet>=500){
            cout<<"Tier 3 subscription choosen"<<endl;
            subscription = 3;
            wallet-=500;
            break;
            }else{
                cout<<"ERROR: Insufficient funds."<<endl;
                break;
            }
        }
        
        default:{
            cout<<"Invalid option"<<endl;
            break;
        }
    }
    
}

