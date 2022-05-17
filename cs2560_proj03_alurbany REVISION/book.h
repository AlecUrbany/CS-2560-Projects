#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
using namespace std;
class Book 
{
    /** 
     * @param is  the input stream
     * @param book the book object to be filled
     * @return istream&
     */
    friend istream& operator >> ( istream& is, Book& book );
    /** 
     * @param os the output stream 
     * @param book the book object reference
     * @return ostream& 
     */
    friend ostream& operator << ( ostream& os, const Book& book );

    public:
        static const int MAX_AUTHORS = 35;
        Book();
        ~Book();
        Book (string title, string authors[], int authorCount, string publisher,
               short yearPublish, bool hardcover, float price,
               string isbn, long copies);
        Book* getNext() const;

        void setNext (Book* next);
        
        void  setTitle ( string title ); 
        string getTitle() const;

        void setAuthors(int, string);
        string getAuthors(int) const;
        
        void setAuthorCount ( int authorCount );
        int getAuthorCount() const;

        void setPublisher ( string publisher );
        string getPublisher() const;
        
        void setYearPublish ( short yearPublish );
        short getYearPublish() const;

        void setHardcover ( bool hardcover );
        bool getHardcover() const;

        void setPrice ( float price );
        float getPrice() const;

        void setISBN ( string isbn );
        string getISBN() const;

        void setCopies ( long copies );
        long getCopies() const;

        /** add all relevant setter & getter methods here DONE**/
    private:
        string title;
        string authors[Book::MAX_AUTHORS];
        int authorCount;
        string publisher;
        short yearPublish;
        bool hardcover;
        float price;
        string isbn;
        long copies;
        Book* next;
        /** add all attributes here DONE**/

};
#endif