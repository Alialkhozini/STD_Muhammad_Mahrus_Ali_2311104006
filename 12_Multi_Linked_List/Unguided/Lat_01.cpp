#include <iostream>
#include <string>
using namespace std;

struct Proyek {
    string nama_proyek;
    int durasi;
    Proyek* next;
};

struct Pegawai {
    string nama;
    string id;
    Proyek* proyek;
    Pegawai* next;
};

// buat List Kosong
void createPegawaiList(Pegawai*& head) {
    head = nullptr;
}
//  buat list Kosong
void createProyekList(Proyek*& head) {
    head = nullptr;
}

// Buat tambah pengawai baru 
void addPegawaiBaru(Pegawai*& head, const string& nama, const string& id) {
    Pegawai* newPegawai = new Pegawai;
    newPegawai->nama = nama;
    newPegawai->id = id;
    newPegawai->proyek = nullptr;
    newPegawai->next = nullptr;

    // Jika Head/List Kosong
    if (head == nullptr) {
        head = newPegawai; // Head di isi Pegawai Baru Jika List Kosong bakalan pindah ke elemen Pertama
    } else { 
        Pegawai* temp = head;
        while ( temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newPegawai;
    }
}
// buat tambah proyek ke dalam pegawai
void addProyek(Pegawai* head, const string& nama_proyek, int durasi){
    while (head != nullptr) {
        Proyek* newProyek = new Proyek;
        newProyek->nama_proyek = nama_proyek;
        newProyek->durasi = durasi;
        newProyek->next = head->proyek;
        head->proyek = newProyek;
        break;
    }
}
// Hapus Proyek Berdasarkan nama Proyek
void removeProyek(Pegawai* head, const string& nama_proyek) {
    while (head != nullptr) {
        Proyek* prev = nullptr;
        Proyek* curr = head->proyek;

        while (curr != nullptr) {
            if (curr->nama_proyek == nama_proyek) {
                if (prev == nullptr) {
                    head->proyek = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        head = head->next;  
        break;
    }
}

// Display
void display(Pegawai* head) {
    // Mengecek Kondisi Apakah Kosong untuk List Pegawai?
    while (head != nullptr) {
        // Kalo Ada maka bakalan display
        cout << "Nama Pegawai: " << head->nama << " ID Pegawai: " << head->id << endl;

        // Panggil Pointer/List Proyek nya
        Proyek* proyek = head->proyek;
        // Cek Apakah Kosong Untuk list Proyek nya
        while ( proyek != nullptr) {
            // Kalo ada bakal display
            cout << "Nama Proyek: " << proyek->nama_proyek << " Durasi Proyek: " << proyek->durasi << " Bulan." << endl;
            proyek = proyek->next;
        }
        cout << endl;
        head = head->next;
    }
}

int main() {
    // Deklarasi/Panggil di Main
    Pegawai* listPegawai;
    createPegawaiList(listPegawai);

    // Buat Pegawai
    addPegawaiBaru(listPegawai, "Andi", "P001");
    addPegawaiBaru(listPegawai, "Budi", "P002");
    addPegawaiBaru(listPegawai, "Citra", "P003");

    // add Proyek
    addProyek(listPegawai, "Aplikasi Mobile", 12);
    addProyek(listPegawai->next, "Sistem Akutansi", 8);
    addProyek(listPegawai->next->next, "E-Commerce", 10);
    // add buat si andi
    addProyek(listPegawai, "Analisis Data", 6);
    // Remove Aplikasi Mobile dari si andi
    removeProyek(listPegawai, "Aplikasi Mobile");

    cout << "Data Pegawai Dan Proyek nya:\n";
    display(listPegawai);

    return 0;
}