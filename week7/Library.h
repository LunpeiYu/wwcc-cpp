#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include <string>
using namespace std;

// Library class represents a clollection of books
class Library {
private:
    string name;
    vector<Book> books;

public:
    // Constructor initializes the library with a name
    Library(string n);
    
    // Adds a book to the library
    void addBook(const Book& book);

    // Display all books in the library
    void displayAllBooks() const;

    // Searches book by author name
    void searchByAuthor(string authorName) const;

    // Searches book by title keyword
    void searchByTitle(string keyword) const;

    // Displays the number of the books
    void displayStats() const;
   
};

#endif