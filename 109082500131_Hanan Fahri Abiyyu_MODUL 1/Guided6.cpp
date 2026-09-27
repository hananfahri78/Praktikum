#include <iostream>

using namespace std;

int main(){
    int kode_hari;
    puts("Menentukan hari kerja/libur\n");
    puts("1=Senin 3=Rabu 5=Jumat 7=Minggu ");
    puts("2=Selasa 4=Kamis 6=Sabtu ");
    
    cin>>kode_hari;
    switch(kode_hari) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            cout<<"Hari Kerja"<<endl;
            break;
        case 6:
        case 7:
            cout<<"Hari Libur"<<endl;
            break;
    default:
        cout<<"Kode masukan salah!!!"<<endl;
    }
    return 0;
}