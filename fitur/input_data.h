#include <iostream>
#include <fstream>
using namespace std;

class datanasabah
{
private:
    string nama;
    string alamat;
    string nomortelepon;
    string NIM;
    fstream file;

public:
    datanasabah(string n, string a, string nt, string nim)
    {
        nama = n;
        NIM = nim;
        alamat = a;
        nomortelepon = nt;
        cout << "Data tersimpan, tekan apa saja untuk lanjut..";
        cin.ignore();
    }

    // fileh
    void simpankefile(int saldo)
    {
        file.open("laporan/laporan_saldo.txt", ios::out);
        if (file.is_open())
        {
            file << "Data Nasabah" << endl;
            file << "            " << endl;
            file << "Nama        : " << nama << endl;
            file << "NIM         : " << NIM << endl;
            file << "Alamat      : " << alamat << endl;
            file << "No. Telepon : " << nomortelepon << endl;
            file << "Saldo       : Rp" << saldo << endl;
            file.close();
        }
        else
        {
            cout << "\nGagal menyimpan file" << endl;
        }
    }
};

// void tampilkandata() {
//     cout << endl << "data yang diinput" << endl;
//     cout << "nama: " << nama << endl;
//     cout << "alamat: " << alamat << endl;
//     cout << "nomor telepon: " << nomortelepon << endl;
// }

// void bacadarifile() {
//     file.open("datanasabah.txt", ios::in);
//     if (file.is_open()) {
//         cout << endl << "isi file datanasabah.txt" << endl;
//         string baris;
//         while (getline(file, baris)) {
//             cout << baris << endl;
//         }
//         file.close();
//     } else {
//         cout << endl << "file tidak ditemukan" << endl;
//     }
// }

// bool validasidata()
// {
//     if (nama.empty() || alamat.empty() || nomortelepon.empty())
//     {
//         cout << "\nada data yang kosong" << endl;
//         return false;
//     }
//     return true;
// }

// void jalan() {
//     inputdata();
//     tampilkandata();
//     if (validasidata()) {
//         bacadarifile();
//     } else {
//         cout << "data tidak disimpan" << endl;
//     }
// }