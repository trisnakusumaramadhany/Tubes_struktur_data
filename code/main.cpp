#include <iostream>
#include "user.h"
#include "pasien.h"

using namespace std;


int main() {
    int pilihan;

    while (true) {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            registerUser();
        } 
        else if (pilihan == 2) {
            if (login()) {
                // masuk menu pasien jika login sukses
                int menuPasien;
                do {
                    cout << "\n=== MENU DATA PASIEN ===\n";
                    cout << "1. Tambah Pasien\n";
                    cout << "2. Tampilkan Pasien\n";
                    cout << "3. Logout\n";
                    cout << "Pilih menu: ";
                    cin >> menuPasien;

                    if (menuPasien == 1) {
                        tambahPasien();
                    } 
                    else if (menuPasien == 2) {
                        tampilPasien();
                    }

                } while (menuPasien != 3);
            }
        } 
        else if (pilihan == 3) {
            cout << "Program selesai.\n";
            break;
        } 
        else {
            cout << "Menu tidak valid!\n";
        }
    }

    return 0;
}
