#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

void kalimatMundur(string kalimat) {
    stack<string> s;
    stringstream ss(kalimat);
    string kata;

    while (ss >> kata){
        s.push(kata);
    }

    cout << "Kalimat Kebalik: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main(){

    string kalimat;

    cout << "\nMasukan tiga Kalimat (contoh : aku suka kamu): " ;
    getline(cin, kalimat);
    kalimatMundur(kalimat);

    return 0 ;
}