#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isiPalindrom(string kalimat) {
    stack<char> s;
    string cleanedKalimat = "";

    for (char c : kalimat) {
        if (isalnum(c)){
            cleanedKalimat += tolower(c);
        }
    }

    for (char c : kalimat) {
        s.push(c);
    }

    for (char c : kalimat){
        if (c != s.top()) {
            return false;
        }
        s.pop();
    }
    return true;
}

int main(){
    string kalimat;

    cout << "Masukan Kalimat: " ;
    getline(cin, kalimat);

    if(isiPalindrom(kalimat)){
        cout << "kalimat tersebut palindrom\n" << endl;
    } else {
        cout << "kalimat tersebut bukan palindrom\n" << endl;
    }

    return 0;
}