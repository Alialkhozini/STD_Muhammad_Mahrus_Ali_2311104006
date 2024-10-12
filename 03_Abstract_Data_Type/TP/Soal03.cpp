#include <iostream>

using namespace std;
// Contoh Pengunaan Pointer

int main(){
    int a = 12;
    int* ptr = &a;

    cout << "Nilai Dari num: " << a << endl;
    cout << "Alamat Memori Dari num: " << ptr << endl;
    cout << "Nilai Yang Dirujuk: " << *ptr << endl;
    *ptr = 36;
    cout << "Setelah Di Pointer: " << a << endl;

    return 0;
}