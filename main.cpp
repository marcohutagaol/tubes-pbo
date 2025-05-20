#include <iostream>
#include <windows.h>
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
      // cekSaldo();
      break;

    case 2:
      // setorSaldo();
      break;

    case 3:
      // tarikSaldo();
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