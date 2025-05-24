#include <iostream>
#include <windows.h>

#include "fitur/input_data.h"
#include "fitur/saldo.h"
#include "fitur/cekdata.h"
#include "fitur/transaksi.h"
#include "fitur/keluar.h"

using namespace std;

string nama, NIM, alamat, nomortelepon;
int menu, loop_menu;

void inputdata()
{
  system("cls");
  cout << "\nInput Data Nasabah" << endl;
  cout << "Nama\t\t: ";
  getline(cin, nama);
  cout << "NIM\t\t: ";
  getline(cin, NIM);
  cout << "Alamat\t\t: ";
  getline(cin, alamat);
  cout << "No. Telepon\t: ";
  getline(cin, nomortelepon);
}

void displayMenu()
{
  system("cls");
  cout << "Pilihan Menu ATM" << endl;
  cout << "1. Cek Saldo" << endl;
  cout << "2. Setor Saldo" << endl;
  cout << "3. Tarik Saldo" << endl;
  cout << "4. Cek Data Diri" << endl;
  cout << "5. Keluar";
}

void next()
{
  cout << "Tekan apa saja untuk lanjut..";
  cin.ignore();
  cin.get();
}

int main()
{
  CekData data;

  inputdata();
  datanasabah nasabah(nama, NIM, alamat, nomortelepon);
  DataTransaksi transaksi;

  do
  {
    system("cls");
    displayMenu();

    loop_menu = 0;

    cout << "\nPilih Menu : ";
    cin >> menu;

    switch (menu)
    {
    case 1:
      fiturCekSaldo();
      next();
      loop_menu = 1;
      break;

    case 2:
      fiturSetorSaldo();
      next();
      loop_menu = 1;
      break;

    case 3:
      fiturTarikSaldo();
      next();
      loop_menu = 1;
      break;

    case 4:
      data.setNama(nama);
      data.setNIM(NIM);
      data.setAlamat(alamat);
      data.setNomor(nomortelepon);
      data.cekData();
      next();
      loop_menu = 1;
      break;

    case 5:
      nasabah.simpankefile(laporanSaldo());
      transaksi.laporanTransaksi(laporanSetor(), laporanTarik(), laporanSaldo());
      keluar();
      return 0;
      break;

    default:
      cout << "Pilih 1 sampai 5 saja" << endl;
      next();
      loop_menu = 1;
      break;
    }
  } while (loop_menu == 1);
}