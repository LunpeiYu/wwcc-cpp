#include "Author.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor: Initialize an author object with name and birthyear
Author::Author(string n, int by) : name(n), birthYear(by) {}

// Return the name of the author
string Author::getName() const {
    return name;
}

// Return the birthyear of the author
int Author::getBirthYear() const {
    return birthYear;
}

// Display author information in format
void Author::display() const {
    cout << name << " (born " << birthYear << ")" << endl;
}