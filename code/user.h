#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

struct User {
    string username;
    string password;
    string role;      // ADMIN / PASIEN
    string pasienID;
};

bool login(string role);
void registerUser();
void loadUserDariFile();
void simpanUserKeFile();

extern string currentUser;
extern string currentRole;
extern string currentPasienID;

#endif
