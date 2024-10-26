#include "SingleList.cpp"

int main() {
    List L;
    Elemen* P1, *P2, *P3, *P4, *P5 = NULL;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    Elemen* found = findElm(L, 8);
    if (found != NULL) {
        cout << found->data << " Ditemukan dalam List " << endl;
    } else {
        cout << " Elemen Tidak Ditemukan dlam List " << endl;
    }

    int total = sumAllElements(L);
    cout << "Total Info dari kelima elemen adalah " << total << endl;

    return 0;
}