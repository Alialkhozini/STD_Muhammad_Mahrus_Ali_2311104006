#include <iostream>
using namespace std;

struct Mahasiswa {
  int nim;
  string nama;
};

struct Node{
  Mahasiswa info;
  Node* next;
};

void tambahMahasiswa(Node*& head, int nim, string nama) {
  Node* newNode = new Node();
  newNode->info.nim = nim;
  newNode->info.nama = nama;
  newNode->next = nullptr;

  if(!head) {
    head = newNode;
  } else {
    Node* temp = head;
    while(temp -> next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
  cout << "Mahasiswa dengan NIM "<< nim << " sukses ditambahkan" << endl;
}

void cariMahasiswa(Node* head, int nim) {
  Node* temp = head;
  while(temp) {
    if(temp->info.nim == nim) {
      cout << "Mahasiswa ditemukan: " << temp->info.nama << endl;
      return;
    }
    temp = temp->next;
  }
  cout << "Mahasiswa dengan NIM" << nim << "tidak ditemukan." << endl;
}

void tampilkanSemuaMahasiswa(Node* head) {
  if(!head) {
    cout << "Daftar Mahasiswa kosong." << endl;
    return;
  }
  Node* temp = head;
  while (temp) {
    cout << "NIM: " << temp->info.nim << ", Nama: " << temp->info.nama << endl;
    temp = temp -> next;
  }
}

int main() {
  Node* head = nullptr;
  int pilihan, nim;
  string nama;

  do {
    cout << "\nMenu:\n";
    cout << "1. Tambah Mahasiswa\n";
    cout << "2. Cari Mahasiswa\n";
    cout << "3. Tampilkan Semua Mahasiswa\n";
    cout << "4. Keluar\n";
    cout << "Pilih Opsi: ";
    cin >> pilihan;
    switch (pilihan) {
      case 1:
        cout << "Masukkan NIM Mahasiswa: ";
        cin >> nim;
        cin.ignore(); 
        cout << "Masukkan Nama Mahasiswa: ";
        getline(cin, nama);
        tambahMahasiswa(head, nim, nama);
        break;

      case 2:
        cout << "Masukkan NIM yang dicari: ";
        cin >> nim;
        cariMahasiswa(head, nim);
        break;
        
      case 3:
        tampilkanSemuaMahasiswa(head);
        break;

      case 4:
        cout << "Keluar dari program." << endl;
        break;

      default:
        cout << "Opsi tidak valid." << endl;
    }
  } while (pilihan != 4);
  return 0;
}