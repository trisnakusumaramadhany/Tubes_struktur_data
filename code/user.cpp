#include "user.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
using namespace std;

User users[50];
int totalUser = 0;

/* GLOBAL STATE */
string currentUser = "";
string currentRole = "";
string currentPasienID = "";

/* ================= VALIDASI PASSWORD ================= */
bool validPassword(string pass) {
    if (pass.length() < 8) return false;

    bool capital = false;
    for (char c : pass)
        if (isupper(c)) capital = true;

    return capital;
}

/* ================= REGISTER ================= */
void registerUser() {

    string confirm;

    cout << "\n=== REGISTER USER ===\n";
    cout << "Role (ADMIN/PASIEN): ";
    cin >> users[totalUser].role;

    cout << "Username: ";
    cin >> users[totalUser].username;

    do {
        cout << "Password (min 8 & 1 huruf besar): ";
        cin >> users[totalUser].password;
        cout << "Konfirmasi Password: ";
        cin >> confirm;

        if (users[totalUser].password != confirm ||
            !validPassword(users[totalUser].password)) {
            cout << "Password tidak valid!\n";
        }

    } while (users[totalUser].password != confirm ||
             !validPassword(users[totalUser].password));

    if (users[totalUser].role == "PASIEN") {
        cout << "ID Pasien: ";
        cin >> users[totalUser].pasienID;
    } else {
        users[totalUser].pasienID = "-";
    }

    totalUser++;
    simpanUserKeFile();

    cout << "Registrasi berhasil!\n";
}

/* ================= LOGIN ================= */
bool login(string role) {

    string u, p;
    const int MAX_ATTEMPT = 2;
    int attempt = 0;

    while (true) {

        cout << "\n=== LOGIN " << role << " ===\n";
        cout << "Username: ";
        cin >> u;
        cout << "Password: ";
        cin >> p;

        for (int i = 0; i < totalUser; i++) {
            if (users[i].username == u &&
                users[i].password == p &&
                users[i].role == role) {

                currentUser = u;
                currentRole = role;
                currentPasienID = users[i].pasienID;

                cout << "Login berhasil!\n";
                return true;
            }
        }

        cout << "Login gagal!\n";
        attempt++;

        if (attempt < MAX_ATTEMPT) {
            cout << "Silakan coba lagi.\n";
            continue;
        }

        cout << "\nLogin salah 2 kali!\n";
        cout << "Login dikunci selama 30 detik...\n";

        for (int i = 30; i > 0; i--) {
            cout << "\rMohon Tunggu " << i << " detik...";
            cout.flush();
            this_thread::sleep_for(chrono::seconds(1));
        }

        attempt = 0;
        cout << "\nSilakan login kembali.\n";
    }
}

/* ================= FILE ================= */
void simpanUserKeFile() {
    ofstream file("user.txt");
    for (int i = 0; i < totalUser; i++) {
        file << users[i].username << " "
             << users[i].password << " "
             << users[i].role << " "
             << users[i].pasienID << endl;
    }
    file.close();
}

void loadUserDariFile() {
    ifstream file("user.txt");
    totalUser = 0;

    while (file >> users[totalUser].username
                >> users[totalUser].password
                >> users[totalUser].role
                >> users[totalUser].pasienID) {
        totalUser++;
    }

    file.close();
}
void gantiPassword() {

    string passLama, passBaru, konfirmasi;

    cout << "\n=== GANTI PASSWORD ===\n";
    cout << "Password lama: ";
    cin >> passLama;

    // cari user yang sedang login
    for (int i = 0; i < totalUser; i++) {

        if (users[i].username == currentUser &&
            users[i].password == passLama) {

            do {
                cout << "Password baru: ";
                cin >> passBaru;
                cout << "Konfirmasi password: ";
                cin >> konfirmasi;

                if (passBaru != konfirmasi || !validPassword(passBaru)) {
                    cout << "Password tidak valid!\n";
                }

            } while (passBaru != konfirmasi || !validPassword(passBaru));

            // 🔁 GANTI DI ARRAY
            users[i].password = passBaru;

            // 💾 SIMPAN KE FILE
            simpanUserKeFile();

            cout << "Password berhasil diubah.\n";
            return;
        }
    }

    cout << "Password lama salah!\n";
}
