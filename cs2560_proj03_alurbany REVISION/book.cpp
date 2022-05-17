#include <string>
#include <iostream>
#include <iomanip>
#include "book.h"
using namespace std;
//constructor
Book::Book()
{
    this->next = nullptr;
}
//destructor
Book::~Book() 
{
    this->next = nullptr;
}
//Parameter Constructor
Book::Book(string title, string authors[], int authorCount, string publisher, short yearPublish, bool hardcover, float price, string isbn, long copies)
{
    this->title = title;

    for (int i = 0; i < authorCount; i++)
    {
        this->authors[i] = authors[i];
    }

    this->authorCount = authorCount;
    this->publisher = publisher;
    this->yearPublish = yearPublish;
    this->hardcover = hardcover;
    this->price = price;
    this->isbn = isbn;
    this->copies = copies;
    this->next = next;
}

Book* Book::getNext() const
{
    return this->next;
}

void Book::setNext (Book* next)
{
    this->next = next;
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
    book.title = temp;
    // Reads from the input file and placed the authorCount
    inputFile >> book.authorCount;
    getline(inputFile, die);
    // For loop to increment the book array in regards to authorCount
    for (int i = 0; i < book.authorCount; i++)
    {
        // Gets the line and the author
        getline(inputFile, temp);
	    book.authors[i] = temp;
    }

    // By now this should get the publisher name
    getline(inputFile, temp);
    book.publisher = temp;
    // Should get the year the book was made
    inputFile >> book.yearPublish;
    // Should get an answer to whether or not the book is a hardcover
    inputFile >> book.hardcover;
    // Getting the Price
    inputFile >> book.price;
    // Getting the ISBN
    getline(inputFile, die);
    getline(inputFile, book.isbn);

    // Getting the number of copies
    inputFile >> book.copies;
    getline(inputFile, die);
    return inputFile;
}

// This output stream sends out the data gathered from book.dat
ostream& operator<< (ostream& outputFile, const Book& book)
{
    outputFile << "\nTitle: " << book.title << endl;
    // For loop that increments, as you go through authors
    for (int ii = 0; ii < book.authorCount; ii++)
        outputFile << "\nAuthors: " << book.authors[ii] << endl;
    outputFile << "\nPublisher: " << book.publisher << endl;
    outputFile << "\nYear: " << book.yearPublish << endl;
    outputFile << "\nCover: ";
    // If statement to "convert" the number the file gives us to whether or not it's a hardcover
    if (book.hardcover == 0)
        outputFile << "Paperback" << endl;
    else
        outputFile << "Hardcover" << endl;
    outputFile << "\nPrice: " << book.price << endl;
    outputFile << "\nISBN: " << book.isbn << endl;
    outputFile << "\nCopies: " << book.copies << endl;

    return outputFile;
}

//setters
void Book::setTitle(string title)
{
    this->title = title;
}

void Book::setAuthors(int i, string author)
{
    this->authors[i] = authors[i];
}

void Book::setAuthorCount(int authorCount)
{
     this->authorCount = authorCount;
}

void Book::setPublisher(string publisher)
{
     this->publisher = publisher;
}

void Book::setYearPublish(short yearPublish)
{
     this->yearPublish = yearPublish;
}

void Book::setHardcover(bool hardcover)
{
     this->hardcover = hardcover;
}

void Book::setPrice(float price)
{
     this->price = price;
}

void Book::setISBN(string isbn)
{
     this->isbn = isbn;
}

void Book::setCopies(long copies)
{
     this->copies = copies;
}
//getters
string Book::getTitle() const
{
    return this->title;
}

string Book::getAuthors(int i) const
{
    return this->authors[i];
}

int Book::getAuthorCount() const
{
    return this->authorCount;
}

string Book::getPublisher() const
{
    return this->publisher;
}

short Book::getYearPublish() const
{
    return this->yearPublish;
}

bool Book::getHardcover() const
{
    return this->hardcover;
}

float Book::getPrice() const
{
    return this->price;
}

string Book::getISBN() const
{
    return this->isbn;
}

long Book::getCopies() const
{
    return this->copies;
}
