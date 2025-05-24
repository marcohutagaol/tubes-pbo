#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void bersihkan(){system("cls");}

const int MAKSUSER = 100;
const int MAKSREKENING = 100;

class pengguna{
public:
    string namapengguna, katasandi, nama, alamat, nohp, tipe;
    
    pengguna(){
        namapengguna = "";
        katasandi = "";
        nama = "";
        alamat = "";
        nohp = "";
        tipe = "";
    }
    
    pengguna(string usr, string pw, string nm, string almt, string telp, string tp){
        namapengguna = usr;
        katasandi = pw;
        nama = nm;
        alamat = almt;
        nohp = telp;
        tipe = tp;
    }
    
    void tampil(){
        cout << "pengguna: " << namapengguna << endl;
        cout << "nama: " << nama << endl;
        cout << "alamat: " << alamat << endl;
        cout << "no hp: " << nohp << endl;
        cout << "tipe: " << tipe << endl;
    }
};

class rekening{
public:
    string namapengguna;
    string norekening;
    string jenis;
    double saldo;
    
    rekening(){
        namapengguna = "";
        norekening = "";
        jenis = "";
        saldo = 0;
    }
    
    rekening(string usr, string no, string jns, double uang){
        namapengguna = usr;
        norekening = no;
        jenis = jns;
        saldo = uang;
    }
    
    void tampil(){
        cout << "pengguna: " << namapengguna << endl;
        cout << "no rekening: " << norekening << endl;
        cout << "jenis: " << jenis << endl;
        cout << "saldo: rp " << saldo << endl;
    }
};

class bank{
public:
    pengguna datapengguna[MAKSUSER];
    rekening datarekening[MAKSREKENING];
    int jumlahpengguna;
    int jumlahrekening;
    string penggunamasuk;
    string tipemasuk;
    
    bank(){
        jumlahpengguna = 0;
        jumlahrekening = 0;
        penggunamasuk = "";
        tipemasuk = "";
        bacadatapengguna();
        bacadatarekening();
        
        bool adaadmin = false;
        for(int i = 0; i < jumlahpengguna; i++){
            if(datapengguna[i].namapengguna == "admin"){
                adaadmin = true;
                break;
            }
        }
        
        if(!adaadmin){
            pengguna adm("admin", "123", "administrator", "kantor", "08123456789", "admin");
            datapengguna[jumlahpengguna] = adm;
            jumlahpengguna++;
            simpandatapengguna();
        }
    }
    
    void simpandatapengguna(){
        ofstream berkas;
        berkas.open("datapengguna.txt");
        if(!berkas.is_open()){
            cout << "tidak bisa buat file datapengguna.txt!" << endl;
            return;
        }
        
        for(int i = 0; i < jumlahpengguna; i++){
            berkas << datapengguna[i].namapengguna << "|";
            berkas << datapengguna[i].katasandi << "|";
            berkas << datapengguna[i].nama << "|";
            berkas << datapengguna[i].alamat << "|";
            berkas << datapengguna[i].nohp << "|";
            berkas << datapengguna[i].tipe << endl;
        }
        berkas.close();
    }
    
    void bacadatapengguna(){
        ifstream berkas;
        berkas.open("datapengguna.txt");
        if(!berkas.is_open()){
            cout << "file akan dibuat." << endl;
            return;
        }
        
        string baris;
        while(getline(berkas, baris) && jumlahpengguna < MAKSUSER){
            if(baris.empty()) continue;
            
            string usr = "", pw = "", nm = "", almt = "", telp = "", tp = "";
            int bagian = 0;
            
            for(int i = 0; i < baris.length(); i++){
                if(baris[i] == '|'){
                    bagian++;
                } else {
                    if(bagian == 0) usr += baris[i];
                    else if(bagian == 1) pw += baris[i];
                    else if(bagian == 2) nm += baris[i];
                    else if(bagian == 3) almt += baris[i];
                    else if(bagian == 4) telp += baris[i];
                    else if(bagian == 5) tp += baris[i];
                }
            }
            
            if(!usr.empty()){
                pengguna p(usr, pw, nm, almt, telp, tp);
                datapengguna[jumlahpengguna] = p;
                jumlahpengguna++;
            }
        }
        berkas.close();
    }
    
