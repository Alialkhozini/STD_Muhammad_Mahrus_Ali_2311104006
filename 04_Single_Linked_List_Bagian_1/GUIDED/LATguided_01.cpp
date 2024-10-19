#include <iostream>

using namespace std;

struct mahasiswa {
    char nama[30];
    char nim[10];
};

struct Node {
    mahasiswa data;
    Node *next;
};

Node *head;
Node *tail;

void init() {
    head = nullptr;
    tail = nullptr;
}

bool isEmpty() {
    return head == nullptr;
}

void insertDepan(const mahasiswa &data) {
    Node *baru = new Node;

    baru->data = data;
    baru->next = nullptr;

    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

void insertBelakang(const mahasiswa &data) {
    Node *baru = new Node;

    baru->data = data;
    baru->next = nullptr;

    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

int hitungList() {
    Node *current = head;
    int jumlah = 0;

    while (current != nullptr) {
        jumlah++;
        current = current->next;
    }

    return jumlah;
}

void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        head = head->next;
        delete hapus;

        if (head == nullptr) {
            tail == nullptr;
        }
    } else {
        cout << "List Kosong!";
    }
}

void hapusBelakang() {
    if (!isEmpty()) {
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node *bantu = head;

            while (bantu->next != tail) {
                bantu = bantu->next;
            }

            delete tail;
            tail = bantu;
            tail->next = nullptr;
        }
    } else {
        cout << "List Kosong!";
    }
}

void tampil() {
    Node *current = head;

    if (!isEmpty()) {
        while (current != nullptr) {
            cout << "Nama: " << current->data.nama << ", NIM: " << current->data.nim << endl;
            current = current->next;
        }
    } else {
        cout << "List Kosong!" << endl;
    }

    cout << endl;
}

void clearList() {
    Node *current = head;

    while (current  != nullptr) {
        Node *hapus = current;
        current = current->next;
        delete hapus;
    }

    head = tail = nullptr;
    cout << "List Berhasil Dihapus!" << endl;
}

int main() {
    init();

    mahasiswa m1 = {"PAJAR", "123456"};
    mahasiswa m2 = {"REJA", "654321"};
    mahasiswa m3 = {"ALIE", "112233"};

    insertDepan(m1);
    tampil();
    insertBelakang(m2);
    tampil();
    insertDepan(m3);
    tampil();

    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();

    clearList();

    return 0;
}