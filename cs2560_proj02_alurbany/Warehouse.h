#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <string>
#include "book.h"
using namespace std;

class Warehouse {

    friend istream& operator >> ( istream& is, Warehouse& warehouse );
    friend ostream& operator << ( ostream& os, const Warehouse& warehouse );

    public:
        static const int MAX_BOOKS = 35;
        Warehouse();
        ~Warehouse();

        // Returns a boolean for whether or not a match could be found
        bool find (string isbn, Book& book) const;
        // Returns the books
        void list (Book& book) const;
    
    private:
        void sort_();
    
    private:
        Book books[Warehouse::MAX_BOOKS];
        int bookCount;
};

#endif
