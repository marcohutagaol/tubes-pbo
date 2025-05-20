#include <iostream>
using namespace std;

class Saldo
{
protected:
  int saldo = 1;

public:
  
};

class fiturSaldo : public Saldo {
  public:
  void cekSaldo() {
    cout << "Jumlah saldo anda: " << saldo;
  }

  void setorSaldo() {
    cout << "Masukkan jumlah saldo yang ingin disetor: " << saldo;
  }
};

int main()
{
  fiturSaldo user;
  user.cekSaldo();
}