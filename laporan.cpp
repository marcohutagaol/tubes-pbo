#include <iostream>
#include <windows.h>
#include <fstream>
#include <time.h>
using namespace std;

int main() {
    time_t  ct = time(0);
    string currenttime=ctime(&ct);
    fstream recipt; 


    recipt.open("recipt.txt", ios::out);

    recipt << "Penyetoran : " << endl;
    recipt << "Penarikan : " << endl;
    recipt << "Sisa Saldo : " << endl;
    recipt << "Tanggal : " << currenttime << endl;

    recipt.close(); 
}