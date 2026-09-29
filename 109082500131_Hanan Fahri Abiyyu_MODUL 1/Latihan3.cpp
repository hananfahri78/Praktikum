#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "input: ";
    cin >> a;
    
    cout << "output: " << endl;

    for (int i = a; i >= 0; i--){
       for (int g = 0; g < a - i; g++) {
            cout << "  ";
       }

       for (int g = i; g >= 1; g--) {
         cout << g << " ";
       }

       cout << "*";
       
       for (int g = 1; g <= i; g++){
        cout << " " << g;
       }
       cout << endl;
    }

    return 0;
}