#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

class datanasabah
{
private:
    string nama;
    string alamat;
    string nomortelepon;
    string NIM;
    string norek;
    fstream file;

public:
    datanasabah(string n, string nim, string a, string nt, string nr)
    {
        nama = n;
        NIM = nim;
        alamat = a;
        nomortelepon = nt;
        norek = nr;
        cout << "Data tersimpan, tekan apa saja untuk lanjut..";
        cin.get();
    }

    void simpankefile(int saldo)
    {

        string namafile = "laporan/laporan_" + norek + ".txt";
        
        file.open(namafile, ios::out);
        if (file.is_open())
        {
            time_t now = time(0);
            char* dt = ctime(&now);
            
            file << "==============================" << endl;
            file << "     LAPORAN DATA NASABAH" << endl;
            file << "==============================" << endl;
            file << "Waktu Cetak : " << dt;
            file << "Nama        : " << nama << endl;
            file << "NIM         : " << NIM << endl;
            file << "Alamat      : " << alamat << endl;
            file << "No. Telepon : " << nomortelepon << endl;
            file << "No. Rekening: " << norek << endl;
            file << "Saldo       : Rp" << saldo << endl;
            file << "==============================" << endl;
            file.close();
            
        }
        else
        {
            cout << "\nGagal menyimpan file" << endl;
        }

        simpanKeMaster(saldo);
    }

    void simpanKeMaster(int saldo)
    {
        file.open("laporan/master_nasabah.txt", ios::app); 
        if (file.is_open())
        {
            time_t now = time(0);
            char* dt = ctime(&now);
            
            file << "==============================" << endl;
            file << "Tanggal     : " << dt;
            file << "Nama        : " << nama << endl;
            file << "NIM         : " << NIM << endl;
            file << "Alamat      : " << alamat << endl;
            file << "No. Telepon : " << nomortelepon << endl;
            file << "No. Rekening: " << norek << endl;
            file << "Saldo       : Rp" << saldo << endl;
            file << "==============================" << endl << endl;
            file.close();
        }
    }
    
    static void lihatSemuaNasabah()
    {
        ifstream file("laporan/master_nasabah.txt");
        if (file.is_open())
        {
            string line;
            cout << "\n==============================" << endl;
            cout << "   DAFTAR SEMUA NASABAH" << endl;
            cout << "==============================" << endl;
            
            while (getline(file, line))
            {
                cout << line << endl;
            }
            file.close();
        }
        else
        {
            cout << "\nBelum ada data nasabah atau file tidak ditemukan." << endl;
        }
    }
    
    // Fungsi untuk menghitung total nasabah
    static int hitungTotalNasabah()
    {
        ifstream file("laporan/master_nasabah.txt");
        int count = 0;
        string line;
        
        if (file.is_open())
        {
            while (getline(file, line))
            {
                if (line.find("No. Rekening:") != string::npos)
                {
                    count++;
                }
            }
            file.close();
        }
        
        return count;
    }
};