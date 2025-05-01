#include <iostream>
#include <fstream>
using namespace std;


/******************************************************** */
class Book
{
private:
    int bookID;  //unique book identifier
    string title; //book title
    string author; //author of book
    float price;   //book price

public:
    Book() : bookID(0), title(""), author(""), price(0.0f) {} //default constructor
    Book(int id, const string &t, const string &a, float p) : bookID(id), title(t), author(a), price(p) {}  //parameterized constructor
    ~Book() {}  //destructor

    void inputBook()          //This function reads book details
    {
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

    void displayBook() const   //This function displays book details
    {
        cout << "ID: " << bookID << ", Title: " << title << ", Author: " << author << ", Price: $" << price << endl;
    }

    int getBookID() const { return bookID; }
    string getBookTitle() const { return title; }
    float getPrice() const { return price; }
};

/*********************************************************************** */
class Borrower
{
private:
    int borrowerID;  //unique borrower identifier
    string name;     //borrower name
    string email;    //borrower email

public:
    Borrower() : borrowerID(0), name(""), email("") {}  //default constructor
    Borrower(int id, const string &n, const string &e) : borrowerID(id), name(n), email(e) {}  //parameterized constructur
    ~Borrower() {}  //destructor

    void inputBorrower()  //function to read borrower details
    {
        cout << "Enter Borrower ID: ";
        cin >> borrowerID;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Email: ";
        getline(cin, email);
    }

    void displayBorrower() const  //function to display borrower details
    {
        cout << "ID: " << borrowerID << ", Name: " << name << ", Email: " << email << endl;
    }

    int getBorrowerID() const { return borrowerID; }
    string getBorrowerName() const { return name; }
};

/******************************************************** */

class Transaction
{
private:
    int transactionID;   //unique transaction identifier
    const Book &book;    //reference to Book object
    const Borrower &borrower;  //reference to Borrower object
    string date;

public:
    Transaction(int id, const Book &b, const Borrower &br, const string &d)  //paramterized constructor
        : transactionID(id), book(b), borrower(br), date(d) {}
    ~Transaction() {}   //destructor

    void displayTransaction() const  //displays transaction details
    {
        cout << "Transaction ID: " << transactionID
             << ", Book: " << book.getBookTitle()
             << ", Borrower: " << borrower.getBorrowerName()
             << ", Date: " << date << endl;
    }

    int getTransactionID() const { return transactionID; }
    string getTransactionDate() const { return date; }
    string getTransactionInfo() const
    {
        return to_string(transactionID) + " " +
               to_string(book.getBookID()) + " " +
               to_string(borrower.getBorrowerID()) + " " + date;     // return transaction id, book id and borrower id concatenated in a string to be saved by DataHandler
    }
};

/****************************************************************** */
class Library
{
private: 
    Book **books;   //dynamically allocated array of Book pointers
    Borrower **borrowers;  //dynamically allocated array of Borrower pointers
    Transaction **transactions;  //dynamically allocated array of Transaction  pointers
    int bookCount, borrowerCount, transactionCount;
    int bookCapacity, borrowerCapacity, transactionCapacity;

    void resizeBooks() 
    {
        bookCapacity *= 2;
        Book **newArr = new Book *[bookCapacity];
        for (int i = 0; i < bookCount; ++i)
            newArr[i] = books[i];
        delete[] books;
        books = newArr;
    }

    void resizeBorrowers()
    {
        borrowerCapacity *= 2;
        Borrower **newArr = new Borrower *[borrowerCapacity];
        for (int i = 0; i < borrowerCount; ++i)
            newArr[i] = borrowers[i];
        delete[] borrowers;
        borrowers = newArr;
    }

    void resizeTransactions()
    {
        transactionCapacity *= 2;
        Transaction **newArr = new Transaction *[transactionCapacity];
        for (int i = 0; i < transactionCount; ++i)
            newArr[i] = transactions[i];
        delete[] transactions;
        transactions = newArr;
    }

public:
    Library()
    {
        bookCapacity = borrowerCapacity = transactionCapacity = 10;
        bookCount = borrowerCount = transactionCount = 0;
        books = new Book *[bookCapacity];
        borrowers = new Borrower *[borrowerCapacity];
        transactions = new Transaction *[transactionCapacity];
    }

