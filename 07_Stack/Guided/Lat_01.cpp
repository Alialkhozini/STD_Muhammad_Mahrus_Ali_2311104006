#include <iostream>
using namespace std;

string arrayBuku[5];
int MAX = 5, top = 0;

bool isFull() {
    return (top == MAX);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBook(string data) {
    if (isFull()) {
        cout << "Stack Penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBook() {
    if (isEmpty()) {
        cout << "Stack kosong, tidak ada yang bisa dikeluarkan" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBook(int posisi) {
    if (isEmpty()) {
        cout << "Stack kosong, tidak ada yang bisa dilihat" << endl;
    } else {
        int index = top - posisi;
        if (index >= 0) {
            cout << "Posisi ke-" << posisi << " adalah " << arrayBuku[index] << endl;
        } else {
            cout << "Posisi di luar batas stack" << endl;
        }
    }
}

int countStack() {
    return top;
}

void changeArrayBook(int posisi, string data) {
    int index = top - posisi;
    if (index >= 0) {
        arrayBuku[index] = data;
    } else {
        cout << "Posisi melebihi data yang ada" << endl;
    }
}

void destroyArrayBook() {
    for (int i = top - 1; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Stack kosong, tidak ada yang bisa dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBook("Pemrograman OOP");
    pushArrayBook("Struktur Data");
    pushArrayBook("Logika Matematika");
    pushArrayBook("Proses Perangkat Lunak");
    pushArrayBook("Teknologi Perangkat Lunak untuk Masyarakat");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah Data Stack Penuh: " << isFull() << endl;
    cout << "Apakah Data Stack Kosong: " << isEmpty() << endl;

    peekArrayBook(2);
    popArrayBook();

    cout << "Banyaknya Data: " << countStack() << endl;
    changeArrayBook(4, "Manajemen Proses Bisnis");
    cetakArrayBuku();
    destroyArrayBook();

    cout << "Jumlah Data Setelah dihapus: " << countStack() << endl;
    cetakArrayBuku();

    return 0;
}