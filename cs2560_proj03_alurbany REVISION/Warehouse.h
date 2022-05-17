#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <string>
#include "book.h"

using namespace std;

class Warehouse 
{
    friend istream& operator >> ( istream& is, Warehouse& warehouse );
    friend ostream& operator << ( ostream& os, const Warehouse& warehouse );

    public:
        static const int MAX_BOOKS = 35;
        Warehouse();
        ~Warehouse();

        // Returns a boolean for whether or not a match could be found
        Book* find (string isbn) const;
        // Returns the books
        void list () const;
    
    private:
        void sort_();
    
    private:
        Book* head;
        int bookCount;
};

#endif
