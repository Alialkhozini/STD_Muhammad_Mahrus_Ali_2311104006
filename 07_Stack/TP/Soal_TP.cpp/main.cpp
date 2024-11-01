#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    stack S;
    createStack(S);

    char frasaAwal[] = {'P', 'E', 'R', 'C', 'A', 'Y', 'A', 'D', 'I', 'R', 'I'};
    char frasaPop[] = {'D', 'I', 'R', 'I'};

    for (char c : frasaAwal) {
        push(S, c);
    }

    cout << "\nIsi stack awal: ";
    printInfo(S);

    cout << "Isi stack setelah pop: ";
    for (char c : frasaPop) {
        pop(S);
    }
    printInfo(S);

    return 0;
}