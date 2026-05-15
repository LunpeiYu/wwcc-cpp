#include "Book.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor: Initialize a book object 
Book::Book(string t, int py, string i, Author a) : title(t), publicationYear(py), isbn(i), author(a) {}

// Return book title
string Book::getTitle() const {
    return title;
}

// Return publication year
int Book::getPublicationYear() const {
    return publicationYear;
}

// Return isbn
string Book::getIsbn() const {
    return isbn;
}

// Return author object
Author Book::getAuthor() const {
    return author;
}

// Set publication year
void Book::setPublicationYear(int py) {
        if (py > 0) {
            publicationYear = py;
        }
}

// Display full book information
void Book::display() const {
    cout << "\"" << title << "\" (" << publicationYear << ")" << endl;
    cout << "   Author: ";
    author.display();
    cout << "   ISBN: " << isbn << endl;
    
}