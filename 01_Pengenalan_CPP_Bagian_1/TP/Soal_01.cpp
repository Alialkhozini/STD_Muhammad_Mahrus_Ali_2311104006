#include <iostream>

using namespace std;

int main() {
    string nama, nim; // Inisialisasi

    cout << "Siapa Nama Kamu?: ";
    getline(cin, nama);
    
    cout << "Berapa NIM Kamu?: ";
    cin >> nim;

    cout << "Halo " << nama << " NIM Kamu Adalah: " << nim;

}