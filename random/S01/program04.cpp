// functional but need to separate horizontal and vertical search into functions

#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 100;         //Size of grid

void vertSearch(string word, char a[SIZE])
{
string vSearch[SIZE];
 for(int i = 0; vSearch[SIZE] != word; i++) {
  vSearch[i] += a[i+4];
 if(vSearch[SIZE] == word) cout << "\nFound (vertical)";
 }
}

void horizSearch(string word, char a[SIZE])
{
 string hSearch[SIZE];
 for(int i = 0; i < SIZE; i++) {
  hSearch[i] += a[i+1];
 if(hSearch[SIZE] == word) cout << "\nFound (horizontal)";
 }
}

int main()
{
   char a[SIZE];     
   ifstream f("grid.txt");
   for (int i = 0; i < SIZE; i++)
   f >> a[i];
   f.close();

   string word;

   cout << "Enter letters to search: ";
   cin >> word;

   vertSearch(word,  a);
   horizSearch(word,  a);

}
