#include <iostream>
using namespace std;

struct Node {
  string data;
  Node* next;
};

Node* front = nullptr;
Node* back = nullptr;

bool isEmpty() {
  return front == nullptr;
}

void enqueueAntrian(string data) {
  Node* newNode = new Node();
  newNode->data = data;
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

int countQueue() {
  int count = 0;
  Node* temp = front;
  while (temp != nullptr) {
    count++;
    temp = temp->next;
  }
  return count;
}

void clearQueue() {
  while (!isEmpty()) {
    dequeueAntrian();
  }
}

void viewQueue() {
  cout << "Data antrian:" << endl;
  Node* temp = front;
  int position = 1;
  while (temp != nullptr) {
    cout << position++ << ". " << temp->data << endl;
    temp = temp->next;
  }
}

int main() {
  enqueueAntrian("Andi");
  enqueueAntrian("Maya");
  viewQueue();
  cout << "Jumlah Antrian = " << countQueue() << endl;
  dequeueAntrian();
  viewQueue();
  cout << "Jumlah Antrian = " << countQueue() << endl;
  clearQueue();
  viewQueue();
  cout << "Jumlah Antrian = " << countQueue() << endl;
  return 0;
}
