#include <iostream>

using namespace std;

int main() {
    char input1[6];
    char input2[3];
    int a, b;
    
    cout << "Input 1 : ";
    for (int a = 0; a < sizeof(input1); a++) {
        cin >> input1[a];
    }

    cout << "Input 2 : ";
    for (int b = 0; b < sizeof(input2); b++) {
        cin >> input2[b];
    }


    for (int a = 0; a < sizeof(input2); a++) {
        for (int b = 0; b < sizeof(input1); b++) {
            if (input2[a] == input1[b]) {
                cout << input2[a]<< "[" << b << "]";

                if (a < 2) {
                    cout << " + ";
                }
            }
        }
    }

    return 0;
}
