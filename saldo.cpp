#include <iostream>
using namespace std;

class Saldo
{
public:
  int saldo;

  Saldo(int saldo = 0) {
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

  void cekSaldo()
  {
    cout << "Jumlah saldo anda: " << saldo << endl;
  }
};

class fiturSaldo : public Saldo
{
public:
  void setSaldo(int saldo)
  {
    this->saldo = saldo;
  }

  int getSaldo()
  {
    return saldo;
  }

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

int main()
{
  fiturSaldo saldo_awal;
  saldo_awal.setSaldo(1000);
  saldo_awal.getSaldo();
  saldo_awal.cekSaldo();

  // fiturSaldo saldo_setor;
  // saldo_setor.setorSaldo();
  // saldo_setor.getSaldo();

  // Saldo tambah_saldo;
  // tambah_saldo = saldo_awal + saldo_setor;
  // tambah_saldo.cekSaldo();

  fiturSaldo saldo_tarik;
  saldo_tarik.tarikSaldo();

  Saldo kurang_saldo;
  kurang_saldo = saldo_awal - saldo_tarik;
  kurang_saldo.cekSaldo();

  return 0;
}