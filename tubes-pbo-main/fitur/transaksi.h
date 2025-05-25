#include <iostream>
#include <windows.h>
#include <fstream>
#include <time.h>
using namespace std;

class DataTransaksi
{
public:
    void laporanTransaksi(int setor, int tarik, int sisa_saldo)
    {
        time_t ct = time(0);
        string currenttime = ctime(&ct);
        fstream recipt;

        recipt.open("laporan/laporan_transaksi.txt", ios::out);

        recipt << "Data Nasabah" << endl;
        recipt << "            " << endl;
        recipt << "Penyetoran : Rp" << setor << endl;
        recipt << "Penarikan  : Rp" << tarik << endl;
        recipt << "Sisa Saldo : Rp" << sisa_saldo << endl;
        recipt << "Tanggal    : " << currenttime << endl;

        recipt.close();
    }
};
