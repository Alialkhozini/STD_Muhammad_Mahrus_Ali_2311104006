#include <iostream>
using namespace std;

struct Node {
  string name;
  string NIM;
  Node* next;
};

Node* front = nullptr;

bool isEmpty() {
  return front == nullptr;
}

void enqueueAntrian(string name, string NIM) {
  Node* newNode = new Node();
  newNode->name = name;
  newNode->NIM = NIM;
  newNode->next = nullptr;

  if (isEmpty() || NIM < front->NIM) {
    newNode->next = front;
    front = newNode;
  } else {
    Node* current = front;
    while (current->next != nullptr && current->next->NIM < NIM) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }
}

void dequeueAntrian() {
  if (isEmpty()) {
    cout << "Antrian kosong" << endl;
  } else {
    Node* temp = front;
    front = front->next;
    delete temp;
  }
}

void viewQueue() {
  cout << "Data antrian mahasiswa (berdasarkan prioritas NIM):" << endl;
  Node* temp = front;
  int position = 1;
  while (temp != nullptr) {
    cout << position++ << ". Nama: " << temp->name << ", NIM: " << temp->NIM << endl;
    temp = temp->next;
  }
}

int main() {
  enqueueAntrian("Andi", "A23111003");
  enqueueAntrian("Maya", "A23111001");
  enqueueAntrian("Budi", "A23111002");
  viewQueue();
  dequeueAntrian();
  viewQueue();
  return 0;
}
