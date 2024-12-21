// #include <iostream>
// #include <string>
// using namespace std;

// struct Mahasiswa {
//     string nama;
//     string nim;
//     char jenis_kelamin;
//     float ipk;
// };

// typedef Mahasiswa infotype;
// typedef struct elmList *address;

// struct elmList
// {
//     infotype info;
//     address next;
// };

// struct List
// {
//     address first;
// };

// void createList(List &L) {
//     L.first = nullptr;
// }

// address allocate(infotype data) {
//     address P = new elmList;
//     P->info = data;
//     P->next = nullptr;
//     return P;
// }

// void insertFirst(List &L, address P) {
//     if (L.first == nullptr) {
//         L.first = P;
//     } else {
//         address Q = L.first;
//         while (Q->next != nullptr) {
//             Q = Q->next;
//         }
//     }
// }

// void insertLast(List &L, address P) {
//     if (L.first == nullptr) {
//         L.first = P;
//     } else {
//         address Q = L.first;
//         while (Q->next != nullptr) {
//             Q = Q->next;
//         }
//     }
// }

// void insertAfter(address prec, address P) {
//     if (prec != nullptr) {
//         P->next = prec->next;
//         prec->next = P;
//     }
// }


// void printList(const List &L) {
//     address P = L.first;
//     while (P != nullptr) {
//         cout << "Nama: " << P->info.nama << endl;
//         cout << "NIM: " << P->info.nim << endl;
//         cout << "L/P: " << P->info.jenis_kelamin << endl;
//         cout << "IPK: " << P->info.ipk << endl;
//         cout << endl; 
//     }    
// }

// int main() {
//     List L;
//     createList(L);
//      //Memebuat data mahasiswa
//     infotype m1 = {"Ali", "01", 'L', 3.3};
//     infotype m2 = {"Bobi", "02", 'L', 3.71};
//     infotype m3 = {"Cindi", "03", 'P', 3.5};
//     infotype m4 = {"Danu", "04", 'L', 4.0};
//     infotype m5 = {"Eli", "05", 'P', 3.4};
//     infotype m6 = {"Fahmi", "06", 'L', 3.45};
//     infotype m7 = {"Gita", "07", 'P', 3.75};
//     infotype m8 = {"Hilmi", "08", 'L', 3.3};

//     // Alokasi elemen
//     address p1 = allocate(m1);
//     address p2 = allocate(m2);
//     address p3 = allocate(m3);
//     address p4 = allocate(m4);
//     address p5 = allocate(m5);
//     address p6 = allocate(m6);
//     address p7 = allocate(m7);
//     address p8 = allocate(m8);

//     // Memasukkan elemen ke list
//     insertFirst(L, p1);     //Ali
//     insertLast(L, p2);      //Bobi
//     insertLast(L, p4);      //Danu
//     insertAfter(p2, p3);    //Cindi setelah Bobi
//     insertLast(L, p5);      //Eli
//     insertLast(L, p6);      //Fahmi
//     insertLast(L, p7);      //Gita
//     insertLast(L, p8);      //Hilmi

//     // Cetak isi list
//     cout << "Coba insert first, last, dan after\n" << endl;
//     printList(L);

//     return 0;

// }
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
};

typedef Mahasiswa infotype;
typedef struct elmList *address;

struct elmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L) {
    L.first = nullptr;
}

address allocate(infotype data) {
    address P = new elmList;
    P->info = data;
    P->next = nullptr;
    return P;
}

void insertFirst(List &L, address P) {
    // Menyambungkan elemen baru ke depan list
    P->next = L.first;
    L.first = P;
}

void insertLast(List &L, address P) {
    if (L.first == nullptr) {
        // Jika list kosong, buat P sebagai elemen pertama
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;  // Cari elemen terakhir
        }
        Q->next = P;  // Menyambungkan P di akhir list
    }
}

void insertAfter(address prec, address P) {
    if (prec != nullptr) {
        P->next = prec->next;  // Menyambungkan P setelah prec
        prec->next = P;        // Menyambungkan prec ke P
    }
}

void printList(const List &L) {
    address P = L.first;
    while (P != nullptr) {
        cout << "Nama: " << P->info.nama << endl;
        cout << "NIM: " << P->info.nim << endl;
        cout << "L/P: " << P->info.jenis_kelamin << endl;
        cout << "IPK: " << P->info.ipk << endl;
        cout << endl;
        P = P->next;  // Pindah ke elemen berikutnya
    }
}

int main() {
    List L;
    createList(L);

    // Membuat data mahasiswa
    infotype m1 = {"Ali", "01", 'L', 3.3};
    infotype m2 = {"Bobi", "02", 'L', 3.71};
    infotype m3 = {"Cindi", "03", 'P', 3.5};
    infotype m4 = {"Danu", "04", 'L', 4.0};
    infotype m5 = {"Eli", "05", 'P', 3.4};
    infotype m6 = {"Fahmi", "06", 'L', 3.45};
    infotype m7 = {"Gita", "07", 'P', 3.75};
    infotype m8 = {"Hilmi", "08", 'L', 3.3};

    // Alokasi elemen
    address p1 = allocate(m1);
    address p2 = allocate(m2);
    address p3 = allocate(m3);
    address p4 = allocate(m4);
    address p5 = allocate(m5);
    address p6 = allocate(m6);
    address p7 = allocate(m7);
    address p8 = allocate(m8);

    // Memasukkan elemen ke list
    insertFirst(L, p1);     // Ali
    insertLast(L, p2);      // Bobi
    insertLast(L, p4);      // Danu
    insertAfter(p2, p3);    // Cindi setelah Bobi
    insertLast(L, p5);      // Eli
    insertLast(L, p6);      // Fahmi
    insertLast(L, p7);      // Gita
    insertLast(L, p8);      // Hilmi

    // Cetak isi list
    cout << "Coba insert first, last, dan after\n" << endl;
    printList(L);

    return 0;
}