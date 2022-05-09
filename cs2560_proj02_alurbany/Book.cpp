#include <string>
#include <iostream>
#include <iomanip>
#include "book.h"
using namespace std;
//constructor
Book::Book()
{
    title_ = "";
    authorCount_ = 0;
    publisher_ = "";
    isbn_ = "";
    yearPublish_ = 0;
    hardcover_ = false;
    price_ = 0;
    copies_ = 0;
}
//destructor
Book::~Book() 
{

}
//Parameter Constructor
Book::Book(string title, string authors[], int authorCount, string publisher, short yearPublish, bool hardcover, float price, string isbn, long copies)
{
    title_ = title;

    for (int i = 0; i < authorCount; i++)
    {
        authors_[i] = authors[i];
    }

    authorCount_ = authorCount;
    publisher_ = publisher;
    yearPublish_ = yearPublish;
    hardcover_ = hardcover;
    price_ = price;
    isbn_ = isbn;
    copies_ = copies;
}

// This is what parses book.dat for info. It collects the lines that equal
// different things. e.g. title, author, etc.
istream& operator>> (istream& inputFile, Book& book)
{
    // I call this the DIE variable. Cause of how this file reads things
    // after a line is parsed without getline, it doesn't move two lines,
    // thus, I have the getline DIE effect, which will move the required lines.
    string die;
    // This variable will store strings into a temp file
    string temp;
    // Should get the line data from the file
    getline(inputFile, temp);
    book.title_ = temp;
    // Reads from the input file and placed the authorCount
    inputFile >> book.authorCount_;
    getline(inputFile, die);
    // For loop to increment the book array in regards to authorCount
    for (int i = 0; i < book.authorCount_; i++)
    {
        // Gets the line and the author
        getline(inputFile, temp);
	    book.authors_[i] = temp;
    }

    // By now this should get the publisher name
    getline(inputFile, temp);
    book.publisher_ = temp;
    // Should get the year the book was made
    inputFile >> book.yearPublish_;
    // Should get an answer to whether or not the book is a hardcover
    inputFile >> book.hardcover_;
    // Getting the Price
    inputFile >> book.price_;
    // Getting the ISBN
    getline(inputFile, die);
    getline(inputFile, book.isbn_);

    // Getting the number of copies
    inputFile >> book.copies_;
    getline(inputFile, die);
    return inputFile;
}

// This output stream sends out the data gathered from book.dat
ostream& operator<< (ostream& outputFile, const Book& book)
{
    outputFile << "\nTitle: " << book.title_ << endl;
    // For loop that increments, as you go through authors
    for (int ii = 0; ii < book.authorCount_; ii++)
        outputFile << "\nAuthors: " << book.authors_[ii] << endl;
    outputFile << "\nPublisher: " << book.publisher_ << endl;
    outputFile << "\nYear: " << book.yearPublish_ << endl;
    outputFile << "\nCover: ";
    // If statement to "convert" the number the file gives us to whether or not it's a hardcover
    if (book.hardcover_ == 0)
        outputFile << "Paperback" << endl;
    else
        outputFile << "Hardcover" << endl;
    outputFile << "\nPrice: " << book.price_ << endl;
    outputFile << "\nISBN: " << book.isbn_ << endl;
    outputFile << "\nCopies: " << book.copies_ << endl;

    return outputFile;
}

//setters
void Book::setTitle(string title)
{
    title_ = title;
}

void Book::setAuthors(int i, string author)
{
   authors_[i] = author;
}

void Book::setAuthorCount(int authorCount)
{
    authorCount_ = authorCount;
}

void Book::setPublisher(string publisher)
{
    publisher_ = publisher;
}

void Book::setYearPublish(short yearPublish)
{
    yearPublish_ = yearPublish;
}

void Book::setHardcover(bool hardcover)
{
    hardcover_ = hardcover;
}

void Book::setPrice(float price)
{
    price_ = price;
}

void Book::setISBN(string isbn)
{
    isbn_ = isbn;
}

void Book::setCopies(long copies)
{
    copies_ = copies;
}
//getters
string Book::getTitle() const
{
    return title_;
}

string Book::getAuthors(int i) const
{
    return authors_[i];
}

int Book::getAuthorCount() const
{
    return authorCount_;
}

string Book::getPublisher() const
{
    return publisher_;
}

short Book::getYearPublish() const
{
    return yearPublish_;
}

bool Book::getHardcover() const
{
    return hardcover_;
}

float Book::getPrice() const
{
    return price_;
}

string Book::getISBN() const
{
    return isbn_;
}

long Book::getCopies() const
{
    return copies_;
}
