#include <iostream>
#include <fstream>
#include <string>
#include "book.h"
#include <cstring>

int read(string filename, Book books[])
{
    ifstream inputFile;
    // A tally to keep track of the book number in the array
    int number = 0;
    // Opening the File
    inputFile.open(filename);
    // Conditional statement in the off chance the file is unable to be opened.
    if (inputFile.fail())
    {
        cout << "File could not be opened" << endl;
        inputFile.close();
        return -1;
    }
    // While loop that will continue so long as the file is not finished
    while (true)
    {
        string die;
        // Should get the line data from the file
        getline(inputFile, books[number].title);
        // Reads from the input file and placed the authorCount
        inputFile >> books[number].authorCount;
        // For loop to increment the book array in regards to authorCount
        getline(inputFile, die);
        for (int i = 0; i < books[number].authorCount; i++)
        {
            // Gets the line and the author
            getline(inputFile, books[number].authors[i]);
            //cout<<"I'm getting author"<<endl;
        }
        // By now this should get the publisher name
        getline(inputFile, books[number].publisher);
        //cout<<"I'm getting publisher"<<endl;
        // Should get the year the book was made
        inputFile >> books[number].yearPublish;
        //cout<<"I'm getting year"<<endl;
        // Should get an answer to whether or not the book is a hardcover
        inputFile >> books[number].hardcover;
        //cout<<"I'm getting cover type"<<endl;
        // Should get a price to the book
        inputFile >> books[number].price;
        //cout<<"I'm getting price"<<endl;
        // Should get an isbn for the book
        getline(inputFile, die);
        inputFile >>  books[number].isbn;
        //cout<<"I'm getting ISBN"<<endl;
        // Should find out how many copies of the book exists
        inputFile >> books[number].copies;
        //cout<<"I'm getting copies"<<endl;
        getline(inputFile, die);

        if (inputFile.eof())
        {
            break;
        }

        number++;
    }

    // Closing the file is a good habit.
    inputFile.close();
    // Should give us the book we want
    return number;
}
// This should print out whatever single book is called
void singleBook(Book books[], int i)
{
    cout << "\nTitle: " << books[i].title;
    // For loop that increments, as you go through authors
    for (int ii = 0; ii < books[i].authorCount; ii++)

        cout << "\nAuthors: " << books[i].authors[ii];

    cout << "\nPublisher: " << books[i].publisher << endl;
    cout << "Date Published: " << books[i].yearPublish << endl;
    cout << "Cover: ";
    // If statement to "convert" the number the file gives us to whether or not it's a hardcover
    if (!books[i].hardcover)
        cout << "Paperback";
    else
        cout << "Hardcover";

    cout << "\nPrice: $" << books[i].price << endl;
    cout << "ISBN: " << books[i].isbn << endl;
    cout << "Copies: " << books[i].copies << endl;
}

// Should print out every book
void allBooks(Book books[], int length)
{
    // For loop that increments the array. Each book is a part of the book array
    // So as each book is printed, the array increments.
    for (int i = 0; i < length; ++i)
    {
        cout << "\nBook Title:" << books[i].title;
        // Loop to get the authors
        for (int ii = 0; ii < books[i].authorCount; ++ii)
        {
            cout << "\nAuthors: " << books[i].authors[ii];
        }
        cout << "\nPublisher: " << books[i].publisher << endl;
        cout << "Date Published: " << books[i].yearPublish << endl;
        cout << "Cover: ";
        // If statement to "convert" the number the file gives us to whether or not it's a hardcover
        if (!books[i].hardcover)
            cout << "Paperback";
        else
            cout << "Paper Regular";

        cout << "\nPrice: $" << books[i].price << endl;
        cout << "ISBN: " << books[i].isbn << endl;
        cout << "Copies: " << books[i].copies << endl;
    }
}

// The find function of the file.
int find(string id, Book books[], int length)
{
    // This for loop will increment until it finds a match.
    for (int i = 0; i < length; i++)
    {
        string trueisbn = books[i].isbn;
        // If there's no match, it reads an error message.
        if (id.compare(books[i].isbn) == 0)
        {
            cout << "match found in book " << (i + 1) << endl;
            cout << "\nBook Title:" << books[i].title;
            // Loop to get the authors
            for (int ii = 0; ii < books[i].authorCount; ++ii)
            {
                cout << "\nAuthors: " << books[i].authors[ii];
            }
            cout << "\nPublisher: " << books[i].publisher << endl;
            cout << "Date Published: " << books[i].yearPublish << endl;
            cout << "Cover: ";
            // If statement to "convert" the number the file gives us to whether or not it's a hardcover
            if (!books[i].hardcover)
                cout << "Paperback";
            else
                cout << "Paper Regular";

            cout << "\nPrice: $" << books[i].price << endl;
            cout << "ISBN: " << books[i].isbn << endl;
            cout << "Copies: " << books[i].copies << endl;
            return 0;
        }
        else
        {    
        cout << "no match in book " << (i + 1) << endl;
        }
    }
    return -1;
}
