#ifndef CURRENT_USER_H
#define CURRENT_USER_H
#include "User.h"
#include<vector>
using namespace std;

class Current_user{
    public:
    vector<User>current_user;
    
    void add_user(User user);

    

    void remove_user();
};

#endif