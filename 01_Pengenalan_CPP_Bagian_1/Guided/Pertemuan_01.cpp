#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main()
{
    // cout << "Saya lagi belajar c++ nih!" << endl;

    /*
    int usia;
    cout << "Usia saya: ";
    cin >> usia;
    cout << "Usia saya " << usia << " tahun" << endl;
    */

    /*
    float w, x, y;
    float z;

    x = 7;
    y = 3;
    w = 1;

    z = (x + y) / (y + w);

    cout << "Nilai z = " << z << endl;
    */

    /*
    double total_pembelian, diskon;
    cout << "Total pembelian = Rp. ";
    cin >> total_pembelian;

    diskon = 0;

    if (total_pembelian >= 100000)
        diskon = 0.05 * total_pembelian;
    else
        diskon = 0;

    cout << "Besar diskon = Rp. " << diskon << endl;;
    cout << "Total pembelian = Rp. " << total_pembelian - diskon << endl;
    */

    int i = 1;
    int jumlah;

    cin >> jumlah;

    do {
        cout << "Baris ke-" << i+1 << endl;
        i++;
    } while (i < jumlah);
    getch();

    return 0;
}