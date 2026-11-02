#include "Doublylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    infotype x;
    address P;
    CreateList(L);
    for (int i = 0; i < 4; i++){
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;
        
        if (findElm(L, x) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        }else{
            P = alokasi(x);
            insertLast(L, P);
            cout << endl;
        }
    }

    printInfo(L);
    cout << endl;

    cout << "Masukkan Nomor Polisi yang dicari  : ";
    cin >> x.nopol;

    address found = findElm(L, x);
    if (found != Nil) {
        cout << "no polisi  : " << found->info.nopol << endl;
        cout << "warna      : " << found->info.warna << endl;
        cout << "tahun      : " << found->info.thnBuat << endl;
    }else{
        cout << "Nomor Polisi " << x.nopol << " Tidak ditemukan" << endl;
    }

    cout << "Masukkan nomor polisi yang akan dihapus  : ";
    cin >> x.nopol;
    address Delete = findElm(L, x);
    if (Delete == Nil) {
        cout << "Data tidak ditemukan!" << endl;
    }else{
        address X;
        if (Delete == L.First) {
            deleteFirst(L, X);
        }else if (Delete == L.Last){
            deleteLast(L, X);
        }else{
            deleterAfter(Delete->prev, X);
        }
        dealokasi(X);
        cout << "Data dengan nomor polisi " << x.nopol << " berhasil dihapus" << endl;
        
    }

    printInfo(L);
    return 0;
}