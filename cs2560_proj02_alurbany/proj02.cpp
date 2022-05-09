#include <iostream>
#include <cstring>
#include <fstream>
#include "book.h"
#include "Warehouse.h"
using namespace std;

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
    file >> book;
    if (argc == 3 && !strcmp("list", argv[2]))
    {
        storage.list(book); 
        return 0;
    }

    if (argc == 4 && !strcmp("find", argv[2]))
    {
        string querie = argv[3];
        storage.find(querie, book);
        return 0;
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
