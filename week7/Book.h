#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Author.h"
using namespace std;

// Book class represents a book in the library system. Uses composition by containing an Author object
class Book {
private:
    string title;
    int publicationYear;
    string isbn;
    Author author;

public:
    // Constructor initializes a book object 
    Book(string t, int py, string i, Author a);

    // Return book title, publication year, ISBN number, and Author object
    string getTitle() const;
    int getPublicationYear() const;
    string getIsbn() const;
    Author getAuthor() const;

    // Set publication year with validation
    void setPublicationYear(int py);

    // Display full book information
    void display() const;

};

#endif
