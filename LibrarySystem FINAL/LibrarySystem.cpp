#include "LibrarySystem.h"
#include <iostream>
#include <fstream>
using namespace std;

//Book
/******************************************** */
Book::Book() : bookID(0), title(""), author(""), price(0.0f) {}

Book::Book(int id, const string& t, const string& a, float p)
    : bookID(id), title(t), author(a), price(p) {}

Book::~Book() {}

void Book::inputBook() {
    cout << "Enter Book ID: ";
    cin >> bookID;
    cin.ignore();
    cout << "Enter Title: ";
    getline(cin, title);
    cout << "Enter Author: ";
    getline(cin, author);
    cout << "Enter Price: ";
    cin >> price;
}

void Book::displayBook() const {
    cout << "ID: " << bookID << ", Title: " << title << ", Author: " << author << ", Price: $" << price << endl;
}

int Book::getBookID() const { return bookID; }
string Book::getBookTitle() const { return title; }
float Book::getPrice() const { return price; }

//Borrower 
/************************************************ */
Borrower::Borrower() : borrowerID(0), name(""), email("") {}

Borrower::Borrower(int id, const string& n, const string& e)
    : borrowerID(id), name(n), email(e) {}

Borrower::~Borrower() {}

void Borrower::inputBorrower() {
    cout << "Enter Borrower ID: ";
    cin >> borrowerID;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Email: ";
    getline(cin, email);
}

void Borrower::displayBorrower() const {
    cout << "ID: " << borrowerID << ", Name: " << name << ", Email: " << email << endl;
}

int Borrower::getBorrowerID() const { return borrowerID; }
string Borrower::getBorrowerName() const { return name; }

//Transaction
/******************************************* */
Transaction::Transaction(int id, const Book& b, const Borrower& br, const string& d)
    : transactionID(id), book(b), borrower(br), date(d) {}

Transaction::~Transaction() {}

void Transaction::displayTransaction() const {
    cout << "Transaction ID: " << transactionID
         << ", Book: " << book.getBookTitle()
         << ", Borrower: " << borrower.getBorrowerName()
         << ", Date: " << date << endl;
}

int Transaction::getTransactionID() const { return transactionID; }
string Transaction::getTransactionDate() const { return date; }

string Transaction::getTransactionInfo() const {
    return to_string(transactionID) + " " +
           to_string(book.getBookID()) + " " +
           to_string(borrower.getBorrowerID()) + " " + date;
}

//Library
/******************************************t */
Library::Library() {
    bookCapacity = 10;
    borrowerCapacity = 10;
    transactionCapacity = 10;
    bookCount = borrowerCount = transactionCount = 0;

    books = new Book*[bookCapacity];
    borrowers = new Borrower*[borrowerCapacity];
    transactions = new Transaction*[transactionCapacity];
}

Library::~Library() {
    for (int i = 0; i < bookCount; ++i) delete books[i];
    for (int i = 0; i < borrowerCount; ++i) delete borrowers[i];
    for (int i = 0; i < transactionCount; ++i) delete transactions[i];

    delete[] books;
    delete[] borrowers;
    delete[] transactions;
}

void Library::resizeBooks() {
    bookCapacity *= 2;
    Book** newArr = new Book*[bookCapacity];
    for (int i = 0; i < bookCount; ++i)
        newArr[i] = books[i];
    delete[] books;
    books = newArr;
}

void Library::resizeBorrowers() {
    borrowerCapacity *= 2;
    Borrower** newArr = new Borrower*[borrowerCapacity];
    for (int i = 0; i < borrowerCount; ++i)
        newArr[i] = borrowers[i];
    delete[] borrowers;
    borrowers = newArr;
}

void Library::resizeTransactions() {
    transactionCapacity *= 2;
    Transaction** newArr = new Transaction*[transactionCapacity];
    for (int i = 0; i < transactionCount; ++i)
        newArr[i] = transactions[i];
    delete[] transactions;
    transactions = newArr;
}

void Library::addBook(Book* book) {
    if (bookCount >= bookCapacity)
        resizeBooks();
    books[bookCount++] = book;
}

void Library::addBorrower(Borrower* borrower) {
    if (borrowerCount >= borrowerCapacity)
        resizeBorrowers();
    borrowers[borrowerCount++] = borrower;
}

void Library::recordTransaction(Transaction* transaction) {
    if (transactionCount >= transactionCapacity)
        resizeTransactions();
    transactions[transactionCount++] = transaction;
}

