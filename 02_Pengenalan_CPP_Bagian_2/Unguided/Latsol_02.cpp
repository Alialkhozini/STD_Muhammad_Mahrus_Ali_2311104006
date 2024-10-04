#include <iostream>

using namespace std;

int main() {
    int x, y, z;

    cout << "Masukkan dimensi x: ";
    cin >> x;

    cout << "Masukkan dimensi y: ";
    cin >> y;

    cout << "Masukkan dimensi z: ";
    cin >> z;

    cout << endl << "Masukkan nilai bertipe integer" << endl;

    int arr[x][y][z];
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "Array[" << i << "][" << j << "][" << k << "] = ";
                cin >> arr[i][j][k];
            }
        }
    }

    cout << endl << "Array = [";

    for (int i = 0; i < x; i++) {
        cout << "[";

        for (int j = 0; j < y; j++) {
            cout << "[";

            for (int k = 0; k < z; k++) {
                cout << arr[i][j][k];

                if (k + 1 < z) {
                    cout << ", ";
                }
            }

            if (j + 1 < y) {
                cout << "], ";
            } else {
                cout << "]";
            }
        }

        if (i + 1 < x) {
            cout << "], ";
        } else {
            cout << "]";
        }
    }

    cout << "];" << endl;

    return 0;
}