    void simpandatarekening(){
        ofstream berkas;
        berkas.open("datarekening.txt");
        if(!berkas.is_open()){
            cout << "tidak bisa buat file datarekening.txt!" << endl;
            return;
        }
        
        for(int i = 0; i < jumlahrekening; i++){
            berkas << datarekening[i].namapengguna << "|";
            berkas << datarekening[i].norekening << "|";
            berkas << datarekening[i].jenis << "|";
            berkas << datarekening[i].saldo << endl;
        }
        berkas.close();
    }
    
    void bacadatarekening(){
        ifstream berkas;
        berkas.open("datarekening.txt");
        if(!berkas.is_open()){
            cout << "datarekening.txt belum ada." << endl;
            return;
        }
        
        string baris;
        while(getline(berkas, baris) && jumlahrekening < MAKSREKENING){
            if(baris.empty()) continue;
            
            string usr = "", no = "", jns = "", saldobaris = "";
            int bagian = 0;
            
            for(int i = 0; i < baris.length(); i++){
                if(baris[i] == '|'){
                    bagian++;
                } else {
                    if(bagian == 0) usr += baris[i];
                    else if(bagian == 1) no += baris[i];
                    else if(bagian == 2) jns += baris[i];
                    else if(bagian == 3) saldobaris += baris[i];
                }
            }
            
            if(!usr.empty()){
                double saldo = 0;
                if(!saldobaris.empty()){
                    saldo = stod(saldobaris);
                }
                rekening r(usr, no, jns, saldo);
                datarekening[jumlahrekening] = r;
                jumlahrekening++;
            }
        }
        berkas.close();
    }
    
    void daftar(){
        if(jumlahpengguna >= MAKSUSER){
            cout << "Maaf, data pengguna sudah penuh!" << endl;
            cout << "tekan apa saja..";
            cin.ignore();
            cin.get();
            return;
        }
        
        string usr, pw, nm, almt, telp;
        bersihkan();
        cout << "\ndaftar pengguna baru" << endl;
        cout << "nama pengguna: ";
        cin >> usr;
        
        for(int i = 0; i < jumlahpengguna; i++){
            if(datapengguna[i].namapengguna == usr){
                cout << "nama pengguna udah ada!" << endl;
                cout << "tekan apa saja..";
                cin.ignore();
                cin.get();
                return;
            }
        }
        
        cout << "kata sandi: ";
        cin >> pw;
        cin.ignore();
        cout << "nama lengkap: ";
        getline(cin, nm);
        cout << "alamat: ";
        getline(cin, almt);
        cout << "no hp: ";
        getline(cin, telp);
        
        pengguna baru(usr, pw, nm, almt, telp, "nasabah");
        datapengguna[jumlahpengguna] = baru;
        jumlahpengguna++;
        simpandatapengguna();
        
        cout << "daftar berhasil dan data tersimpan!" << endl;
        cout << "tekan apa saja..";
        cin.get();
    }
    
    bool masuk(){
        string usr, pw;
        bersihkan();
        cout << "\nmasuk" << endl;
        cout << "nama pengguna: ";
        cin >> usr;
        cout << "kata sandi: ";
        cin >> pw;
        
        for(int i = 0; i < jumlahpengguna; i++){
            if(datapengguna[i].namapengguna == usr && datapengguna[i].katasandi == pw){
                penggunamasuk = usr;
                tipemasuk = datapengguna[i].tipe;
                cout << "masuk berhasil!" << endl;
                cout << "tekan apa saja...";
                cin.ignore();
                cin.get();
                return true;
            }
        }
        
        cout << "nama pengguna atau kata sandi salah!" << endl;
        cout << "tekan apa saja..";
        cin.ignore();
        cin.get();
        return false;
    }
    