    ~Library()
    {
        for (int i = 0; i < bookCount; ++i)
            delete books[i];
        for (int i = 0; i < borrowerCount; ++i)
            delete borrowers[i];
        for (int i = 0; i < transactionCount; ++i)
            delete transactions[i];
        delete[] books;
        delete[] borrowers;
        delete[] transactions;
    }

    void addBook(Book *book)  //add a book to system
    {
        if (bookCount >= bookCapacity)
            resizeBooks();
        books[bookCount++] = book;
    }

    void addBorrower(Borrower *borrower)  //add a borrower to system
    {
        if (borrowerCount >= borrowerCapacity)
            resizeBorrowers();
        borrowers[borrowerCount++] = borrower;
    }

    void recordTransaction(Transaction *transaction)
    {
        if (transactionCount >= transactionCapacity)
            resizeTransactions();
        transactions[transactionCount++] = transaction;
    }

    Book *searchBookByTitle(const string &title) const
    {
        for (int i = 0; i < bookCount; ++i)
            if (books[i]->getBookTitle() == title)
                return books[i];
        return nullptr;
    }

    Borrower *searchBorrowerByName(const string &name) const
    {
        for (int i = 0; i < borrowerCount; ++i)
            if (borrowers[i]->getBorrowerName() == name)
                return borrowers[i];
        return nullptr;
    }

    void displayAllBooks() const
    {
        cout << "_All books_\n";
        for (int i = 0; i < bookCount; ++i)
            books[i]->displayBook();
    }

    void displayAllBorrowers() const
    {
        cout << "_All borrowers_\n";
        for (int i = 0; i < borrowerCount; ++i)
            borrowers[i]->displayBorrower();
    }

    void displayAllTransactions() const
    {
        cout << "_All transactions_\n";
        for (int i = 0; i < transactionCount; ++i)
            transactions[i]->displayTransaction();
    }

    Book **getBooks() const { return books; }
    Borrower **getBorrowers() const { return borrowers; }
    Transaction **getTransactions() const { return transactions; }

    int getBookCount() const { return bookCount; }
    int getBorrowerCount() const { return borrowerCount; }
    int getTransactionCount() const { return transactionCount; }
};

//******************************************************************** */
class DataHandler
{
private:
    string bookFile = "books.txt";
    string borrowerFile = "borrowers.txt";
    string transactionFile = "transactions.txt";

public:
    bool saveBooks(Book **books, int count) const
    {
        ofstream out(bookFile);
        if (!out)
            return false;
        for (int i = 0; i < count; ++i)
            out << books[i]->getBookID() << "," << books[i]->getBookTitle() << "," << books[i]->getPrice() << endl;
        return true;
    }

    bool loadBooks(Book **&books, int &count) const
    {
        ifstream in(bookFile);
        if (!in)
            return false;
        count = 0;
        string line;
        while (getline(in, line))
        {
            int id;
            string title;
            float price;
            size_t pos1 = line.find(",");
            size_t pos2 = line.rfind(",");
            id = stoi(line.substr(0, pos1));
            title = line.substr(pos1 + 1, pos2 - pos1 - 1);
            price = stof(line.substr(pos2 + 1));
            books[count++] = new Book(id, title, "Unknown", price);
        }
        return true;
    }

    bool saveBorrowers(Borrower **borrowers, int count) const
    {
        ofstream out(borrowerFile);
        if (!out)
            return false;
        for (int i = 0; i < count; ++i)
            out << borrowers[i]->getBorrowerID() << "," << borrowers[i]->getBorrowerName() << endl;
        return true;
    }

    bool loadBorrowers(Borrower **&borrowers, int &count) const
    {
        ifstream in(borrowerFile);
        if (!in)
            return false;
        count = 0;
        string line;
        while (getline(in, line))
        {
            int id;
            string name;
            size_t pos = line.find(",");
            id = stoi(line.substr(0, pos));
            name = line.substr(pos + 1);
            borrowers[count++] = new Borrower(id, name, "unknown@example.com");
        }
        return true;
    }

