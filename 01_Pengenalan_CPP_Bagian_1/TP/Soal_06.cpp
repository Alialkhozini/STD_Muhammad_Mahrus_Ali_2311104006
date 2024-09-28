#include <iostream>

using namespace std;

int main() {
    
    int a, b, bilangan;
    cout << "Masukkan Batas Bawah: " ;
    cin >> a;

    cout << "Masukkan Batas Atas: " ;
    cin >> b;

    for (bilangan = a; bilangan <= b; bilangan++) {
        cout << "Bilangan " << bilangan << endl;
    }

    return 0;
}