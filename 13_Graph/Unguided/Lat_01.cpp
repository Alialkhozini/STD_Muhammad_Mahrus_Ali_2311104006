#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;  
    cout << "Silakan masukan jumlah simpul: ";
    cin >> n;

    string kota[n];
    int jarak[n][n];

    
    for (int i = 0; i < n; i++) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> kota[i];
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                jarak[i][j] = 0;  
            } else {
                cout << kota[i] << "-->" << kota[j] << " : ";
                cin >> jarak[i][j];
            }
        }
    }

    
    cout << endl << "Matriks jarak antar kota:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << jarak[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}