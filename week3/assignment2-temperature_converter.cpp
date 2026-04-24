#include <iostream>
#include <iomanip>
using namespace std;

void convertTemperature(double temperature, char unit, double &c, double &f, double &k) {
    switch (unit) {
        case 'C':
        case 'c':
            c = temperature;
            f = (c * 9.0/5) + 32;
            k = c +273.15;
            break;
        
        case 'F':
        case 'f':
            f = temperature;
            c = (f - 32) * 5.0/9;
            k = (f - 32) * 5.0/9 + 273.15;
            break;
        
        case 'K':
        case 'k':
            k = temperature;
            c = k - 273.15;
            f = (k - 273.15) * 9.0/5 +32;
            break;
    
        default:
            cout << "Invalid input, try again!" << endl;
            c = f = k = 0;       
    }
}

int main() {
    double temperature;
    char unit;
    double c, f, k;

    cout << "Enter a temperature value: ";
    cin >> temperature;
    
    cout << "Enter the unit (C for Celsius, F for Fahrenheit, K for Kelvin): ";
    cin >> unit;

    convertTemperature(temperature, unit, c, f, k);

    cout << fixed << setprecision(2);

    cout <<"\nTemperature Conversions:" << endl;
    cout << "Celsius: " << c << "C" << endl;
    cout << "Fahrenheit: " << f << "F" << endl;
    cout << "Kelvin: " << k << "K" << endl;

    return 0;
}