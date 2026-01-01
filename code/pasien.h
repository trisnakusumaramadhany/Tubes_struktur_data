#ifndef PASIEN_H
#define PASIEN_H

#include <string>
using namespace std;

struct Pasien {
    string id, nama, alamat, telp, keluhan;
    int umur;
};

void loadPasien();
void simpanPasien();

void tambahPasien();
void tampilSemuaPasien();

void tampilPasienByID(string id);
void editProfilPasien(string id);
void tampilAntrian(string id);

#endif
