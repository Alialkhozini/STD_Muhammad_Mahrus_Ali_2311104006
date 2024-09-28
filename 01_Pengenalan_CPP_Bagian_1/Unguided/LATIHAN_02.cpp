#include <iostream>
#include <string>

using namespace std;

string angkaAlfa(int angka) {
    // Satuan - Belasan
    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", 
                    "delapan", "sembilan", "sepuluh", "sebelas", "dua belas", 
                    "tiga belas", "empat belas", "lima belas", "enam belas", 
                    "tujuh belas", "delapan belas", "sembilan belas"};
    // puluhan
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delpan puluh", "sembilan puluh"};

    if(angka < 20){
        return satuan[angka];
    } 
    
    else if (angka < 100) {
        if (angka % 10 == 0) {
            return puluhan[angka / 10];
        } else {
            return puluhan[angka / 10] + " " + satuan[angka % 10]; 
        }
    }
    
    else if (angka == 100) {
        return "seratus" ;
    }

    return ""; 

}

int main() {
    int angka ;

    cout << "Masukan Angka: ";
    cin >> angka;


    if(angka < 0 || angka > 100) {
        cout << "Angka Terlalu Besar Atau Kecil. " << endl;
    } else {
        cout << angka << " Dalam Tulisan: " << angkaAlfa(angka) ;
    }

    return 0;
}