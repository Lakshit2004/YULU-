#ifndef _USER_H_
#define _USER_H_
#include <iostream>
using namespace std;

class User{
    
protected:
    string username;
    string roll_num;  //students DTU roll number
    int wallet;   //current wallet balance
    int subscription; // subscription tier
    string password;
    

public:
    User(string u, string r, int w, int s, string p);

    void set_username(string s);
    void set_roll_num(string r);
    void set_wallet(int w);
    void set_subscription(int s);
    void set_password(string p);

    string get_username() const;
    string get_roll_num() const;
    int get_wallet() const;
    int get_subscription() const;
    string get_password() const;

    void display();

    void display_subscription(); //just displays a table of different subscription in detail

    void purchase_subscription(); //display sub, setter for sub, setter of wallet(deducting amount)->all functions are called inside this function
        
    

};



#endif
