#include "User.h"
#include "User_database.h"
#include<iostream>
#include<string>
#include <iomanip>


void UserDatabase::addUser(const User& user) {
        users.push_back(user);
    }


bool UserDatabase::isRollNumberRegistered(const string& rollNumber) {
        for ( User& user : users) {
            string r = user.get_roll_num();
            if (r == rollNumber) {
                return true;
            }
        }
        return false;
    }

//function to check if user is logged in
    bool UserDatabase::is_logged_in(const string& roll_number, const string& password){
        for(const User& user: users){
            if (user.get_roll_num() == roll_number && user.get_password() == password) {
            return true;
        }
    }
    return false;
}
        
  
    //function that returns the list of users
    vector<User>& UserDatabase::get_users() {
        return users;
    }

