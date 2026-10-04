#include <iostream>
using namespace std;

const int MAX = 3;

void penjumlahan (int X[MAX][MAX], int Y[MAX][MAX], int Z[MAX][MAX]) {
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++) {
            Z[i][j] = X[i][j] + Y[i][j];
        }
    }
}

void pengurangan (int X[MAX][MAX], int Y[MAX][MAX], int Z[MAX][MAX]) {
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++) {
            Z[i][j] = X[i][j] - Y[i][j];
        }
    }
}

void perkalian (int X[MAX][MAX], int Y[MAX][MAX], int Z[MAX][MAX]) {
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++) {
            Z[i][j] = 0;
            for (int k = 0; k < MAX; k++) {
                Z[i][j] += X[i][k] * Y[k][j];
            }
        }
    }
}

void Input(int in[MAX][MAX], char alphabet) {

    cout << "Masukkan matriks " << alphabet << endl;
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            cout << alphabet << "[" << i << "]" << "[" << j << "]" << " = ";
            cin >> in[i][j];
        }
    }
}


void tampilkanOutput(int out[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << out[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int X[MAX][MAX], Y[MAX][MAX], Z[MAX][MAX];
    int menu;
    
    do {
    cout << endl;
    cout << "--- Menu Program Array ---" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "3. Perkalian" << endl;
    cout << "0. Exit\n" << endl;
    

    cout << "Pilih: ";
    cin >> menu;

    
        switch (menu) {
            
            case 1:
                cout << "Penjumlahan dipilih!" << endl;
                Input(X, 'X');
                cout << endl;
                Input(Y, 'Y');
                penjumlahan(X, Y, Z);
                cout << "Hasil penjumlahan X dan Y = " << endl;
                tampilkanOutput(Z);
                break;

            case 2:
                cout << "Pengurangan dipilih!" << endl;
                Input(X, 'X');
                cout << endl;
                Input(Y, 'Y');
                pengurangan(X, Y, Z);
                cout << "Hasil pengurangan X dan Y = " << endl;
                tampilkanOutput(Z);
                break;

            case 3:
                cout << "Perkalian dipilih!" << endl;
                Input(X, 'X');
                cout << endl;
                Input(Y, 'Y');
                perkalian(X, Y, Z);
                cout << "Hasil perkalian X dan Y = " << endl;
                tampilkanOutput(Z);
                break;

            case 0:
                cout << "Terima Kasih Telah Menggunakan Aplikasi Kami" << endl;
                break;

        default:
            cout << "Input menu tidak valid! Silakan coba lagi!" << endl;
            break;
        }

    } while(menu != 0);

    return 0;    
}