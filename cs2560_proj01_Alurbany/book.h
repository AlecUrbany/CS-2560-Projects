// @file book.h 
 
#ifndef BOOK_H 
#define BOOK_H 
 
#include <string> 
using namespace std; 
 
const int MAX_AUTHORS = 20; 
 
struct Book { 
   string title; 
   string authors[MAX_AUTHORS]; 
   short authorCount; 
   string publisher; 
   short yearPublish; 
   bool hardcover; 
   float price; 
   string isbn; 
   long copies; 
}; 
 
/** 
 * @param filename name of the input data file 
 * @param books[] an array of textbook records read from the file 
 * 
 * @return the number of textbook records read 
 */ 
int read (string filename, Book books[]); 
 
/** 
 * @param id the ISBN number to search for 
 * @param books[] the list of textbook records 
 * @param length the number of textbook records in the array 
 * 
 * @return the array index of the matching record, otherwise it returns -1 
 */ 
int find (string id, Book books[], int length); 
 
void allBooks(Book books[], int length);
#endif /* BOOK_H */ 