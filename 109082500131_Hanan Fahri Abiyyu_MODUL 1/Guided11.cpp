#include <iostream>
using namespace std;

float ctof(float celcius);

int main() {
    float celcius, fahrenheit;
    cout <<"nilai Celcius? ";
    cin >> celcius;
    fahrenheit = ctof(celcius);
    cout<<celcius<<" Celcius adalah "<<fahrenheit<<" Fahrenheit"<<endl;
    return 0;
    }

    float ctof(float celcius){
    return (celcius * 1.8) + 32;
}