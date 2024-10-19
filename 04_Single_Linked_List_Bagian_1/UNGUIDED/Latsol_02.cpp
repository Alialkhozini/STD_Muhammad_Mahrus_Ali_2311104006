#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

void insertAtFront(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = nullptr;

    if (temp != nullptr && temp->data == key) {
        *head = temp->next;
        delete temp;
        return;
    }

    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Node dengan nilai " << key << " tidak ditemukan." << endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
}


void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data;
        if (node->next != nullptr) {
            cout << " -> ";
        }
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    insertAtFront(&head, 10); 
    insertAtEnd(&head, 20);   
    insertAtFront(&head, 5);  
    
    cout << "Linked List Sebelum Dihapus: ";
    printList(head);

    deleteNode(&head, 10);
    cout << "Linked List Setelah Dihapus: ";
    printList(head);

    return 0;
}