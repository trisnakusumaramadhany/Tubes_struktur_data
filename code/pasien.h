#ifndef PASIEN_H
#define PASIEN_H

#include <string>

struct Pasien {
    std::string id;
    std::string nama;
    int umur;
    std::string keluhan;
};

void tambahPasien();
void tampilPasien();

#endif
