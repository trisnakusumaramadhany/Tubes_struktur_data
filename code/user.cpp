#include "user.h"
#include <iostream>
using namespace std;

User users[10];
int totalUser = 0;

bool login() {
    string u, p;
    cout << "\n=== LOGIN ===\n";
    cout << "Username: ";
    cin >> u;
    cout << "Password: ";
    cin >> p;

    for (int i = 0; i < totalUser; i++) {
        if (users[i].username == u && users[i].password == p) {
            cout << "Login berhasil!\n";
            return true;
        }
    }
    cout << "Login gagal!\n";
    return false;
}

void registerUser() {
    cout << "\n=== REGISTER ===\n";
    cout << "Username: ";
    cin >> users[totalUser].username;
    cout << "Password: ";
    cin >> users[totalUser].password;
    totalUser++;

    cout << "Registrasi berhasil!\n";
}
