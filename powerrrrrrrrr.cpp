#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
void cls() {
        system("cls");
}
class user {
public:
    string nama_user, pass, nama, alamat, hp, tipe;
    user(string usr, string pw, string nm, string almt, string telp, string tp) {
        nama_user = usr;
        pass = pw;
        nama = nm;
        alamat = almt;
        hp = telp;
        tipe = tp;
    }
    void tampil() {
        cout << "user: " << nama_user << endl;
        cout << "nama: " << nama << endl;
        cout << "alamat: " << alamat << endl;
        cout << "hp: " << hp << endl;
        cout << "tipe: " << tipe << endl;
    }
};
class rekening {
public:
    string nama_user;
    string no_rek;
    string jenis;
    double saldo;
    rekening(string usr, string no, string jns, double uang) {
        nama_user = usr;
        no_rek = no;
        jenis = jns;
        saldo = uang;
    }
    void tampil() {
        cout << "user: " << nama_user << endl;
        cout << "no rekening: " << no_rek << endl;
        cout << "jenis: " << jenis << endl;
        cout << "saldo: rp " << saldo << endl;
    }
};

class bank {
public:
    vector<user> data_user;
    vector<rekening> data_rekening;
    string userlogin;
    string tipelogin;
    bank() {
        userlogin = "";
        tipelogin = "";
        user adm("admin", "123", "administrator", "kantor", "08123456789", "admin");
        data_user.push_back(adm);
    }
    void daftar() {
        string usr, pw, nm, almt, telp;
        cls();
        cout << "\ndaftar user baru" << endl;
        cout << "username: ";
        cin >> usr;
        for(int i = 0; i < data_user.size(); i++) {
            if(data_user[i].nama_user == usr) {
                cout << "username udah ada!" << endl;
                cout << "tekan apa saja..";
                cin.ignore();
                cin.get();
                return;
            }}   
        cout << "password: ";
        cin >> pw;
        cin.ignore();
        cout << "nama lengkap: ";
        getline(cin, nm);
        cout << "alamat: ";
        getline(cin, almt);
        cout << "no hp: ";
        getline(cin, telp);
        user baru(usr, pw, nm, almt, telp, "nasabah");
        data_user.push_back(baru);
        cout << "daftar berhasil!" << endl;
        cout << "tekan apa saja..";
        cin.get();
    }
    bool masuk() {
        string usr, pw;
        cls();
        cout << "\nmasuk" << endl;
        cout << "username: ";
        cin >> usr;
        cout << "password: ";
        cin >> pw;
        
        for(int i = 0; i < data_user.size(); i++) {
            if(data_user[i].nama_user == usr && data_user[i].pass == pw) {
                userlogin = usr;
                tipelogin = data_user[i].tipe;
                cout << "masuk berhasil!" << endl;
                cout << "tekan apa saja...";
                cin.ignore();
                cin.get();
                return true;
            }
        }
        cout << "username atau password salah!" << endl;
        cout << "tekan apa saja..";
        cin.ignore();
        cin.get();
        return false;
    }
    void buat_rek() {
        string no, jns;
        double uang;
        cls();
        for(int i = 0; i < data_rekening.size(); i++) {
            if(data_rekening[i].nama_user == userlogin) {
                cout << "kamu udah punya rekening" << endl;
                cout << "tekan apa saja..";
                cin.ignore();
                cin.get();
                return;
            }
        }

        cout << "\nbuat rekening" << endl;
        no = "rek" + to_string(rand() % 100000);
        cout << "no rekening: " << no << endl;
        cin.ignore();
        cout << "jenis rekening: ";
        getline(cin, jns);
        cout << "saldo awal: rp ";
        cin >> uang;
        
        rekening baru(userlogin, no, jns, uang);
        data_rekening.push_back(baru);
        
        cout << "rekening berhasil dibuat" << endl;
        cout << "tekan apa saja..";
        cin.ignore();
        cin.get();
    }
    void lihat_rek() {
        cls();
        cout << "\n rekening saya " << endl;
        for(int i = 0; i < data_rekening.size(); i++) {
            if(data_rekening[i].nama_user == userlogin) {
                data_rekening[i].tampil();
                cout << "\ntekan apa saja..";
                cin.ignore();
                cin.get();
                return;
            }
        }
        cout << "kamu belum punya rekening" << endl;
        cout << "tekan apa saja..";
        cin.ignore();
        cin.get();
    }
    void semuauser() {
        cls();
        cout << "\nsemua user" << endl;
        if(data_user.empty()) {
            cout << "gak ada user" << endl;
            cout << "tekan apa saja..";
            cin.ignore();
            cin.get();
            return;
        }
        for(int i = 0; i < data_user.size(); i++) {
            cout << "\nuser ke-" << (i+1) << ":" << endl;
            data_user[i].tampil();
            cout << "--------------------" << endl;
        }
        cout << "\ntekan apa saja..";
        cin.ignore();
        cin.get();
    }
    void semuarek() {
        cls();
        cout << "\nsemua rekening" << endl;
        
        if(data_rekening.empty()) {
            cout << "gak ada rekening!" << endl;
            cout << "tekan apa saja..";
            cin.ignore();
            cin.get();
            return;
        }
        
        for(int i = 0; i < data_rekening.size(); i++) {
            cout << "\nrekening ke-" << (i+1) << ":" << endl;
            data_rekening[i].tampil();
            cout << "--------------------" << endl;
        }
        cout << "\ntekan apa saja..";
        cin.ignore();
        cin.get();
    }
    
