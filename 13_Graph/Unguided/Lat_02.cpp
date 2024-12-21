#include <iostream>
using namespace std;

int main() {

    int n, e;
    

    cout << "Masukkan jumlah simpul: ";
    cin >> n;
    cout << "Masukkan jumlah sisi: ";
    cin >> e;


    int adjMatrix[n][n];
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }


    cout << "Masukkan pasangan simpul yang terhubung (misal: 1 2):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        

        adjMatrix[u-1][v-1] = 1;
        adjMatrix[v-1][u-1] = 1;  
    }

    
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}