#include <iostream>
#include <string>
#include <cctype>
#include "Library.h"
using namespace std;

// Constructor
Library::Library(string n) : name(n) {}

// Adds a Book object to the library collection
void Library::addBook(const Book& book) {
    books.push_back(book);
}

// Displays all books in the library catalog
void Library::displayAllBooks() const {

    if (books.empty()) {
        cout << "No books found in catalog." << endl;
        return;
    }
    cout << "\nCATALOG: " << endl;

    for(size_t i = 0; i < books.size(); i++) {
        cout << i + 1 << ". ";
        books[i].display();
        cout << endl;
    }

}

// Searches books by author name (partial match)
void Library::searchByAuthor(string authorName) const {
    if (books.empty()) {
        cout << "No books found in catalog." << endl;
        return;
    }

    for(size_t i = 0; i < authorName.size(); i++) {
        authorName[i] = tolower(authorName[i]);
    }
    bool found = false;

    for(size_t i = 0; i < books.size(); i++) {

        string name = books[i].getAuthor().getName();

        for (size_t j = 0; j < name.size(); j++) {
            name[j] = tolower(name[j]);
        }

        if(name.find(authorName) != string::npos) {

            if(!found) {
                cout << "Book by " << books[i].getAuthor().getName() << ":" << endl;
            }
            cout <<"  - \"" << books[i].getTitle() << "\" (" << books[i].getPublicationYear() << ")" << endl;
            
            found = true;
        }
    
    }
    if(!found) {
        cout << "No books found for this author." << endl;
    }
}

// Searches books by title keyword (partial match)
void Library::searchByTitle(string keyword) const {
    if (books.empty()) {
        cout << "No books found in catalog." << endl;
        return;
    }

    for(size_t i = 0; i < keyword.size(); i++) {
        keyword[i] = tolower(keyword[i]);
    }
    bool found = false;
    
    for(size_t i = 0; i < books.size(); i++) {

        string title = books[i].getTitle();

        for (size_t j = 0; j < title.size(); j++) {
            title[j] = tolower(title[j]);
        }

        if(title.find(keyword) != string::npos) {
            cout <<"  - \"" << books[i].getTitle() << "\" (" << books[i].getPublicationYear() << ") - " << books[i].getAuthor().getName() << endl;
            found = true;
        }
    
    }
    if(!found) {
        cout << "No books found with that keyword." << endl;
    }

}

// Display basic library statistics
void Library::displayStats() const {
    
    cout << "\nSTATS:" << endl;
    cout << "  Total books in catalog: " << books.size() << endl;

}
