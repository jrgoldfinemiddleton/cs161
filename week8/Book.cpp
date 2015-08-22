/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 08/09/15
** Description: This file contains the Book class function
**              implementation.
**********************************************************/

#include "Book.hpp"

using std::string;


/*********************************************************************
** Description: Constructs a Book given an ID code, a title, and an
**              author name.
*********************************************************************/ 
Book::Book(string idc, string t, string a) {
  idCode = idc;
  title = t;
  author = a;
  
  // Book starts out neither checked out
  // nor requested by a Patron
  setLocation(ON_SHELF);
  setCheckedOutBy(NULL);  
  setRequestedBy(NULL);
  setDateCheckedOut(0);
}


/*********************************************************************
** Description: Returns the maximum number of days this Book may be
**              checked out by a Patron.
*********************************************************************/ 
int Book::getCheckOutLength() {
  return CHECK_OUT_LENGTH;
}


/*********************************************************************
** Description: Returns the ID code.
*********************************************************************/ 
string Book::getIdCode() {
  return idCode;
}


/*********************************************************************
** Description: Returns the title.
*********************************************************************/ 
string Book::getTitle() {
  return title;
}


/*********************************************************************
** Description: Returns the author name.
*********************************************************************/ 
string Book::getAuthor() {
  return author;
}


/*********************************************************************
** Description: Returns ON_SHELF, ON_HOLD_SHELF, or CHECKED_OUT
**              depending on the current status of this Book.
*********************************************************************/ 
Locale Book::getLocation() {
  return location;
}


/*********************************************************************
** Description: Updates the current status of this Book.
*********************************************************************/ 
void Book::setLocation(Locale loc) {
  location = loc;
}


/*********************************************************************
** Description: Returns a pointer to the Patron currently checking
**              out this Book.  Returns NULL if not checked out.
*********************************************************************/ 
Patron* Book::getCheckedOutBy() {
  return checkedOutBy;
}


/*********************************************************************
** Description: Updates the Patron currently checking out this Book
**              via a pointer.
*********************************************************************/ 
void Book::setCheckedOutBy(Patron *pat) {
  checkedOutBy = pat;
}


/*********************************************************************
** Description: Returns a pointer to the Patron currently requesting
**              this Book.  Returns NULL if not requested.
*********************************************************************/ 
Patron* Book::getRequestedBy() {
  return requestedBy;
}


/*********************************************************************
** Description: Updates the Patron currently requesting this Book
**              via a pointer.
*********************************************************************/ 
void Book::setRequestedBy(Patron *pat) {
  requestedBy = pat;
}


/*********************************************************************
** Description: Returns the date the book was checked out in the form
**              of days since the Library was created.
*********************************************************************/ 
int Book::getDateCheckedOut() {
  return dateCheckedOut;
}


/*********************************************************************
** Description: Updates the date the book was checked out in the form
**              of days since the Library was created.
*********************************************************************/ 
void Book::setDateCheckedOut(int date) {
  dateCheckedOut = date;
}
