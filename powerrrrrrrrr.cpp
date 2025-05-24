#include <iostream>
#include <fstream>
using namespace std;

class datanasabah {
private:
    string nama;
    string alamat;
    string nomortelepon;
    fstream file;

public:
    datanasabah() {
        nama = "";
        alamat = "";
        nomortelepon = "";
        cout << "objek data nasabah dibuat" << endl;
    }

    //const
    datanasabah(string n, string a, string nt) {
        nama = n;
        alamat = a;
        nomortelepon = nt;
        cout << "objek data nasabah dibuat dengan parameter" << endl;
    }
//desc
    ~datanasabah() {
        if (file.is_open()) {
            file.close();
        }
        cout << "objek data nasabah dihapus" << endl;
    }

    void inputdata() {
        cout << endl << "input data nasabah" << endl;
        cout << "nama: ";
        getline(cin, nama);
        cout << "alamat: ";
        getline(cin, alamat);
        cout << "nomor telepon: ";
        getline(cin, nomortelepon);
    }

    void tampilkandata() {
        cout << endl << "data yang diinput" << endl;
        cout << "nama: " << nama << endl;
        cout << "alamat: " << alamat << endl;
        cout << "nomor telepon: " << nomortelepon << endl;
    }

    //fileh
    void simpankefile() {
        file.open("datanasabah.txt", ios::out);
        if (file.is_open()) {
            file << "data nasabah" << endl;
            file << "            " << endl;
            file << "nama: " << nama << endl;
            file << "alamat: " << alamat << endl;
            file << "nomor telepon: " << nomortelepon << endl;
            file.close();
            cout << endl << "data disimpan ke file datanasabah.txt" << endl;
        } else {
            cout << endl << "gagal menyimpan file" << endl;
        }
    }

    void bacadarifile() {
        file.open("datanasabah.txt", ios::in);
        if (file.is_open()) {
            cout << endl << "isi file datanasabah.txt" << endl;
            string baris;
            while (getline(file, baris)) {
                cout << baris << endl;
            }
            file.close();
        } else {
            cout << endl << "file tidak ditemukan" << endl;
        }
    }

    bool validasidata() {
        if (nama.empty() || alamat.empty() || nomortelepon.empty()) {
            cout << endl << "ada data yang kosong" << endl;
            return false;
        }
        return true;
    }

    void jalan() {
        inputdata();
        tampilkandata();
        if (validasidata()) {
            simpankefile();
            bacadarifile();
        } else {
            cout << "data tidak disimpan" << endl;
        }
    }
};

int main() {
    datanasabah nasabah;
    nasabah.jalan();
    cout << endl << "program selesai" << endl;
    return 0;
}
