#include <iostream>
#include "user.h"
#include "pasien.h"

using namespace std;

/* ================= MENU ADMIN ================= *///
void menuAdmin() {
    int pilih;
    do {
        cout << "\n=== MENU ADMIN ===\n";
        cout << "1. Tambah Pasien\n";
        cout << "2. Lihat Semua Pasien\n";
        cout << "3. Logout\n";
        cout << "4. Ganti Password\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                tambahPasien();
                break;
            case 2:
                tampilSemuaPasien();
                break;
            case 3:
                cout << "Logout admin...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 3);
}

/* ================= MENU PASIEN ================= */
void menuPasien() {
    int pilih;
    do {
        cout << "\n=== MENU PASIEN ===\n";
        cout << "1. Lihat Data Saya\n";
        cout << "2. Lihat Antrian\n";
        cout << "3. Edit Profil\n";
        cout << "4. Logout\n";
        cout << "5. Ganti Password\n";

        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                tampilPasienByID(currentPasienID);
                break;
            case 2:
                tampilAntrian(currentPasienID);
                break;
            case 3:
                editProfilPasien(currentPasienID);
                break;
            case 4:
                cout << "Logout pasien...\n";
                break;
            case 5:
                gantiPassword();
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 4);
}

/* ================= MAIN ================= */
int main() {
    loadUserDariFile();
    loadPasien();

    int menu;
    do {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Register (Admin / Pasien)\n";
        cout << "2. Login Admin\n";
        cout << "3. Login Pasien\n";
        cout << "4. Exit\n";
        cout << "Pilih: ";
        cin >> menu;

        switch (menu) {
            case 1:
                registerUser();
                break;

            case 2:
                if (login("ADMIN"))
                    menuAdmin();
                else
                    cout << "Login admin gagal!\n";
                break;

            case 3:
                if (login("PASIEN"))
                    menuPasien();
                else
                    cout << "Login pasien gagal!\n";
                break;

            case 4:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Menu tidak valid!\n";
        }

    } while (menu != 4);

    return 0;
}
