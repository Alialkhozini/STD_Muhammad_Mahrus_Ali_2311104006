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

bool searchNode(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int hitungNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
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
    
    int cariValue = 20;
    if (searchNode(head, cariValue)) {
        cout << "Node dengan nilai " << cariValue << " ditemukan." << endl;
    } else {
        cout << "Node dengan nilai " << cariValue << " tidak ditemukan." << endl;
    }

    cout << "Panjang linked list: " << hitungNodes(head) << endl;

    return 0;
}