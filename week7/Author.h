#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
using namespace std;

// Author class stores basic information 
class Author {
private:
    string name;
    int birthYear;

public:
    // Constructor: initialize author name and birth year
    Author(string n, int by);
    
    // Get author's name and birthyear
    string getName() const;
    int getBirthYear() const;

    // Display author information
    void display() const;    
};

#endif
