#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

// Overloaded Function Prototypes
string format(int num);
string format(double num);
string format(double num, int precision);
string format(string str);

// Main Function
int main() {
    cout << "Integer formatting:" << endl;
    cout << "Original: 1111111" << endl;
    cout << "Formatted: " << format(1111111) << endl << endl;

    cout << "Double formatting (default 2 decimal places):" <<endl;
    cout << "Original: 22.2222" << endl;
    cout << "Formatted: " << format(22.2222) << endl << endl;

    cout << "Double formatting (custom decimal places):" << endl;
    cout << "Original: 22.2222 with precision 3" << endl;
    cout << "Formatted: " << format(22.2222, 3) << endl << endl;

    cout << "String formatting:" << endl;
    cout << "Original: hello world of c++ programming" << endl;
    cout << "Formatted: " << format("hello world of c++ programming") << endl;
    
    return 0;
}

// Function Definitions
// Integer version: format number with commas
// Example: 1111111 -> 1,111,111
string format(int num) {
    bool isNegative = (num < 0);
    if (isNegative) num = -num; // Change to positive

    string str = to_string(num);

    // If number is (<= 3 digits), no cammas needed
    if (str.length() <= 3) {
        if (isNegative) return "-" +str;
        return str;
    }

    string result = "";
    int count = 0;
    // Process from right to left and add commas every 3 digits
    for (int i = str.length() - 1; i>=0; i--) {
        result = str[i] + result;
        count++;

        if (count == 3 && i != 0) {
            result = "," + result;
            count = 0;
        }
    }
    // Restore negative sign if needed
    if (isNegative) {
        result = "-" + result;
    }
    return result;
}

// Double version: format to 2 decimal places
// Example: 22.2222 -> 22.22
string format(double num) {
    stringstream snum;
    
    // fixed setprecision controls to deimal formatting
    snum << fixed << setprecision(2) << num;
    return snum.str();
}

// Double version: custom precision
// Example : 22.2222 -> 22.222
string format(double num, int precision) {
    stringstream scnum;

    // precision can be defined decimal places
    scnum << fixed << setprecision(precision) << num;
    return scnum.str();
}

// String version: capitalize first letter of each word
// Example: "hello word" -> "Hello World"
string format(string str) {
    
    //Edge case: empty string
    if (str.length() == 0) return str;

    bool newWord = true;

    // Loop through each character
    for (int i = 0; i < str.length(); i++) {

        // If start of new word and lowercase letter, capitalize it
        if (newWord && str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] -32;
            newWord = false;
        }

        // Space means next character starts a new world
        if (str[i] == ' ') {
            newWord = true;
        }
    }
    return str;
}

