#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void tulis(int x);

int main() {
    system("cls");

    int jumlah;

    cout << "Jumlah baris kata: ";
    cin >> jumlah;

    tulis(jumlah);
    getch();

    return 0;
}

void tulis(int x) {
    for (int i = 0; i < x; i++) {
        cout << "Baris ke-" << i + 1 << endl;
    }
}