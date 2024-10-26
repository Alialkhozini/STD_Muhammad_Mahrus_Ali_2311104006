#include <iostream>
using namespace std;

struct Elemen {
    int data;
    Elemen* next;
};

struct List {
    Elemen* first;
};

void createList(List& L) {
    L.first = NULL;
}

Elemen* alokasi(int x) {
    Elemen* P = new Elemen;
    if (P != NULL) {
        P->data = x;
        P->next = NULL;
    }
    return P;
}

void insertFirst(List& L, Elemen* P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    Elemen* P = L.first;
    while (P != NULL) {
        cout << P->data << " ";
        P = P->next;
    }
    cout << endl;
}

Elemen* findElm(List L, int x) {
    Elemen* P = L.first;
    while (P != NULL)
    {
        if (P->data == x) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

int sumAllElements(List L) {
    int total = 0;
    Elemen* P = L.first;
    while (P != NULL) {
        total += P->data;
        P = P ->next;
    }
    return total;
}