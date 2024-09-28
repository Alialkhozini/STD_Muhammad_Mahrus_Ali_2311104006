#include <iostream>

using namespace std;

int main () {
    float bil1, bil2;
    float hasil;
    


    cout << "Masukkan Bilangan Pertama: ";
    cin >> bil1;

    cout << "Masukkan Bilangan Kedua: ";
    cin >> bil2;

    hasil = bil1 + bil2;
    cout << "Hasil Penjumlahan Dari " << bil1 << " + " << bil2 << " Adalah " << hasil << endl;
    hasil = bil1 - bil2;
    cout << "Hasil Pengurangan Dari " << bil1 << " - " << bil2 << " Adalah " << hasil << endl;
    hasil = bil1 * bil2;
    cout << "Hasil Perkalian Dari " << bil1 << " x " << bil2 << " Adalah " << hasil << endl;
    hasil = bil1 / bil2;
    cout << "Hasil Pembagian Dari " << bil1 << " : " << bil2 << " Adalah " << hasil << endl;

    return 0;

}