#include "Warehouse.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
Warehouse::Warehouse() 
{
    bookCount = 0;
}
Warehouse::~Warehouse()
{

}

istream& operator >> (istream& inputFile, Warehouse& obj) 
{
    obj.bookCount = 0;
    while (inputFile.peek() != EOF && obj.bookCount < obj.MAX_BOOKS) 
    {
        inputFile >> obj.books[obj.bookCount];
        obj.bookCount++;    
    }
    return inputFile;
}

ostream& operator << (ostream& out, const Warehouse& obj) 
{
    for (int i = 0; i < obj.bookCount; i++) 
    {
        out << obj.books[i];
    }
    return out;
}

bool Warehouse::find(string isbn, Book& books) const 
{
   for (int i = 0; i < bookCount; i++) 
   {
       // Setting up the variables so that we can compare ISBN's
       Book book = this->books[i];
       string search = book.getISBN();
       cout << "searching book "<< i+1 << "... " << endl;
       if (search == isbn)
       {
            cout << "Found!" << endl;
            cout << "\nTitle: " << book.getTitle() << endl;
            // For loop that increments, as you go through authors
            for (int ii = 0; ii < book.getAuthorCount(); ii++)
                cout << "\nAuthors: " << book.getAuthors(ii) << endl;
            cout << "\nPublisher: " << book.getPublisher() << endl;
            cout << "\nYear: " << book.getYearPublish() << endl;
            cout << "\nCover: ";
            // If statement to "convert" the number the file gives us to whether or not it's a hardcover
            if (book.getHardcover() == 0)
            {
                cout << "Paperback" << endl;
            }
            else
            {
                cout << "Hardcover" << endl;
            }
            cout << "\nPrice: " << book.getPrice() << endl;
            cout << "\nISBN: " << book.getISBN() << endl;
            cout << "\nCopies: " << book.getCopies() << endl;

            return true;
        } 
   }
   return false;
}

// This is the list that actually lists books. So long as i is < bookcount
// it will print out books
void Warehouse::list(Book& book) const 
{
    int i = 0;
    while (i != bookCount) 
    {
        cout << books[i] << endl;
        i++;
    }

}
