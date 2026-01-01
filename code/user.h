#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

struct User {
    string username;
    string password;
};

bool login();
void registerUser();

#endif
