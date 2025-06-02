#include <iostream>
#include <windows.h>
using namespace std;


class Keluar
{
public:
  virtual void pesan()
  {
    cout << "\nTerimakasi sudah menggunakan program kami ^^" << endl;
  }
};

class Transaksi : public Keluar
{
public:
  void pesan() override
  {
    cout << "\nSilahkan cek histori transaksi anda pada laporan_transaksi.txt" << endl;
  }
};

class SisaSaldo : public Keluar
{
public:
  void pesan() override
  {
    cout << "Anda juga bisa cek sisa saldo anda pada laporan_norek.txt\n" << endl;
  }
};

class DestructorKeluar : public Keluar
{
public:
  ~DestructorKeluar()
  {
    cout << "Program akan ditutup dalam:" << endl;
    Sleep(1000);
    cout << "3" << endl;
    Sleep(1000);
    cout << "2" << endl;
    Sleep(1000);
    cout << "1" << endl;
    Sleep(1000);
    cout << "Program telah ditutup" << endl;
  }
};

void keluar()
{
  Keluar *keluar = new Keluar();
  keluar->pesan();

  Transaksi transaksi;
  keluar = &transaksi;
  keluar->pesan();

  SisaSaldo sisa_saldo;
  keluar = &sisa_saldo;
  keluar->pesan();

  DestructorKeluar destructor;
}