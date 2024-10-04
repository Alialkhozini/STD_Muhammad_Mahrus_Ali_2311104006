#include <iostream>

using namespace std;

int kendaraan(int kapasitas_kendaraan, int jumlah_penumpang) {
    int jumlah;

    jumlah = jumlah_penumpang / kapasitas_kendaraan;

    if (jumlah_penumpang % kapasitas_kendaraan > 0) {
        jumlah++;
    }

    return jumlah;
}

int main() {
    int kapasitas_kendaraan, jumlah_kendaraan, banyak_kendaraan;

    cout << "Masukkan kapasitas kendaraan: ";
    cin >> kapasitas_kendaraan;

    cout << "Masukkan jumlah penumpang: ";
    cin >> jumlah_kendaraan;

    banyak_kendaraan = kendaraan(kapasitas_kendaraan, jumlah_kendaraan);

    cout << "Banyak kendaraan yang disewa: " << banyak_kendaraan << endl;

    return 0;
}