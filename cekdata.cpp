#include <iostream>
using namespace std;

class dataDiri
{
private:
    string nama = "hasbi";
    int NIM = 241402038;

public:
    string getNama()
    {
        return nama;
    }

    int getNIM()
    {
        return NIM;
    }

    void setNama(string nama)
    {
        this->nama = nama;
    }

    void setNIM(int NIM)
    {
        this->NIM = NIM;
    }
};

class output : public dataDiri
{
public:
    void tampilan()
    {
        cout << "Nama : " << getNama() << endl;
        cout << "NIM : " << getNIM() << endl;
    }
};

int main()
{
    output obj;
    obj.tampilan();
    return 0;
};