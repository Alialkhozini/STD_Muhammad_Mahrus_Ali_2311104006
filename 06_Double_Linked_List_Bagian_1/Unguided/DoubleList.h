#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include <iostream>
#include <string>
using namespace std;

struct infotype {
  string nopol;
  string warna;
  int thnBuat;
};

struct ElmList;
typedef ElmList* address;

struct ElmList {
  infotype info;
  address next;
  address prev;
};

struct List {
  address First;
  address Last;
};

void CreateList(List &L) {
  L.First = nullptr;
  L.Last = nullptr;
}

address alokasi(infotype x) {
  address newElm = new ElmList;
  newElm->info = x;
  newElm->next = nullptr;
  newElm->prev = nullptr;
  return newElm;
}

void dealokasi(address &P) {
  delete P;
  P = nullptr;
}

bool isNopolExists(const List &L, const string &nopol) {
  address temp = L.First;
  while (temp != nullptr) {
    if (temp->info.nopol == nopol) {
      return true; 
    }
    temp = temp->next;
  }
  return false; 
}

address findElm(const List &L, const string &nopol) {
  address temp = L.First;
  while (temp != nullptr) {
    if (temp->info.nopol == nopol) {
      return temp; 
    }
    temp = temp->next;
  }
  return nullptr; 
}

void printSearchResult(const List &L, const string &nopol) {
  address found = findElm(L, nopol);
  if (found != nullptr) {
    cout << "\nNomor Polisi : " << found->info.nopol << endl;
    cout << "Warna : " << found->info.warna << endl;
    cout << "Tahun : " << found->info.thnBuat << endl;
  } else {
    cout << "Nomor polisi " << nopol << " tidak ditemukan." << endl;
  }
}

void deleteElm(List &L, const string &nopol) {
  address found = findElm(L, nopol);
  if (found != nullptr) {
    if (found == L.First) { 
      L.First = found->next;
      if (L.First != nullptr) {
        L.First->prev = nullptr;
      }
    } else if (found == L.Last) { 
      L.Last = found->prev;
      if (L.Last != nullptr) {
        L.Last->next = nullptr;
      }
    } else { 
      found->prev->next = found->next;
      found->next->prev = found->prev;
    }
    delete found;
    cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus." << endl;
  } else {
    cout << "Nomor polisi " << nopol << " tidak ditemukan." << endl;
  }
}

void printInfo(const List &L) {
  if (L.First == nullptr) {
    cout << "List kosong" << endl;
    return;
  }

  address temp = L.First;
  cout << "\nDATA LIST\n\n";
  while (temp != nullptr) {
    cout << "no polisi : " << temp->info.nopol << endl;
    cout << "warna : " << temp->info.warna << endl;
    cout << "tahun : " << temp->info.thnBuat << endl << endl;
    temp = temp->next;
  }
}

void insertLast(List &L, address P) {
  if (L.First == nullptr) { 
    L.First = P;
    L.Last = P;
  } else { 
    L.Last->next = P;
    P->prev = L.Last;
    L.Last = P;
  }
}

#endif