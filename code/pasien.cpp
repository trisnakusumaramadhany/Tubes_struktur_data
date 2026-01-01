#include "pasien.h"
#include <iostream>
using namespace std;

Pasien daftarPasien[50];
int totalPasien = 0;

void tambahPasien() {
    if (totalPasien >= 50) {
        cout << "Data pasien sudah penuh!\n";
        return;
    }

    cout << "\n=== TAMBAH PASIEN ===\n";
    cout << "ID Pasien   : ";
    cin >> daftarPasien[totalPasien].id;
    cin.ignore();

    cout << "Nama Pasien : ";
    getline(cin, daftarPasien[totalPasien].nama);

    cout << "Umur        : ";
    cin >> daftarPasien[totalPasien].umur;
    cin.ignore();

    cout << "Keluhan     : ";
    getline(cin, daftarPasien[totalPasien].keluhan);

    totalPasien++;
    cout << "Pasien berhasil ditambahkan!\n";
}

void tampilPasien() {
    cout << "\n=== DAFTAR PASIEN ===\n";

    if (totalPasien == 0) {
        cout << "Belum ada data pasien.\n";
        return;
    }

    for (int i = 0; i < totalPasien; i++) {
        cout << "\nPasien ke-" << i + 1 << endl;
        cout << "ID      : " << daftarPasien[i].id << endl;
        cout << "Nama    : " << daftarPasien[i].nama << endl;
        cout << "Umur    : " << daftarPasien[i].umur << endl;
        cout << "Keluhan : " << daftarPasien[i].keluhan << endl;
    }
}
