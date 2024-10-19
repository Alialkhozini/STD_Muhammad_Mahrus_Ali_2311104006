#include <iostream>
#include "list.cpp"

using namespace std;

int main() {
    List head;

    createList(head);

    cout << "Masukkan NIM perdigit" << endl;

    for (int i = 0; i < 10; i++) {
        int number;

        cout << "Digit " << i+1 << " : ";
        cin >> number;

        address elm = allocate(number);

        insertLast(head, elm);
    }

    printInfo(head);

    return 0;
}
