#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertSorted(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr || head->data >= value) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
    
        while (temp->next != nullptr && temp->next->data < value) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int element;

    cout << "Masukkan 4 elemen integer secara terurut: " << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Elemen ke-" << (i + 1) << ": ";
        cin >> element;
        insertSorted(head, element);
    }

    cout << "List sebelum menambahkan elemen baru: ";
    displayList(head);

    cout << "Masukkan elemen tambahan untuk dimasukkan: ";
    cin >> element;

    insertSorted(head, element);
    cout << "List setelah menambahkan elemen baru: ";
    displayList(head);
}