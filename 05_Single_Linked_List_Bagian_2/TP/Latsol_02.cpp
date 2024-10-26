#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


void insertLast(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
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

void bubbleSortList(Node* head) {
    if (head == nullptr) return;

    bool swapped;
    Node* current;
    Node* lastPtr = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != lastPtr) {
            if (current->data > current->next->data) {
                
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        lastPtr = current;
    } while (swapped);
}

int main() {
    Node* head = nullptr;

    cout << "Masukkan 5 elemen integer ke dalam list: " << endl;
    for (int i = 0; i < 5; i++) {
        int element;
        cout << "Elemen ke-" << (i + 1) << ": ";
        cin >> element;
        insertLast(head, element);
    }

    cout << "List sebelum diurutkan: ";
    displayList(head);

    bubbleSortList(head);

    cout << "List setelah diurutkan: ";
    displayList(head);

    return 0;
}
