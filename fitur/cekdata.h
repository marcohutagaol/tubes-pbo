#include <iostream>
using namespace std;

class dataDiri
{
private:
    string nama, NIM, alamat, nomortelepon;

public:
    string getNama()
    {
        return nama;
    }
    string getNIM()
    {
        return NIM;
    }
    string getAlamat()
    {
        return alamat;
    }
    string getNomor()
    {
        return nomortelepon;
    }

    void setNama(string nama)
    {
        this->nama = nama;
    }
    void setNIM(string NIM)
    {
        this->NIM = NIM;
    }
    void setAlamat(string alamat)
    {
        this->alamat = alamat;
    }
    void setNomor(string nomortelepon)
    {
        this->nomortelepon = nomortelepon;
    }
};

class CekData : public dataDiri
{
public:
    void cekData()
    {
        cout << "\nData Anda" << endl;
        cout << "Nama\t\t: " << getNama() << endl;
        cout << "NIM\t\t: " << getNIM() << endl;
        cout << "Alamat\t\t: " << getAlamat() << endl;
        cout << "No. Telepon\t: " << getNomor() << endl;
    }
};