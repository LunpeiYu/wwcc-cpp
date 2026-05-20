#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// ========================= FUNCTION PROTOTYPES ========================
void variableValuesAndAddresses(int& age, double& gpa, char& grade);
void referenceDemonstration(int& age);
void pointerDemonstration(int& age);
void swapFunction(int& x, int& y);
void arrayPointRelationship(int arr[]);
int findMaxValue(int* arr, int size);
void writeNote(ofstream& file, const string& note);
void displayNote(ifstream& file);

// ========================= MAIN FUNCTION ==============================
int main() {

    // Part 1 Demonstrations
    cout << "\n===== PART 1: MEMORY AND ADDRESSING =====\n" << endl;

    // Variables
    int age = 25;
    double gpa = 3.75;
    char grade = 'A';

    int x = 10;
    int y = 20;

    int arr[5] = {10, 30, 50, 60, 100};

    variableValuesAndAddresses(age, gpa, grade);
    referenceDemonstration(age);
    pointerDemonstration(age);
    swapFunction(x, y);
    arrayPointRelationship(arr);

    int max = findMaxValue(arr, 5);
    cout << "  Maximum value (via pointer): " << max << endl;

    // Part 2 File I/O
    cout << "\n========== PART 2: FILE I/O ==========\n" << endl;

    // Write notes to file
    ofstream outFile("notes.txt", ios::app);

    if (!outFile) {

        cerr << "Error: cannot open file for writing!" << endl;
        return 1; 
    }

    string note;

    for (int i = 0; i < 3; i++) {
        cout << "Enter note " << i + 1 << ": ";
        getline(cin, note);

        writeNote(outFile, note);
    }

    cout << "\nNotes written to notes.txt successfully." << endl;

    outFile.close();

    // Display notes from file
    ifstream inFile("notes.txt");

    if(!inFile) {

        cerr << "Error: cannot open file for reading." << endl;
        return 1;
    }

    displayNote(inFile);
    
    inFile.close();

    return 0;
}

// ========================= FUNCTION DEFINITIONS ======================== 
// Display values and memory addresses
void variableValuesAndAddresses(int& age, double& gpa, char& grade) {
    
    cout << "Variable values and addresses:" << endl;
    
    cout << left << setw(10) << "  int" << setw(10) << "age" << "= " << setw(5) << age  << setw(15) << "at address" << setw(10) << &age << endl;
    cout << left << setw(10) << "  double" << setw(10) << "gpa" << "= " << setw(5) << gpa << setw(15) << "at address" << setw(10) << &gpa << endl;
    cout << left << setw(10) << "  char" << setw(10) << "grade" << "= " << setw(5) << ("'" + string(1, grade) + "'") << setw(15) << "at address" << setw(10) << static_cast<void*>(&grade) << endl;
}

// Demonstrate reference behavior
void referenceDemonstration(int& age) {

    int& refAge = age;

    cout << "\nReference demonostration:" << endl;
    cout << "  Before: age = " << age << endl;

    refAge = 26;

    cout << "  After modifying through reference: age = " << age << endl;
}

// Demonstrate pointer usage
void pointerDemonstration(int& age) {
   
    int* ptr = nullptr;
    ptr = &age;

    cout << "\nPointer demostration:" << endl;
    
    
    if (ptr !=nullptr) {

        cout << "  Pointer stores address: " << ptr << endl;
        cout << "  Value at that address: " << *ptr << endl;

        *ptr = 100;
    
        cout << "  After modifying through pointer: " << age << endl;
    }    
}

// Swap using references
void swapFunction(int& x, int& y) {

    cout << "\nSwap function (by reference):" << endl;
    cout << "  Before: " << "x = " << x <<", " << "y = " << y << endl;

    int temp = x;
    x = y;
    y = temp;

    cout << "  After swap: " << "x = " << x << ", " << "y = " << y << endl;
}

// Array-pointer relationship
void arrayPointRelationship(int arr[]) {

    cout << "\nArray-pointer relationship:" << endl; 
    
    for (int i = 0; i < 2; i++) {
        cout << "  arr[" << i << "] = " << *(arr + i) << "   *(arr + " << i << ") = " << *(arr + i) << endl;
    }
}

// Find max using pointer traversal
int findMaxValue(int* arr, int size) {

    int max = *arr;

    for (int i = 0; i < size; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }   
    }
    return max;
}

// Write notes to file
void writeNote(ofstream& file, const string& note) {
    file << note << endl;
}

// Display notes from file
void displayNote(ifstream& file) {

    string line;

    cout << "\nReading notes back from file:" << endl;

    while(getline(file, line)) {
        cout << "  "<< line << endl;
    }
}