    bool saveTransactions(Transaction **transactions, int count) const
    {
        ofstream out(transactionFile);
        if (!out)
            return false;
        for (int i = 0; i < count; ++i)
            out << transactions[i]->getTransactionInfo() << endl;
        return true;
    }

    bool loadTransactions(Transaction **&transactions, int &count, Book **books, int bCount, Borrower **borrowers, int brCount) const
    {
        ifstream in(transactionFile);
        if (!in)
            return false;
        count = 0;
        string line;
        while (getline(in, line))
        {
            int tid, bid, brid;
            char date[20];
            sscanf(line.c_str(), "%d %d %d %s", &tid, &bid, &brid, date);
            Book *b = nullptr;
            Borrower *br = nullptr;
            for (int i = 0; i < bCount; ++i)
                if (books[i]->getBookID() == bid)
                    b = books[i];
            for (int i = 0; i < brCount; ++i)
                if (borrowers[i]->getBorrowerID() == brid)
                    br = borrowers[i];
            if (b && br)
                transactions[count++] = new Transaction(tid, *b, *br, date);
        }
        return true;
    }
};

// Menu functions
int main()
{
    Library library;
    DataHandler dataHandler;

    int choice;
    do
    {
        cout << "\n_Menu_\n";
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
        cout << "Select an option: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            Book *b = new Book();
            b->inputBook();
            library.addBook(b);
            break;
        }
        case 2:
        {
            Borrower *br = new Borrower();
            br->inputBorrower();
            library.addBorrower(br);
            break;
        }
        case 3:
        {
            int tid;
            string date;
            cout << "Enter transaction ID: ";
            cin >> tid;
            cin.ignore();
            string title, name;
            cout << "Enter book title: ";
            getline(cin, title);
            Book *b = library.searchBookByTitle(title);
            if (!b)
            {
                cout << "Book not found.\n";
                break;
            }

            cout << "Enter borrower name: ";
            getline(cin, name);
            Borrower *br = library.searchBorrowerByName(name);
            if (!br)
            {
                cout << "Borrower not found.\n";
                break;
            }

            cout << "Enter date (YYYY/MM/DD): ";
            getline(cin, date);

            Transaction *t = new Transaction(tid, *b, *br, date);
            library.recordTransaction(t);
            break;
        }
        case 4:
        {
            string title;
            cout << "Enter book title: ";
            getline(cin, title);
            Book *b = library.searchBookByTitle(title);
            if (b)
                b->displayBook();
            else
                cout << "Book not found.\n";
            break;
        }
        case 5:
        {
            string name;
            cout << "Enter borrower name: ";
            getline(cin, name);
            Borrower *br = library.searchBorrowerByName(name);
            if (br)
                br->displayBorrower();
            else
                cout << "Borrower not found.\n";
            break;
        }
        case 6:
            library.displayAllBooks();
            break;
        case 7:
            library.displayAllBorrowers();
            break;
        case 8:
            library.displayAllTransactions();
            break;
        case 9:
        {
            bool b1 = dataHandler.saveBooks(library.getBooks(), library.getBookCount());
            bool b2 = dataHandler.saveBorrowers(library.getBorrowers(), library.getBorrowerCount());
            bool b3 = dataHandler.saveTransactions(library.getTransactions(), library.getTransactionCount());
            cout << (b1 && b2 && b3 ? "Data saved.\n" : "Error saving.\n");
            break;
        }
        case 10:
        {
            Book **b = new Book *[100];
            Borrower **br = new Borrower *[100];
            Transaction **t = new Transaction *[100];
            int bc = 0, brc = 0, tc = 0;

            dataHandler.loadBooks(b, bc);
            for (int i = 0; i < bc; i++)
                library.addBook(b[i]);

            dataHandler.loadBorrowers(br, brc);
            for (int i = 0; i < brc; i++)
                library.addBorrower(br[i]);

            dataHandler.loadTransactions(t, tc, library.getBooks(), bc, library.getBorrowers(), brc);
            for (int i = 0; i < tc; i++)
                library.recordTransaction(t[i]);

            cout << "Data loaded.\n";
            break;
        }
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
