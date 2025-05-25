#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

#include "fitur/admin_nasabah.h"  
#include "fitur/input_data.h"
#include "fitur/saldo.h"
#include "fitur/cekdata.h"
#include "fitur/transaksi.h"
#include "fitur/keluar.h"

using namespace std;

string nama, NIM, alamat, nomortelepon, norek;
int menu, ulang;

string generateNoRekBNI()
{
    srand(time(0)); 
    string norek = "46";     
    for(int i = 0; i < 8; i++)
    {
        norek += to_string(rand() % 10);
    } 
    return norek;
}

void inputdata()
{
  system("cls");
  cout << "\nInput Data Nasabah" << endl;
  
  cin.ignore();
  
  cout << "Nama\t\t: ";
  getline(cin, nama);
  cout << "NIM\t\t: ";
  getline(cin, NIM);
  cout << "Alamat\t\t: ";
  getline(cin, alamat);
  cout << "No. Telepon\t: ";
  getline(cin, nomortelepon);
  norek = generateNoRekBNI();
  
  system("cls");
  cout << "\n==================================" << endl;
  cout << "    REGISTRASI BERHASIL!" << endl;
  cout << "==================================" << endl;
  cout << "Selamat! Akun BNI Anda telah dibuat" << endl;
  cout << "Nomor Rekening BNI" << norek << endl;
  cout << "==================================" << endl;
  cout << "Tekan apa saja untuk lanjut ke ATM...";
  cin.get();
}

void displayMenu()
{
  system("cls");
  cout << "Pilihan Menu ATM" << endl;
  cout << "1. Cek Saldo" << endl;
  cout << "2. Setor Saldo" << endl;
  cout << "3. Tarik Saldo" << endl;
  cout << "4. Cek Data Diri" << endl;
  cout << "5. Keluar & Simpan Data" << endl;
}

void next()
{
  cout << "Tekan apa saja untuk lanjut..";
  cin.ignore();
  cin.get();
}

void menuUtama()
{
  int pilihan;
  system("cls");
  cout << "   SISTEM ATM BANK BNI DIGITAL" << endl;
  cout<<endl;
  cout << "1. Registrasi Nasabah Baru" << endl;
  cout << "2. Admin Panel" << endl;
  cout << "3. Keluar Program" << endl;
  cout <<endl;
  cout << "Pilih menu (1-3): ";
  cin >> pilihan;
  
  switch(pilihan)
  {
    case 1:
      {
        CekData data;
        inputdata();
        datanasabah nasabah(nama, NIM, alamat, nomortelepon, norek); 
        DataTransaksi transaksi;
        do
        {
          system("cls");
          displayMenu();
          ulang = 0;
          cout << "\nPilih Menu : ";
          cin >> menu;

          switch (menu)
          {
          case 1:
            fiturCekSaldo();
            next();
            ulang = 1;
            break;

          case 2:
            fiturSetorSaldo();
            next();
            ulang = 1;
            break;

          case 3:
            fiturTarikSaldo();
            next();
            ulang = 1;
            break;

          case 4:
            data.setNama(nama);
            data.setNIM(NIM);
            data.setAlamat(alamat);
            data.setNomor(nomortelepon);
            data.cekData();
            next();
            ulang = 1;
            break;

          case 5:
            nasabah.simpankefile(laporanSaldo());
            transaksi.laporanTransaksi(laporanSetor(), laporanTarik(), laporanSaldo());
            
            system("cls");
            cout << "   DATA BERHASIL DISIMPAN!" << endl;
            cout << "Terima kasih" << endl;
            cout << "layanan ATM BNI Digital" << endl;
            cout << "Tekan apa saja untuk kembali ke menu utama...";
            cin.ignore();
            cin.get();
            
            ulang = 0; 
            break;

          default:
            cout << "Pilih 1 sampai 5 saja" << endl;
            next();
            ulang = 1;
            break;
          }
        } while (ulang == 1);
      }
      break;
      
    case 2:
      {
        AdminNasabah sistem;
        if(sistem.loginAdmin()) 
        {
          sistem.menuAdmin();
        }
      }
      break;
      
    case 3:
      system("cls");
      cout << "   TERIMA KASIH!" << endl;
      exit(0);
      break;
    default:
      cout << "Pilihan tidak valid!" << endl;
      cin.ignore();
      cin.get();
      break;
  }
}

int main()
{
  while(true)
  {
    menuUtama();
  }
  
  return 0;
}