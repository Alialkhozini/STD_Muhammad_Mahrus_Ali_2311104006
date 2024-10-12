#include "pelajaran.h"
#include <iostream>

pelajaran create_pelajaran(string mataKuliah, string kodeMataKuliah) {
    pelajaran pel;
    pel.namaMatkul = mataKuliah;
    pel.kodeMatkul = kodeMataKuliah;
    return pel;
}

void tampil_pelajaran(const pelajaran& pel) {
    cout << "Nama Mata Kuliah: " << pel.namaMatkul << endl;
    cout << "Kode Mata Kuliah: " << pel.kodeMatkul << endl;
}