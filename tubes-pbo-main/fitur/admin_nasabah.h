#ifndef ADMIN_NASABAH_H
#define ADMIN_NASABAH_H

#include <iostream>
#include <string>
#include <windows.h>
#include "admin_functions.h"  


using namespace std;

class AdminNasabah 
{
private:
    string username_admin = "admin";
    string password_admin = "123456";
    
public:
    int pilihRole() 
    {
        int pilihan;
        system("cls");
        cout << "==================================" << endl;
        cout << "    SISTEM ATM BANK DIGITAL" << endl;
        cout << "==================================" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Nasabah" << endl;
        cout << "==================================" << endl;
        cout << "Pilih role Anda (1/2): ";
        cin >> pilihan;
        
        return pilihan;
    }
    
    bool loginAdmin() 
    {
        string input_username, input_password;
        int percobaan = 0;
        
        system("cls");
        cout << "==================================" << endl;
        cout << "        LOGIN ADMIN" << endl;
        cout << "==================================" << endl;
        
        while(percobaan < 3) 
        {
            cout << "Username: ";
            cin >> input_username;
            cout << "Password: ";
            cin >> input_password;
            
            if(input_username == username_admin && input_password == password_admin) 
            {
                cout << "\nLogin berhasil! Selamat datang Admin." << endl;
                cout << "Tekan apa saja untuk lanjut...";
                cin.ignore();
                cin.get();
                return true;
            } 
            else 
            {
                percobaan++;
                cout << "\nUsername atau password salah!" << endl;
                if(percobaan < 3) 
                {
                    cout << "Sisa percobaan: " << (3 - percobaan) << endl;
                    cout << "Coba lagi..." << endl << endl;
                }
            }
        }
        
        cout << "\nAnda telah gagal login 3 kali. Program akan keluar." << endl;
        cout << "Tekan apa saja untuk keluar...";
        cin.ignore();
        cin.get();
        return false;
    }
    
    void menuAdmin() 
    {
        int pilihan;
        do 
        {
            system("cls");
            cout << "==================================" << endl;
            cout << "        MENU ADMIN" << endl;
            cout << "==================================" << endl;
            cout << "1. Lihat Semua Data Nasabah" << endl;
            cout << "2. Reset Data" << endl;
            cout << "3. Keluar" << endl;
            cout << "==================================" << endl;
            cout << "Pilih menu (1-4): ";
            cin >> pilihan;
            
            switch(pilihan) 
            {
                case 1:
                    AdminFunctions::lihatDataNasabah();
                    break;
                case 2:
                    AdminFunctions::resetData();
                    break;
                case 3:
                     cout << "Keluar dari menu admin..." << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid!" << endl;
                    cout << "Tekan apa saja untuk lanjut...";
                    cin.ignore();
                    cin.get();
                    break;
            }
        } while(pilihan != 3);
    }
};

#endif