    void menu_admin() {
        int pilih;
        do {
            cls();
            cout << "\nhalo komdigiii: " << userlogin << endl;
            cout << "\nmenu admin" << endl;
            cout << "1. lihat semua user" << endl;
            cout << "2. lihat semua rekening" << endl;
            cout << "3. keluar" << endl;
            cout << "pilih: ";
            cin >> pilih; 
            switch(pilih) {
                case 1:
                    semuauser();
                    break;
                case 2:
                    semuarek();
                    break;
                case 3:
                    cout << "keluar berhasil!" << endl;
                    userlogin = "";
                    tipelogin = "";
                    cout << "tekan apa saja..";
                    cin.ignore();
                    cin.get();
                    break;
                default:
                    cout << "pilihan salah!" << endl;
                    cout << "tekan apa saja..";
                    cin.ignore();
                    cin.get();
            }
        } while(pilih != 3);
    }
    
    void menu_nasabah() {
        int pilih;
        
        do {
            cls();
            cout << "\nhalo: " << userlogin << endl;
            cout << "\n menu nasabah" << endl;
            cout << "1. buat rekening" << endl;
            cout << "2. lihat rekening" << endl;
            cout << "3. keluar" << endl;
            cout << "pilih: ";
            cin >> pilih;
            switch(pilih) {
                case 1:
                    buat_rek();
                    break;
                case 2:
                    lihat_rek();
                    break;
                case 3:
                    cout << "keluar berhasil!" << endl;
                    userlogin = "";
                    tipelogin = "";
                    cout << "tekan apa saja..";
                    cin.ignore();
                    cin.get();
                    break;
                default:
                    cout << "pilihan salah!" << endl;
                    cout << "tekan apa saja..";
                    cin.ignore();
                    cin.get();
            }
        } while(pilih != 3);
    }
    void mulai() {
        int pilih;
        
        do {
            cls();
            cout << "== sistem bank sederhana ==" << endl;
    
            cout << "\nregistrasi dan login" << endl;
            cout << "1. masuk" << endl;
            cout << "2. daftar" << endl;
            cout << "3. keluar" << endl;
            cout << "pilih: ";
            cin >> pilih;
            
            switch(pilih) {
                case 1:
                    if(masuk()) {
                        if(tipelogin == "admin") {
                            menu_admin();
                        } else {
                            menu_nasabah();
                        }
                    }
                    break;
                case 2:
                    daftar();
                    break;
                case 3:
                    cls();
                    cout << "makasih udah pake sistem bank!" << endl;
                    break;
                default:
                    cout << "pilihan salah!" << endl;
                    cout << "tekan apa saja..";
                    cin.ignore();
                    cin.get();
            }
        } while(pilih != 3);
    }
};
int main() {
    bank sistem;
    sistem.mulai();
    return 0;
}