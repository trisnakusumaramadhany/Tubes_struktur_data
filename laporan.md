# Laporan Pembuatan Sistem Antrian Rumah Sakit Berbasis C++

## 1. Anggota Kelompok 6

Nama : M.Rafi maulana / 103112400264

Nama : Satria Adhi Sadarma  / 103112400273

Nama : Trisna Kusuma Ramadhany / 103112400277

---

## 2. Latar Belakang

Rumah sakit merupakan salah satu fasilitas pelayanan kesehatan yang memiliki tingkat kunjungan pasien yang tinggi setiap harinya. Banyaknya pasien yang datang sering kali menimbulkan permasalahan dalam pengelolaan antrian, pendataan pasien, serta pencatatan informasi pelayanan. Apabila proses tersebut masih dilakukan secara manual, maka berpotensi menimbulkan kesalahan pencatatan, antrian yang tidak teratur, serta pelayanan yang kurang efisien.

Oleh karena itu, dibutuhkan sebuah sistem antrian rumah sakit yang terkomputerisasi untuk membantu proses pendaftaran, pengelolaan data pasien, serta pengaturan antrian secara sistematis. Sistem Antrian Rumah Sakit berbasis C++ ini dirancang untuk memudahkan admin dalam mengelola data pasien dan membantu pasien dalam melihat data diri serta posisi antriannya. Dengan memanfaatkan konsep struktur data dan pemrograman modular, sistem ini diharapkan mampu meningkatkan efektivitas dan ketertiban dalam pelayanan rumah sakit.

---

## 3. Pembagian Tugas

### 3.1 Tugas yang Dikerjakan M.Rafi maulana

*  berperan dalam pengembangan fitur keamanan akun, khususnya fitur ganti password, pengelolaan penyimpanan data password, pembaruan use case diagram

### 3.2 Tugas yang Dikerjakan Satria Adhi Sadarma

*  pengembangan fitur pengelolaan data pasien, yang meliputi pembuatan dan implementasi kode pada pasien.h, pasien.cpp, serta main.cpp sebagai pengatur alur utama program.

### 3.3 Tugas yang Dikerjakan Trisna Kusuma Ramadhany

* mengembangkan fitur manajemen pengguna, seperti login, registrasi, dan pengelolaan data user melalui file User.h dan User.cpp, serta menyusun bahan presentasi awal dalam bentuk PowerPoint.

---

## 5. Kesulitan Selama Mengerjakan Tugas Besar

Beberapa kesulitan yang dialami selama pengerjaan tugas besar ini antara lain:

* Menemukan serta memperbaiki ketika ada yang code error
* Kendala untuk membuat code dengan live share
* Kendala dalam mengembangan fitur di dalam sistem

Kesulitan tersebut dapat diatasi dengan pembagian tugas yang jelas serta pengujian program secara bertahap.

---

## 6. Program / Coding

### 6.1 pasien.h

```cpp
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

```

**Penjelasan:**
File `pasien.h` berfungsi sebagai header yang berisi struktur data Pasien serta deklarasi fungsi-fungsi yang berkaitan dengan pengelolaan data pasien. Struktur Pasien menyimpan informasi penting seperti ID, nama, umur, alamat, nomor telepon, dan keluhan pasien.

---

### 6.2 pasien.cpp

```cpp
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

```

**Penjelasan:**
File `pasien.cpp` berisi implementasi fungsi-fungsi yang dideklarasikan pada `pasien.h`. Fungsi-fungsi tersebut digunakan untuk memuat data pasien dari file, menyimpan data ke file, menambah pasien baru, menampilkan seluruh pasien, serta menampilkan dan mengedit data pasien berdasarkan ID. Selain itu, terdapat fungsi untuk menampilkan nomor antrian pasien berdasarkan urutan pendaftaran.

---

### 6.3 user.h

```cpp
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
```

**Penjelasan:**
File `user.h` digunakan untuk mendefinisikan struktur User dan deklarasi fungsi login serta registrasi. Struktur ini digunakan untuk membedakan hak akses antara admin dan pasien.

---

### 6.4 user.cpp

```cpp
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
            cout << "\rTunggu " << i << " detik...";
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

```

**Penjelasan:**
File `user.cpp` berisi implementasi proses registrasi dan login pengguna. Pada file ini juga diterapkan validasi password serta sistem penguncian login sementara apabila terjadi kesalahan login berulang kali.

---

### 6.5 main.cpp

```cpp
#include <iostream>
#include "user.h"
#include "pasien.h"

using namespace std;

/* ================= MENU ADMIN ================= */
void menuAdmin() {
    int pilih;
    do {
        cout << "\n=== MENU ADMIN ===\n";
        cout << "1. Tambah Pasien\n";
        cout << "2. Lihat Semua Pasien\n";
        cout << "3. Logout\n";
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

```

**Penjelasan:**
File `main.cpp` merupakan entry point program yang mengatur alur utama sistem. Program akan menampilkan menu utama, memproses login admin atau pasien, serta mengarahkan pengguna ke menu sesuai dengan role masing-masing.


## 7. Kesimpulan

Sistem Antrian Rumah Sakit berbasis C++ ini berhasil diimplementasikan dengan baik dan mampu membantu pengelolaan data pasien serta pengaturan antrian secara lebih terstruktur. Dengan adanya pembagian hak akses antara admin dan pasien, sistem menjadi lebih aman dan terkontrol. Penyimpanan data menggunakan file teks juga memungkinkan data tetap tersimpan meskipun program ditutup. Diharapkan sistem ini dapat menjadi dasar pengembangan aplikasi pelayanan rumah sakit yang lebih kompleks di masa mendatang.
