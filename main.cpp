#include <iostream>
#include <windows.h>

#include "saldo.h"

using namespace std;

int menu, loop_menu;

void displayMenu()
{
  cout << "Pilihan Menu ATM" << endl;
  cout << "1. Cek Saldo" << endl;
  cout << "2. Setor Saldo" << endl;
  cout << "3. Tarik Saldo" << endl;
  cout << "4. Cek Data Diri" << endl;
  cout << "5. Keluar";
}

int main()
{
  Saldo saldo_sekarang;
  Saldo tambah_saldo;
  fiturSaldo saldo_setor, saldo_tarik;

  system("cls");

  displayMenu();

  do
  {
    loop_menu = 0;

    cout << "\nPilih Menu : ";
    cin >> menu;

    switch (menu)
    {
    case 1:
      saldo_sekarang.cekSaldo();

      loop_menu = 1;
      break;

    case 2:
      saldo_setor.setorSaldo();
      saldo_sekarang = saldo_sekarang + saldo_setor;
      saldo_sekarang.cekSaldo();

      loop_menu = 1;
      break;

    case 3:
      if (!saldo_sekarang.isEmpty())
      {
        saldo_tarik.tarikSaldo();
        if (saldo_sekarang.getSaldo() < saldo_tarik.getSaldo())
        {
          cout << "Saldo ga cukup kocak" << endl;
        }
        else
        {
          saldo_sekarang = saldo_sekarang - saldo_tarik;
          saldo_sekarang.cekSaldo();
        }
      }
      else
      {
        cout << "Saldo kosong, setor duls" << endl;
      }

      loop_menu = 1;
      break;

    case 4:
      // cekDataDiri();
      break;

    case 5:
      // keluar();
      break;

    default:
      cout << "Pilih 1 sampai 5 saja" << endl;
      loop_menu = 1;
      break;
    }
  } while (loop_menu == 1);
}