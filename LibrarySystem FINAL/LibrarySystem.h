/*Header file for library management*/

#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H

#include <string>

using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;
    float price;

public:
    Book();
    Book(int id, const string& title, const string& author, float price);
    ~Book();

    void inputBook();
    void displayBook() const;

    int getBookID() const;
    string getBookTitle() const;
    float getPrice() const;
};

class Borrower {
private:
    int borrowerID;
    string name;
    string email;

public:
    Borrower();
    Borrower(int id, const string& name, const string& email);
    ~Borrower();

    void inputBorrower();
    void displayBorrower() const;

    int getBorrowerID() const;
    string getBorrowerName() const;
};

class Transaction {
private:
    int transactionID;
    const Book& book;
    const Borrower& borrower;
    string date;

public:
    Transaction(int id, const Book& book, const Borrower& borrower, const string& date);
    ~Transaction();

    void displayTransaction() const;
    int getTransactionID() const;
    string getTransactionDate() const;
    string getTransactionInfo() const;
};

class Library {
private:
    Book** books;
    Borrower** borrowers;
    Transaction** transactions;

    int bookCount, borrowerCount, transactionCount;
    int bookCapacity, borrowerCapacity, transactionCapacity;

    void resizeBooks();
    void resizeBorrowers();
    void resizeTransactions();

public:
    Library();
    ~Library();

    void addBook(Book* book);
    void addBorrower(Borrower* borrower);
    void recordTransaction(Transaction* transaction);

    Book* searchBookByTitle(const string& title) const;
    Book* searchBookByID(int id) const;
    Borrower* searchBorrowerByName(const string& name) const;

    void displayAllBooks() const;
    void displayAllBorrowers() const;
    void displayAllTransactions() const;

    Book** getBooks() const;
    Borrower** getBorrowers() const;
    Transaction** getTransactions() const;

    int getBookCount() const;
    int getBorrowerCount() const;
    int getTransactionCount() const;
};

class DataHandler {
private:
    string bookFile;
    string borrowerFile;
    string transactionFile;

public:
    DataHandler(const string& bFile = "books.txt",
                const string& brFile = "borrowers.txt",
                const string& tFile = "transactions.txt");

    bool saveBooks(Book** books, int count) const;
    bool loadBooks(Book**& books, int& count);

    bool saveBorrowers(Borrower** borrowers, int count) const;
    bool loadBorrowers(Borrower**& borrowers, int& count);

    bool saveTransactions(Transaction** transactions, int count) const;
    bool loadTransactions(Transaction**& transactions, int& count, Book** books, int bookCount, Borrower** borrowers, int borrowerCount) const;
};

#endif