    void buatrekening(){
        if(jumlahrekening >= MAKSREKENING){
            cout << "Maaf, data rekening sudah penuh!" << endl;
            cout << "tekan apa saja..";
            cin.ignore();
            cin.get();
            return;
        }
        
        string no, jns;
        double uang;
        bersihkan();
        
        for(int i = 0; i < jumlahrekening; i++){
            if(datarekening[i].namapengguna == penggunamasuk){
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
        
        rekening baru(penggunamasuk, no, jns, uang);
        datarekening[jumlahrekening] = baru;
        jumlahrekening++;
        simpandatarekening();
        
        cout << "rekening berhasil dibuat dan tersimpan!" << endl;
        cout << "tekan apa saja..";
        cin.ignore();
        cin.get();
    }
    
    void lihatrekening(){
        bersihkan();
        cout << "\n rekening saya " << endl;
        
        for(int i = 0; i < jumlahrekening; i++){
            if(datarekening[i].namapengguna == penggunamasuk){
                datarekening[i].tampil();
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
    
    void semuapengguna(){
        bersihkan();
        cout << "\nsemua pengguna" << endl;
        
        if(jumlahpengguna == 0){
            cout << "gak ada pengguna" << endl;
            cout << "tekan apa saja..";
            cin.ignore();
            cin.get();
            return;
        }
        
        for(int i = 0; i < jumlahpengguna; i++){
            cout << "\npengguna ke-" << (i + 1) << ":" << endl;
            datapengguna[i].tampil();
            cout << "--------------------" << endl;
        }
        
        cout << "\ntekan apa saja..";
        cin.ignore();
        cin.get();
    }
    
    void semuarekening(){
        bersihkan();
        cout << "\nsemua rekening" << endl;
        
        if(jumlahrekening == 0){
            cout << "gak ada rekening!" << endl;
            cout << "tekan apa saja..";
            cin.ignore();
            cin.get();
            return;
        }
        
        for(int i = 0; i < jumlahrekening; i++){
            cout << "\nrekening ke-" << (i + 1) << ":" << endl;
            datarekening[i].tampil();
            cout << "--------------------" << endl;
        }
        
        cout << "\ntekan apa saja..";
        cin.ignore();
        cin.get();
    }
    
    void menuadmin(){
        int pilih;
        do{
            bersihkan();
            cout << "\nhalo komdigiii: " << penggunamasuk << endl;
            cout << "\nmenu admin" << endl;
            cout << "1. lihat semua pengguna" << endl;
            cout << "2. lihat semua rekening" << endl;
            cout << "3. keluar" << endl;
            cout << "pilih: ";
            cin >> pilih;
            
            switch(pilih){
                case 1:
                    semuapengguna();
                    break;
                case 2:
                    semuarekening();
                    break;
                case 3:
                    cout << "keluar berhasil!" << endl;
                    penggunamasuk = "";
                    tipemasuk = "";
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
    
    void menunasabah(){
        int pilih;
        do{
            bersihkan();
            cout << "\nhalo: " << penggunamasuk << endl;
            cout << "\n menu nasabah" << endl;
            cout << "1. buat rekening" << endl;
            cout << "2. lihat rekening" << endl;
            cout << "3. keluar" << endl;
            cout << "pilih: ";
            cin >> pilih;
            
            switch(pilih){
                case 1:
                    buatrekening();
                    break;
                case 2:
                    lihatrekening();
                    break;
                case 3:
                    cout << "keluar berhasil!" << endl;
                    penggunamasuk = "";
                    tipemasuk = "";
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
    
    void mulai(){
        int pilih;
        cout << "isii" << endl;
        cout << jumlahpengguna << " pengguna" << endl;
        cout << jumlahrekening << " rekening" << endl;
        cout << "tekan apa saja untuk lanjut..";
        cin.get();
        
        do{
            bersihkan();
            cout << "sistem bank sederhana" << endl;
            cout << "\nregistrasi dan login" << endl;
            cout << "1. masuk" << endl;
            cout << "2. daftar" << endl;
            cout << "3. keluar" << endl;
            cout << "pilih: ";
            cin >> pilih;
            
            switch(pilih){
                case 1:
                    if(masuk()){
                        if(tipemasuk == "admin"){
                            menuadmin();
                        } else {
                            menunasabah();
                        }
                    }
                    break;
                case 2:
                    daftar();
                    break;
                case 3:
                    bersihkan();
                    cout << "makasih udah pake sistem bank!" << endl;
                    cout << "semua data udah tersimpan di file." << endl;
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

int main(){
    bank sistem;
    sistem.mulai();
    return 0;
}