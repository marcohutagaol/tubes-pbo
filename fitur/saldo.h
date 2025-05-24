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
    cout << "Jumlah saldo anda: Rp" << saldo << endl;
  }
};

class fiturSaldo : public Saldo
{
public:
  fiturSaldo operator+(fiturSaldo const &temp)
  {
    fiturSaldo add;
    add.saldo = saldo + temp.saldo;
    return add;
  }

  void setorSaldo()
  {
    cout << "Masukkan jumlah saldo yang ingin disetor: Rp";
    cin >> saldo;
  }

  void tarikSaldo()
  {
    cout << "Masukkan jumlah saldo yang ingin ditarik: Rp";
    cin >> saldo;
  }
};

Saldo saldo_sekarang, tambah_saldo;
fiturSaldo saldo_setor, saldo_tarik;
fiturSaldo laporan_setor, laporan_tarik;

void fiturCekSaldo()
{
  saldo_sekarang.cekSaldo();
}

void fiturSetorSaldo()
{
  saldo_setor.setorSaldo();
  saldo_sekarang = saldo_sekarang + saldo_setor;
  laporan_setor = laporan_setor + saldo_setor;
  saldo_sekarang.cekSaldo();
}

void fiturTarikSaldo()
{
  if (!saldo_sekarang.isEmpty())
  {
    saldo_tarik.tarikSaldo();
    if (saldo_sekarang.getSaldo() < saldo_tarik.getSaldo())
    {
      cout << "Saldo tidak cukup" << endl;
    }
    else
    {
      saldo_sekarang = saldo_sekarang - saldo_tarik;
      laporan_tarik = laporan_tarik + saldo_tarik;
      saldo_sekarang.cekSaldo();
    }
  }
  else
  {
    cout << "Saldo kosong" << endl;
  }
}

int laporanSaldo()
{
  return saldo_sekarang.getSaldo();
}

int laporanSetor()
{
  return laporan_setor.getSaldo();
}

int laporanTarik()
{
  return laporan_tarik.getSaldo();
}