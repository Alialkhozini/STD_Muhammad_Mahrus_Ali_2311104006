#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* prev;
  Node* next;
};

void insertFirst(Node*& head, int data) {
  Node* newNode = new Node();
  newNode->data = data;
  newNode->prev = nullptr;
  newNode->next = head;
  if (head != nullptr) {
    head->prev = newNode;
  }
  head = newNode;
}

void insertLast(Node*& head, int data) {
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = nullptr;

  if (head == nullptr) {
    newNode->prev = nullptr;
    head = newNode;
    return;
  }

  Node* temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }

  temp->next = newNode;
  newNode->prev = temp;
}

void deleteFirst(Node*& head) {
  if (head == nullptr) {
    cout << "List kosong, tidak ada elemen yang bisa dihapus." << endl;
    return;
  }

  Node* temp = head;
  head = head->next;

  if (head != nullptr) {
    head->prev = nullptr;
  }

  delete temp;
}

void deleteLast(Node*& head) {
  if (head == nullptr) {
    cout << "List kosong, tidak ada elemen yang bisa dihapus." << endl;
    return;
  }

  if (head->next == nullptr) { 
    delete head;
    head = nullptr;
    return;
  }

  Node* temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }

  temp->prev->next = nullptr;
  delete temp;
}

void displayList(Node* head) {
  if (head == nullptr) {
    cout << "DAFTAR ANGGOTA LIST SETELAH PENGHAPUSAN: List kosong." << endl;
    return;
  }

  Node* temp = head;
  cout << "DAFTAR ANGGOTA LIST SETELAH PENGHAPUSAN: ";
  while (temp != nullptr) {
    cout << temp->data;
    if (temp->next != nullptr) {
        cout << " <-> ";
    }
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  Node* head = nullptr;

  int firstElm, secondElm, thirdElm;
  cout << "Masukkan elemen pertama = ";
  cin >> firstElm;
  insertFirst(head, firstElm);

  cout << "Masukkan elemen kedua di akhir = ";
  cin >> secondElm;
  insertLast(head, secondElm);

  cout << "Masukkan elemen ketiga di akhir = ";
  cin >> thirdElm;
  insertLast(head, thirdElm);

  deleteFirst(head);
  deleteLast(head);
  displayList(head);
}