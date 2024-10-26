#include "DoubleList.h"
int main() {
  List L;
  CreateList(L);
  infotype kendaraan;
  string nopol;

  for (int i = 0; i < 4; i++) { 
    cout << "masukkan nomor polisi: ";
    cin >> kendaraan.nopol;
    
    if (isNopolExists(L, kendaraan.nopol)) {
        cout << "nomor polisi sudah terdaftar" << endl;
        cout << endl;
        continue; 
    }

    cout << "masukkan warna kendaraan: ";
    cin >> kendaraan.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> kendaraan.thnBuat;
    cout << endl;
    
    address P = alokasi(kendaraan);
    insertLast(L, P);
  }
  
  printInfo(L);

  string searchNopol;
  cout << endl;
  cout << "Masukkan Nomor Polisi yang dicari : ";
  cin >> searchNopol;

  printSearchResult(L, searchNopol); 

  string deleteNopol;
  cout << endl;
  cout << "Masukkan Nomor Polisi yang akan dihapus : ";
  cin >> deleteNopol;

  deleteElm(L, deleteNopol);

  printInfo(L);
}