#include <iostream>
#include <fstream>
using namespace std;

class Book{
    private:
     int year;
     string title;
     string author;

    public:

     Book() : title("Title"), author("Author"), year(0);
     void display(){
        cout << "Title: " << this->title << ", author: " << this->author << ", year: " << this->year;
     };
};

int main(){
    Book book1;
    book1.display();
}
