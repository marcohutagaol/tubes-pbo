#include <iostream>
using namespace std;

class Saldo
{
protected:
  int saldo;

public:
  Saldo(int saldo = 0)
  {
    this->saldo = saldo;
  }

  Saldo operator+(Saldo const &temp)
  {
    Saldo sum;
    sum.saldo = saldo + temp.saldo;
    return sum;
  }

  Saldo operator-(Saldo const &temp)
  {
    Saldo diff;
    diff.saldo = saldo - temp.saldo;
    return diff;
  }

  int getSaldo()
  {
    return saldo;
  }

  bool isEmpty()
  {
    if (saldo == 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool isMinus()
  {
    if (saldo < 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  void cekSaldo()
  {
    cout << "Jumlah saldo anda: " << saldo << endl;
  }
};

class fiturSaldo : public Saldo
{
public:
  void setorSaldo()
  {
    cout << "Masukkan jumlah saldo yang ingin disetor: ";
    cin >> saldo;
  }

  void tarikSaldo()
  {
    cout << "Masukkan jumlah saldo yang ingin ditarik: ";
    cin >> saldo;
  }
};