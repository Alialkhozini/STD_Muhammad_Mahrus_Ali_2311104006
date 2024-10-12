#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m);
float rata2 (mahasiswa m);

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata = " << rata2(mhs);
    return 0; 
}

void inputMhs(mahasiswa &m){
    cout << "input NIM: " ;
    cin >> (m).nim;
    cout << "input Nilai1: ";
    cin >> (m).nilai1;
    cout << "input Nilai2: ";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m) {
    return (m.nilai1 + m.nilai2) / 2;
}