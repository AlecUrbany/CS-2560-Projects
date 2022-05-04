#include <iostream>
#include <cstring>
#include "book.h"
using namespace std;

// Main function definition
const int maxEntries = 35;
Book library[maxEntries];

int main (int argc, char* argv[]) 
{
    using namespace std;
    if (argc == 3 && !strcmp("list", argv[2]))
    {
        allBooks(library, read(argv[1], library));
    }

    if (argc == 4 && !strcmp("find", argv[2]))
    {
        cout << find(argv[3], library, read(argv[1], library)) << endl;
    }

    else
    {
        cout << "To list books: ";
        cout << argv[0]<< " <book.dat> <list>" << endl;
        cout << "To find books: ";
        cout << argv[0]<< " <book.dat> <find> <ISBN>" << endl;
        return -1;
    }
    return 0;
}
