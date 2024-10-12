#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string mataKuliah = "Struktur Data";
    string kodeMataKuliah = "STD";

    pelajaran pel = create_pelajaran(mataKuliah, kodeMataKuliah);

    tampil_pelajaran(pel);

    return 0;
}