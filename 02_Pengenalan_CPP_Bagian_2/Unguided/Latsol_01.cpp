#include <iostream>

#define MAX 10

using namespace std;

int main() {
    // Deklarasi variabel
    int num[MAX], odd[MAX], even[MAX], oddSize = 0, evenSize = 0;

    // Input loop 10x
    for (int i = 0; i < MAX; i++) {
        cout << "Masukkan angka ke-" << i + 1 << ": ";
        cin >> num[i];
    }

    // Menampilkan angka yang diinputkan
    cout << "Angka yang Diinputkan : ";
    for (int i = 0; i < MAX; i++) {
        cout << num[i] << " ";
    }
    cout << endl;

    // Proses pengecekkan angkan genap/ganjil
    for (int i = 0; i < MAX; i++) {
        if (num[i] % 2 == 0) {
            even[evenSize] = num[i];
            evenSize++;
        } else {
            odd[oddSize] = num[i];
            oddSize++;
        }
    }
    cout << endl;

    // Menampilkan angka genap
    cout << "Angka Genap : ";
    for (int i = 0; i < evenSize; i++) {
        cout << even[i] << " ";
    }
    cout << endl;

    // Menampilkan angka ganjil
    cout << "Angka Ganjil : ";
    for (int i = 0; i < oddSize; i++) {
        cout << odd[i] << " ";
    }
    cout << endl;

    return 0;
}