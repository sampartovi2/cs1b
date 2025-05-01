#include "LibrarySystem.h"
#include <iostream>
using namespace std;


//Menu fucntionality
int main() {
    Library library;
    DataHandler dataHandler;

    int choice;
    do {
        cout << "\n======  Menu ======\n";
        cout << "1. Add a book\n";
        cout << "2. Add a borrower\n";
        cout << "3. Record a transaction\n";
        cout << "4. Search book by title\n";
        cout << "5. Search borrower by name\n";
        cout << "6. Display all books\n";
        cout << "7. Display all borrowers\n";
        cout << "8. Display all transactions\n";
        cout << "9. Save data\n";
        cout << "10. Load data\n";
        cout << "0. Exit\n";
        cout << "Enter a choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {                   //add book
                Book* b = new Book();
                b->inputBook();
                library.addBook(b);
                break;
            }
            case 2: {                   //add borrower
                Borrower* br = new Borrower();
                br->inputBorrower();
                library.addBorrower(br);
                break;
            }
            case 3: {                   //record trans
                int tid;
                string date;
                cout << "Enter transaction ID: ";
                cin >> tid;
                cin.ignore();

                string bookTitle;
                cout << "Enter book title: ";
                getline(cin, bookTitle);
                Book* b = library.searchBookByTitle(bookTitle);
                if (!b) {
                    cout << "Book not found!\n";
                    break;
                }

                string borrowerName;
                cout << "Enter borrower name: ";
                getline(cin, borrowerName);
                Borrower* br = library.searchBorrowerByName(borrowerName);
                if (!br) {
                    cout << "Borrower not found!\n";
                    break;
                }

                cout << "Enter transaction date (e.g., 2025-04-20): ";
                getline(cin, date);

                Transaction* t = new Transaction(tid, *b, *br, date);
                library.recordTransaction(t);
                break;
            }
            case 4: {               //search title
                string title;
                cout << "Enter Book Title: ";
                getline(cin, title);
                Book* b = library.searchBookByTitle(title);
                if (b) b->displayBook();
                else cout << "Book not found.\n";
                break;
            }
            case 5: {               //search name
                string name;
                cout << "Enter Borrower Name: ";
                getline(cin, name);
                Borrower* br = library.searchBorrowerByName(name);
                if (br) br->displayBorrower();
                else cout << "Borrower not found.\n";
                break;
            }
            case 6:             //display books
                library.displayAllBooks();
                break;
            case 7:             //display borrowers
                library.displayAllBorrowers();
                break;
            case 8:             //display trans
                library.displayAllTransactions();
                break;
            case 9: {           //save data
                bool bSaved = dataHandler.saveBooks(library.getBooks(), library.getBookCount());
                bool brSaved = dataHandler.saveBorrowers(library.getBorrowers(), library.getBorrowerCount());
                bool tSaved = dataHandler.saveTransactions(library.getTransactions(), library.getTransactionCount());
                cout << (bSaved && brSaved && tSaved ? "Data saved successfully.\n" : "Failed to save data.\n");
                break;
            }
            case 10: {              //load data
                Book** books = new Book*[100];
                Borrower** borrowers = new Borrower*[100];
                Transaction** transactions = new Transaction*[100];
                int bCount = 0, brCount = 0, tCount = 0;

                bool bLoaded = dataHandler.loadBooks(books, bCount);
                for (int i = 0; i < bCount; ++i) library.addBook(books[i]);

                bool brLoaded = dataHandler.loadBorrowers(borrowers, brCount);
                for (int i = 0; i < brCount; ++i) library.addBorrower(borrowers[i]);

                bool tLoaded = dataHandler.loadTransactions(transactions, tCount, library.getBooks(), library.getBookCount(), library.getBorrowers(), library.getBorrowerCount());
                for (int i = 0; i < tCount; ++i) library.recordTransaction(transactions[i]);

                cout << (bLoaded && brLoaded && tLoaded ? "Data loaded successfully.\n" : "Failed to load data.\n");
                break;
            }
            case 0:     //exit
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }

    } while (choice != 0);  //display menu until exit

    return 0;
}
