#include <iostream>
#include <string>
using namespace std;

int main() {
   int bilangan;
   string sKecil[] = {"nol","satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"};
   string sKapital[] = {"", "Satu", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan"};
   
   cout << "Masukkan angka (0 - 100)" << endl;
   cin >> bilangan;

   
   
   if (bilangan >= 0 && bilangan <= 11) {
      cout << sKecil[bilangan];
   }else if (bilangan >= 12 && bilangan <= 19) {
      cout << sKecil[bilangan % 10] << " belas";
   }else if (bilangan >= 20 && bilangan <= 99) {
      cout << sKecil[bilangan / 10] << " puluh";
      if (bilangan % 10 != 0) {
         cout << " " << sKapital[bilangan%10];
      }
   }else if (bilangan == 100) {
      cout << "seratus\n";
   }

   if (bilangan < 0 || bilangan > 100) {
      cout << "Input tidak valid, masukkan angka 0 hingga 100" << endl;
      return 0;
   }

   return 0;

}