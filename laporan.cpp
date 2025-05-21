#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

int main() {
    fstream recipt;


    recipt.open("recipt.txt", ios::out);

    recipt << "Penyetoran : " << endl;
    recipt << "Penarikan : " << endl;
    recipt << "Sisa Saldo : " << endl;

    recipt.close(); 
}