#include "pasien.h"
#include <iostream>
#include <fstream>
using namespace std;

Pasien p[50];
int total = 0;

/* ================= FILE ================= */
void loadPasien() {
    ifstream f("pasien.txt");
    total = 0;

    while (getline(f, p[total].id, '|') &&
           getline(f, p[total].nama, '|') &&
           (f >> p[total].umur) &&
           f.get() &&
           getline(f, p[total].alamat, '|') &&
           getline(f, p[total].telp, '|') &&
           getline(f, p[total].keluhan)) {

        total++;
    }

    f.close();
}

void simpanPasien() {
    ofstream f("pasien.txt");
    for (int i = 0; i < total; i++) {
        f << p[i].id << "|"
          << p[i].nama << "|"
          << p[i].umur << "|"
          << p[i].alamat << "|"
          << p[i].telp << "|"
          << p[i].keluhan << endl;
    }
    f.close();
}

/* ================= ADMIN ================= */
void tambahPasien() {

    if (total >= 50) {
        cout << "Data pasien penuh!\n";
        return;
    }

    cout << "ID Pasien   : ";
    cin >> p[total].id;

    cout << "Nama        : ";
    cin.ignore();
    getline(cin, p[total].nama);

    cout << "Umur        : ";
    cin >> p[total].umur;
    cin.ignore();

    cout << "Alamat      : ";
    getline(cin, p[total].alamat);

    cout << "Telepon     : ";
    getline(cin, p[total].telp);

    cout << "Keluhan     : ";
    getline(cin, p[total].keluhan);

    total++;
    simpanPasien();

    cout << "Pasien berhasil ditambahkan.\n";
}

void tampilSemuaPasien() {

    if (total == 0) {
        cout << "Belum ada data pasien.\n";
        return;
    }

    cout << "\n=== DATA SEMUA PASIEN ===\n";

    for (int i = 0; i < total; i++) {

        cout << "\n-------------------------\n";
        cout << "Pasien ke-" << i + 1 << endl;
        cout << "ID      : " << p[i].id << endl;
        cout << "Nama    : " << p[i].nama << endl;
        cout << "Umur    : " << p[i].umur << endl;
        cout << "Alamat  : " << p[i].alamat << endl;
        cout << "Telepon : " << p[i].telp << endl;
        cout << "Keluhan : " << p[i].keluhan << endl;
    }
}

/* ================= PASIEN ================= */
void tampilPasienByID(string id) {

    for (int i = 0; i < total; i++) {
        if (p[i].id == id) {
            cout << "Nama    : " << p[i].nama << endl;
            cout << "Umur    : " << p[i].umur << endl;
            cout << "Alamat  : " << p[i].alamat << endl;
            cout << "Telp    : " << p[i].telp << endl;
            cout << "Keluhan : " << p[i].keluhan << endl;
            return;
        }
    }

    cout << "Data pasien tidak ditemukan.\n";
}

void editProfilPasien(string id) {

    for (int i = 0; i < total; i++) {
        if (p[i].id == id) {

            cin.ignore();
            cout << "Alamat baru  : ";
            getline(cin, p[i].alamat);

            cout << "Telepon baru : ";
            getline(cin, p[i].telp);

            simpanPasien();

            cout << "Profil berhasil diperbarui.\n";
            return;
        }
    }

    cout << "Data pasien tidak ditemukan.\n";
}

void tampilAntrian(string id) {

    for (int i = 0; i < total; i++) {
        if (p[i].id == id) {
            cout << "Nomor antrian anda: " << i + 1 << endl;
            return;
        }
    }

    cout << "Anda belum terdaftar sebagai pasien.\n";
}
