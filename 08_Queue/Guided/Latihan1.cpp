#include <iostream>
using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;

string queueTeller[5];

bool isFull() {
  if (back == maksimalQueue) {
    return true;
  } else {
    return false;
  }
}

bool isEmpty() {
  if (back == 0) {
    return true;
  } else {
    return false;
  }
}

void enqueueAntrian(string data) {
  // Fungsi menambahkan antrian
  if (isFull()) {
    cout << "Antrian Penuh" << endl;
  } else {
    if (isEmpty()) {
      // Kondisi ketika queue kosong
      queueTeller[0] = data;
      front++;
      back++;
    } else {
      queueTeller[back] = data;
      back++;
    }
  }
}

void dequeueAntrian() {
  // Fungsi mengurangi antrian
  if(isEmpty()) {
    cout << "Antrian kosong" << endl;
  } else {
    // Pindahkan elemen ke depan
    for(int i = 0; i < back - 1; i++) {
      queueTeller[i] = queueTeller[i + 1];
    }
    queueTeller[back - 1] = ""; // Kosongkan elemen terakhir
    back--;
  }
}

int countQueue() {
  // Fungsi menghitung banyak antrian
  return back;
}

void clearQueue() {
  // Fungsi menghapus semua antrian
  if(isEmpty()) {
    cout << "Antrian Kosong" << endl;
  } else {
    for(int i = 0; i < back; i++) {
      queueTeller[i] = "";
    }
    back = 0;
    front = 0;
  }
}

void viewQueue() {
  // Fungsi melihat antrian
  cout << "Data antrian teller:" << endl;
  for(int i = 0; i < maksimalQueue; i++) {
    if (queueTeller[i] != "") {
      cout << i + 1 << ". " << queueTeller[i] << endl;
    } else {
      cout << i + 1 << ". (kosong)" << endl;
    }
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