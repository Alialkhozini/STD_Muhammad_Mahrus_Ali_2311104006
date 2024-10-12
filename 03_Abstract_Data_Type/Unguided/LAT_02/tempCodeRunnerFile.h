#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>

using namespace std;

struct pelajaran
{
    string namaMatkul;
    string kodeMatkul;
};

pelajaran create_pelajaran(string mataKuliah, string kodeMataKuliah);

void tampil_pelajaran(const pelajaran& pel);

#endif