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
  if(head != nullptr) {
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

void displayList(Node* head) {
  Node* temp = head;
  cout << "DAFTAR ANGGOTA LIST: ";
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

  cout << "Masukkan elemen kedua di awal = ";
  cin >> secondElm;
  insertFirst(head, secondElm);

  cout << "Masukkan elemen ketiga di akhir = ";
  cin >> thirdElm;
  insertLast(head, thirdElm);

  displayList(head);

  return 0;
}