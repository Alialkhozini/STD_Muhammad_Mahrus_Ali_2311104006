#include <iostream>
#include <string>
using namespace std;

// STRUCT BUKU
struct Buku {
    string judul;
    string tanggal_pengembalian;
    Buku* next;
};
// STRUCT ANGGOTA
struct Anggota {
    string nama;
    string id;
    Buku* bukuPinjam;
    Anggota* next;
};

// BUAT DAFTAR ANGGOTA
void createAnggota(Anggota*& head) {
    head = nullptr;
}

// TAMBAH ANGGOTA BARU
void addAnggota(Anggota*& head, const string& nama, const string& id) {
    // Deklarasi Dulu varr newAnggota -> Anggota*
    Anggota* newAnggota = new Anggota;
    newAnggota->nama = nama;
    newAnggota->id = id;
    newAnggota->bukuPinjam = nullptr; // Null -> karena kan ini buat add anggota jadi pinjam buku kita null in aja dulu
    newAnggota->next = nullptr;

    // Perbandingan agar list data yang masuk pertama itu tetap pertama
    if (head == nullptr) {
        // Kalo masih kosong head di isi new Anggota
        head = newAnggota;
    } else {
        // kalo enggak buat varr temporary
        Anggota* temp = head;
        // LOoping sampai temp bakal jalan ke next sampai data nya itu gak null/gak kosong
        while (temp->next != nullptr) {
            // Maka temp di isi sama lokasi/value hasil dari looping
            temp = temp->next;
        }
        temp->next = newAnggota; // maka akhirnya di isi dengan newAnggota
    }
}

// Fumgsi Buat AddBuku ke dalan anggota
void addBuku(Anggota* head, const string& judul, const string& tanggal_pengembalian) {
    while ( head != nullptr) {
        Buku* newBuku = new Buku;
        newBuku->judul = judul;
        newBuku->tanggal_pengembalian = tanggal_pengembalian;
        newBuku->next = head->bukuPinjam;
        head->bukuPinjam = newBuku;
        break;
    }
}

// Fungsi untuk menghapus anggota dan buku yang dipinjam
void removeAnggota(Anggota*& head, const string& id) {
    Anggota* prev = nullptr;
    Anggota* curr = head;

    while (curr != nullptr) {
        if (curr->id == id) {
            if (prev == nullptr) {  
                head = curr->next;
            } else {
                prev->next = curr->next;
            }

            Buku* bukuTemp = curr->bukuPinjam;
            while (bukuTemp != nullptr) {
                Buku* tempBuku = bukuTemp;
                bukuTemp = bukuTemp->next;
                delete tempBuku;
            }

            delete curr;
            cout << "Anggota dengan ID " << id << " telah dihapus beserta buku yang dipinjam." << endl;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Display Info
void display(Anggota* head) {
    // Cek kondisi List Anggota nya Kosong atau Enggak
    while ( head != nullptr) {
        // jika kagak kosong (ada)
        cout << "Nama Anggota: " << head->nama << " ID: " << head->id << endl;

        // Sekarang Untuk Buku nya
        // panggil/Deklarasi dulu Pointer Buku nya
        Buku* buku = head->bukuPinjam;
        while ( buku != nullptr) {
            cout << "Nama Buku: " << buku->judul << " Tanggal Pengembalian: " << buku->tanggal_pengembalian << endl;
            buku = buku->next;
        }
        cout << endl;
        head = head->next;
    }
}


int main() {
    // Deklarasi Dulu Disini
    Anggota* listAnggota;
    createAnggota(listAnggota);

    // Tambah Anggota
    addAnggota(listAnggota, "Rani", "A001");
    addAnggota(listAnggota, "Dito", "A002");
    addAnggota(listAnggota, "Vina", "A003");

    // Tambah Buku yang dipinjam
    addBuku(listAnggota, "Pemrograman C++", "01/12/2024");  
    addBuku(listAnggota->next, "Algoritma Pemrograman", "15/12/2024"); 
    addBuku(listAnggota->next->next, "Struktur Data", "10/12/2024");  

    // Tamabh Buku baru buat si rani
    addBuku(listAnggota, "Struktur Data", "10/12/2024");  // Untuk Rani

    // ngapus si dito
    removeAnggota(listAnggota, "A002");

    cout << "Data Anggota dan Buku yang Dipinjam:" << endl;
    display(listAnggota);

    return 0;
}