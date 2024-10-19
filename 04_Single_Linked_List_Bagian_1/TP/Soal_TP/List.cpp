#include <iostream>
#include "list.h"

using namespace std;

void createList(List &L) {
    first(L) = NULL;
}

address allocate(infotype x) {
    address p = new elmlist;
    info(p) = x;
    next(p) = NULL;

    return p;
}

void insertFirst(List &L, address P) {
    next(P) = first(L);
    first(L) = P;
}

void insertLast(List &L, address P) {
    if (first(L) == NULL) {
        insertFirst(L, P);
    } else {
        address Q = first(L);

        while (next(Q) != NULL) {
            Q = next(Q);
        }

        next(Q) = P;
    }
}

void insertAfter(List &L, address P, int Q) {
    address Prec = first(L);

    while ((next(Prec) != NULL) && (info(Prec) != Q)) {
        Prec = next(Prec);
    }

    if (next(Prec) != NULL) {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteFirst(List &L) {
    address P = first(L);
    first(L) = next(P);
    next(P) = NULL;
}

void deleteLast(List &L) {
    address Q = first(L);
    
    while (next(next(Q)) != NULL) {
        Q = next(Q);
    }

    address P = next(Q);
    next(Q) = NULL;
}

void deleteAfter(List &L, int Q) {
    address Prec = first(L);

    while ((next(Prec) != NULL) && (info(Prec) != Q)) {
        Prec = next(Prec);
    }

    address P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;
    delete P;
}

void printInfo(List L) {
    address p = first(L);

    cout << "Isi list : ";

    while (p != NULL) {
        cout << info(p);
        p = next(p);
    }
    cout << endl;
}

int searchInfo(List &L, int P) {
    address Q = first(L);
    address temp = NULL;

    while (Q != NULL) {
        if (info(Q) == P) {
            if (temp == NULL) {
                cout << "Nilai " << P << "pada urutan pertama" << endl;
            } else {
                cout << "Nilai " << P << "setelah nilai " << info(temp) << endl;
            }
            return true;
        }
        temp = Q;
        Q = next(Q);
    }

    cout << "Nilai " << P << " tidak ditemukan!" << endl;
    return false;
}