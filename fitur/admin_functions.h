#ifndef ADMIN_FUNCTIONS_H
#define ADMIN_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class AdminFunctions 
{
public:
    static void lihatDataNasabah() 
    {
        system("cls");
        cout << "      DATA SEMUA NASABAH" << endl;
        
        ifstream file("laporan/master_nasabah.txt");
        if (file.is_open()) 
        {
            string line;
            int totalNasabah = 0;

            while (getline(file, line)) 
            {
                cout << line << endl;
                for (int i = 0; i < line.length(); i++) 
                {
                    if (line.substr(i, 13) == "No. Rekening:") 
                    {
                        totalNasabah++;
                        break;
                    }
                }
            }
            file.close();
            
            if (totalNasabah > 0) 
            {
                cout << "\n\t\t\t\t\t" << endl;
                cout << "Total Nasabah: " << totalNasabah << " orang" << endl;
                cout << "\t\t\t\t\t\t\t" << endl;
            }
        } 
        else 
        {
            cout << "Belum ada data nasabah." << endl;
        }
        
        cout << "\nTekan apa saja untuk kembali...";
        cin.ignore();
        cin.get();
    }
    
    static void resetData() 
    {
        char konfirmasi;
        system("cls");
        cout << "        RESET DATA" << endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t";
        cout<<endl;
        cout << "Data yang akan dihapus:" << endl;
        cout << "- Semua data nasabah" << endl;
        cout << "- Semua laporan transaksi" << endl;
        cout<<endl;
        cout << "Apakah Anda yakin? (y/n): ";
        cin >> konfirmasi;
        
        if (konfirmasi == 'y' || konfirmasi == 'Y') 
        {
            remove("laporan/master_nasabah.txt");
            remove("laporan/laporan_transaksi.txt");
            
            cout << "       RESET BERHASIL!" << endl;
        } 
        else 
        {
            cout << "\nReset dibatalkan." << endl;
        }
        
        cout << "\nTekan apa saja untuk kembali...";
        cin.ignore();
        cin.get();
    }
};

#endif