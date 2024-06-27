#ifndef _USER_DATABASE_H_
#define _USER_DATABASE_H_
#include <iostream>
#include <vector>
#include "User.h"
using namespace std;


class UserDatabase {
private:
    vector<User> users;

public:
    // Function to add a new user
    void addUser(const User& user);

    // Function to check if a roll number is already registered
    bool isRollNumberRegistered(const string& rollNumber);

    //function to check if user is logged in
    bool is_logged_in(const string& roll_number, const string& password);

    //function that returns the list of users
    vector<User>& get_users() ;
};






#endif