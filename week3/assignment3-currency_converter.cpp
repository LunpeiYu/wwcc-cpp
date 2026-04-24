#include <iostream>
#include <iomanip>
using namespace std;

// Staic Variable, keeps track of how many conversions performed
static int count = 0;

// Function Prototypes
// Founctions convert USD to different currencies
double dollarToEuro(double amount);
double dollarToPound(double amount);
double dollarToYen(double amount);

// Returns the number of conversions
int getConversionCount();

// Main Function
int main() {
    double amount;
    int choice;
    char anotherConversion = 'y';

    cout << fixed << setprecision(2);

    while (anotherConversion == 'y' || anotherConversion == 'Y') {
        // Display menu
        cout << "\nCURRENCY CONVERTER\n";
        cout << "------------------" << endl;
        cout << "1. Convert USD to Euro (EUR)" << endl;
        cout << "2. Convert USD to British Pound (GBP)" << endl;
        cout << "3. Convert USD to Japanese Yen (JPY)" << endl;
        cout << "4. Exit" << endl;

        cout << "\nEnter your choice (1-4): ";
        cin >> choice;

        if (choice == 4) {
            break;
        }

        cout << "Enter amount in USD: ";
        cin >> amount;

        double convertedResult;
        
        // Conversion based on choice
        switch (choice){
            case 1:
                convertedResult = dollarToEuro(amount);
                cout << amount << " USD" << " = " << convertedResult << " EUR" << endl;
                break;
            
            case 2:
                convertedResult = dollarToPound(amount);
                cout << amount << " USD" << " = " << convertedResult << " GBP" << endl;
                break;

            case 3:
                convertedResult = dollarToYen(amount);
                cout << amount << " USD" << " = " << convertedResult << " JPY" << endl;
                break;

            default:
                cout << "Invalid choice, try again!" << endl;
                continue;
        }

        // Total conversions
        cout << "\nNumber of conversions performed: " << count << endl;

        // Check if continue
        while (true) {
            cout << "\nWould you like to perform another conversion? (y/n): ";
            cin >> anotherConversion;

            if (anotherConversion == 'y' || anotherConversion == 'Y' || anotherConversion == 'n' || anotherConversion == 'N') {
                break;
            }
            cout << "Invalid! Please enter y or n." << endl;
        }
        if (anotherConversion == 'n' || anotherConversion == 'N') {
            cout << "\nThank you for using the Currency Converter!";
            break;
        }
    }
    return 0;    
}

// Function Definitions
// Convert USD to Euro
double dollarToEuro(double amount) {   
    count++;
    return amount * 0.85;
}

// Convert USD to British Pound
double dollarToPound(double amount) {
    count++;
    return amount * 0.74;
}

// Convert USD to Japanese Yen
double dollarToYen(double amount) {
    count++;
    return amount * 110.33;
}

// Return total number of conversions
int getConversionCount() {
    return count;
}


    








