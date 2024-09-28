#include <iostream>

using namespace std;

int main(){
    int nilai;
    
    cout << "Masukkan NiLai Anda: " << endl;
    cin >> nilai;

    if(nilai > 80) {
        cout << "A" << endl;
    } else {
        cout << "Bukan A" << endl;
    }

}