#include <iostream>
using namespace std;

struct Node {
  string name;
  string NIM;
  Node* next;
};

Node* front = nullptr;
Node* back = nullptr;

bool isEmpty() {
  return front == nullptr;
}

void enqueueAntrian(string name, string NIM) {
  Node* newNode = new Node();
  newNode->name = name;
  newNode->NIM = NIM;
  newNode->next = nullptr;

  if (isEmpty()) {
    front = back = newNode;
  } else {
    back->next = newNode;
    back = newNode;
  }
}

void dequeueAntrian() {
  if (isEmpty()) {
    cout << "Antrian kosong" << endl;
  } else {
    Node* temp = front;
    front = front->next;
    delete temp;
    if (front == nullptr) {
      back = nullptr;
    }
  }
}

void viewQueue() {
  cout << "Data antrian mahasiswa:" << endl;
  Node* temp = front;
  int position = 1;
  while (temp != nullptr) {
    cout << position++ << ". Nama: " << temp->name << ", NIM: " << temp->NIM << endl;
    temp = temp->next;
  }
}

int main() {
  enqueueAntrian("Andi", "A23111001");
  enqueueAntrian("Maya", "A23111002");
  viewQueue();
  dequeueAntrian();
  viewQueue();
  return 0;
}
