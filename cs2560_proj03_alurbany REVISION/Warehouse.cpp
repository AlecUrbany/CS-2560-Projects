#include "Warehouse.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
Warehouse::Warehouse() 
{
    this->head = nullptr;
    bookCount = 0;
}
Warehouse::~Warehouse()
{

}


istream& operator >> (istream& inputFile, Warehouse& obj) 
{
    int bookCount = 0;
    Book* temp = new Book;
    obj.head = temp;
    inputFile >> *temp;
    temp->setNext(new Book());
    temp = temp->getNext();
    while (inputFile.peek() != EOF)
    {
            inputFile >> *temp;
            temp->setNext(new Book());
            temp = temp->getNext();
            bookCount++;
    }
    
    return inputFile;
}

ostream& operator << (ostream& out, const Warehouse& obj) 
{
    Book* actualBook = obj.head;
    //while loop runs through the book
    while(actualBook)
    {
        out << *actualBook <<endl;
        // Will send a pointer to get the next book
        actualBook = actualBook->getNext();
    }
    return out;
}

Book* Warehouse::find(string isbn) const 
{
    Book* temp = this->head;
    while(temp)
    {
        if(temp->getISBN() == isbn)
        {
            cout << *temp << endl;
            break;
        }
        temp = temp->getNext();
    }
        return temp;
}


// it will print out books
void Warehouse::list() const 
{
    Book* temp = this->head;
    if (this->head == nullptr)
    {
        cout << "no books found" << endl;
        return;
    }
    else
    {
        while(temp)
        {  
            cout << *temp << endl;
            temp = temp->getNext();
        }
    }

}