Book* Library::searchBookByTitle(const string& title) const {
    for (int i = 0; i < bookCount; ++i)
        if (books[i]->getBookTitle() == title)
            return books[i];
    return nullptr;
}

Book* Library::searchBookByID(int id) const {
    for (int i = 0; i < bookCount; ++i)
        if (books[i]->getBookID() == id)
            return books[i];
    return nullptr;
}

Borrower* Library::searchBorrowerByName(const string& name) const {
    for (int i = 0; i < borrowerCount; ++i)
        if (borrowers[i]->getBorrowerName() == name)
            return borrowers[i];
    return nullptr;
}

void Library::displayAllBooks() const {
    cout << "\n--- Books ---\n";
    for (int i = 0; i < bookCount; ++i)
        books[i]->displayBook();
}

void Library::displayAllBorrowers() const {
    cout << "\n--- Borrowers ---\n";
    for (int i = 0; i < borrowerCount; ++i)
        borrowers[i]->displayBorrower();
}

void Library::displayAllTransactions() const {
    cout << "\n--- Transactions ---\n";
    for (int i = 0; i < transactionCount; ++i)
        transactions[i]->displayTransaction();
}

Book** Library::getBooks() const { return books; }
Borrower** Library::getBorrowers() const { return borrowers; }
Transaction** Library::getTransactions() const { return transactions; }

int Library::getBookCount() const { return bookCount; }
int Library::getBorrowerCount() const { return borrowerCount; }
int Library::getTransactionCount() const { return transactionCount; }

//DataHandler
//********************************************** */
DataHandler::DataHandler(const string& bFile, const string& brFile, const string& tFile)
    : bookFile(bFile), borrowerFile(brFile), transactionFile(tFile) {}

bool DataHandler::saveBooks(Book** books, int count) const {
    ofstream out(bookFile);
    if (!out) return false;
    for (int i = 0; i < count; ++i)
        out << books[i]->getBookID() << "," << books[i]->getBookTitle() << "," << books[i]->getPrice() << endl;
    return true;
}

bool DataHandler::loadBooks(Book**& books, int& count) {
    ifstream in(bookFile);
    if (!in) return false;

    string line;
    count = 0;
    while (getline(in, line)) {
        int id;
        string title;
        float price;

        size_t pos1 = line.find(",");
        size_t pos2 = line.rfind(",");

        id = stoi(line.substr(0, pos1));
        title = line.substr(pos1 + 1, pos2 - pos1 - 1);
        price = stof(line.substr(pos2 + 1));

        books[count++] = new Book(id, title, "Unknown", price); //placeholder
    }
    return true;
}

bool DataHandler::saveBorrowers(Borrower** borrowers, int count) const {
    ofstream out(borrowerFile);
    if (!out) return false;
    for (int i = 0; i < count; ++i)
        out << borrowers[i]->getBorrowerID() << "," << borrowers[i]->getBorrowerName() << endl;
    return true;
}

bool DataHandler::loadBorrowers(Borrower**& borrowers, int& count) {
    ifstream in(borrowerFile);
    if (!in) return false;

    string line;
    count = 0;
    while (getline(in, line)) {
        int id;
        string name;

        size_t pos = line.find(",");
        id = stoi(line.substr(0, pos));
        name = line.substr(pos + 1);

        borrowers[count++] = new Borrower(id, name, "unknown@example.com");  //placeholder
    }
    return true;
}

bool DataHandler::saveTransactions(Transaction** transactions, int count) const {
    ofstream out(transactionFile);
    if (!out) return false;
    for (int i = 0; i < count; ++i)
        out << transactions[i]->getTransactionInfo() << endl;
    return true;
}

bool DataHandler::loadTransactions(Transaction**& transactions, int& count,
                                   Book** books, int bookCount,
                                   Borrower** borrowers, int borrowerCount) const {
    ifstream in(transactionFile);
    if (!in) return false;

    string line;
    count = 0;
    while (getline(in, line)) {
        int tid, bid, brid;
        string date;
        sscanf(line.c_str(), "%d %d %d %s", &tid, &bid, &brid, &date[0]);

        Book* b = nullptr;
        Borrower* br = nullptr;

        for (int i = 0; i < bookCount; ++i)
            if (books[i]->getBookID() == bid)
                b = books[i];

        for (int i = 0; i < borrowerCount; ++i)
            if (borrowers[i]->getBorrowerID() == brid)
                br = borrowers[i];

        if (b && br)
            transactions[count++] = new Transaction(tid, *b, *br, date);
    }

    return true;
}
