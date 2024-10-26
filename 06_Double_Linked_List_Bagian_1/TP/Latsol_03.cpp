#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* prev;
  Node* next;
};

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

void displayForward(Node* head) {
  Node* temp = head;
  cout << "Daftar elemen dari depan ke belakang: ";
  while (temp != nullptr) {
    cout << temp->data;
    if (temp->next != nullptr) {
      cout << " <-> ";
    }
    temp = temp->next;
  }
  cout << endl;
}

void displayBackward(Node* head) {
  if (head == nullptr) return;

  Node* temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }

  cout << "Daftar elemen dari belakang ke depan: ";
  while (temp != nullptr) {
    cout << temp->data;
    if (temp->prev != nullptr) {
      cout << " <-> ";
    }
    temp = temp->prev;
  }
  cout << endl;
}

int main() {
  Node* head = nullptr;
  int n, data;

  cout << "Masukkan 4 elemen secara berurutan: ";
  for (int i = 0; i < 4; i++) {
    cin >> data;
    insertLast(head, data);
  }

  displayForward(head);
  displayBackward(head);
}