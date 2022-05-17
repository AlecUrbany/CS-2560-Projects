#include <iostream>
#include <cstring>
#include <fstream>
#include "book.h"
#include "Warehouse.h"
using namespace std;
// g++ -Wall -std=c++17 -o proj03 proj03.cpp Book.cpp Warehouse.cpp (compiler phrase since I'm lazy)
int main (int argc, char* argv[]) 
{
    Warehouse storage;
    Book book;
    ifstream file;
    using namespace std;
    string filename = argv[1];

    file.open(filename);
    if (file.fail()) {
        cout << "File failed to open" << endl;
        return -1;
    }
    file >> storage;
    if (argc == 3 && !strcmp("list", argv[2]))
    {
        storage.list();
    }

    if (argc == 4 && !strcmp("find", argv[2]))
    {
        string querie = argv[3];
        Book* book {nullptr};
        string isbn {querie};
        book = storage.find(isbn);
        if(book)
        {
           cout << "Found!" << endl; 
        }
        else
        {
            cout << "If an item does not appear in our records, it does not exist!" << endl;  
        }
        
    }

    else
    {
        cout << "To list books: ";
        cout << argv[0] << " <book.dat> <list>" << endl;
        cout << "To find books: ";
        cout << argv[0] << " <book.dat> <find> <ISBN>" << endl;
        return -1;
    }
    return 0;
}
