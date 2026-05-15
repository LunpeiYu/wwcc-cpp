#include <iostream> 
#include <string>
#include <limits>
#include "Author.h"
#include "Book.h"
#include "Library.h"
using namespace std;

// Main Function
int main () {

    // Create a Library object with name
    Library myLibrary("WWCC Library");

    int choice;

    do {
        // Display menu
        cout << "\nLIBRARY MANAGEMENT SYSTEM" << endl;
        cout << "-------------------------" << endl;
        cout << "Library: WWCC Library" << endl;
        cout << "\n1. Add Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Search by Author" << endl;
        cout << "4. Search by Title" << endl;
        cout << "5. Show Stats" << endl;
        cout << "6. Exit" << endl;

        cout << "\nEnter choice: ";
        cin >> choice;

        if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid input! Please enter a number (1-6)." << endl;
        continue;
        }

        switch(choice) {

            case 1: {
                // Add sample books to the library
                Author a1("F. Scott Fitzgerald", 1896);
                Book b1("The Great Gatsby", 1925, "9780743273565", a1);
                myLibrary.addBook(b1);

                Author a2("George Orwell", 1903);
                Book b2("1984", 1949, "9780451524935", a2);
                myLibrary.addBook(b2);
                
                Author a3("George Orwell", 1903);
                Book b3("Animal Farm", 1945, "9780451526342", a3);
                myLibrary.addBook(b3);
                
                cout << "\nBooks added Successfully!" << endl;
                break;                
            }

            case 2: {
                // Display all books in catalog
                myLibrary.displayAllBooks();
                break;
            }

            case 3: {
                // Search books by author name
                string name;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nSearch by author: ";
                getline(cin, name);

                while(!name.empty() && name.back() == ' ') {
                    name.pop_back();
                }
                myLibrary.searchByAuthor(name);
                break;
            }

            case 4: {
                // Search books by title keyword
                string keyword;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nSearch by title: ";
                getline(cin, keyword);

                while(!keyword.empty() && keyword.back() == ' ') {
                    keyword.pop_back();
                }
                myLibrary.searchByTitle(keyword);
                break;
            }

            case 5: {
                // Display total number of books
                myLibrary.displayStats();
                break;
            }

            case 6: {
                // Exit program
                cout << "Goodbye!" << endl;
                break;
            }

            default:
                // Handle invalid input
                cout << "Invalid choice! Please enter(1-6)." << endl;
                break;
        }
    } while(choice != 6);

    return 0;
}