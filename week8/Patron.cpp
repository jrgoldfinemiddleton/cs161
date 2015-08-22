/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 
** Description: This file contains the Patron class
**              function implementation.
**********************************************************/

#include "Patron.hpp"

using std::string;
using std::vector;


/*********************************************************************
** Description: Constructs a Patron given an ID number and a name.
*********************************************************************/ 
Patron::Patron(string idn, string n) {
  idNum = idn;
  name = n;
  fineAmount = 0.0;  

  // vector already declared
}


/*********************************************************************
** Description: Returns the ID number.
*********************************************************************/ 
string Patron::getIdNum() {
  return idNum;
}


/*********************************************************************
** Description: Returns the name.
*********************************************************************/ 
string Patron::getName() {
  return name;
}


/*********************************************************************
** Description: Returns the list of books this Patron currently has
**              checked out in the form of a vector of pointers to
**              Books.
*********************************************************************/ 
vector<Book*> Patron::getCheckedOutBooks() {
  return checkedOutBooks;
}


/*********************************************************************
** Description: Appends a pointer to a Book to the list of this
**              Patron's checked out books. 
*********************************************************************/ 
void Patron::addBook(Book *b) {
  checkedOutBooks.push_back(b);
}


/*********************************************************************
** Description: Removes a book from the list of books checked out
**              given a pointer to a Book.
*********************************************************************/ 
void Patron::removeBook(Book *b) {
  // length of list of books
  int numCheckedOutBooks = checkedOutBooks.size();

  // search for the book passed as a parameter in the list of
  // checked out books and remove it when it is found
  for (int i = 0; i < numCheckedOutBooks; i++) {
    Book *curBook = checkedOutBooks.at(i);
    if (b == curBook) {
      checkedOutBooks.erase(checkedOutBooks.begin() + i);
      return;
    }
  }
}


/*********************************************************************
** Description: Returns the current total dollar amount this Patron
**              owes the Library in fines.
*********************************************************************/ 
double Patron::getFineAmount() {
  return fineAmount;
}


/*********************************************************************
** Description: Adds the given dollar amount to the total fines this
**              Patron owes the Library.
*********************************************************************/ 
void Patron::amendFine(double amount) {
  fineAmount += amount;
}

