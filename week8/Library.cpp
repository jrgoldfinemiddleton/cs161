/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 
** Description: This file contains the Library class
**              function implementation.
**********************************************************/

#include "Library.hpp"

using std::string;
using std::vector;


/*********************************************************************
** Description: Constructs a library and sets the current date to 0.
*********************************************************************/ 
Library::Library() {
  currentDate = 0;
}


/*********************************************************************
** Description: Adds a Book to this Library's holdings via a pointer.
*********************************************************************/ 
void Library::addBook(Book *b) {
  holdings.push_back(b);
}


/*********************************************************************
** Description: Adds a Patron to this Library's members via a pointer.
*********************************************************************/ 
void Library::addPatron(Patron *pat) {
  members.push_back(pat);
}


/*********************************************************************
** Description: Allows a Patron to check out a Book from this Library
**              given that certain conditions are met.  Returns a
**              string indicating the status of the check out attempt.
*********************************************************************/ 
string Library::checkOutBook(string pID, string bID) {
  Book *book = getBook(bID);        // Book desired
  Patron *patron = getPatron(pID);  // Patron seeking book

  // if Book is not in holdings, do not allow check out
  if (!book) {
    return "book not found";
  }

  // if Patron is not a member, do not allow check out
  if (!patron) {
    return "patron not found";
  }

  // determine Book's status
  Locale status = book->getLocation();

  if (status == CHECKED_OUT) {
    return "book already checked out";
  }

  // if this Patron wants to check out a Book someone else
  // has on hold, do not allow check out
  if (status == ON_HOLD_SHELF) {
    if (book->getRequestedBy() != patron) {
      return "book on hold by other patron";
    } else {
      // otherwise this Patron is allowed to check out the Book,
      // so no one is now requesting it
      book->setRequestedBy(NULL);
    }
  }

  // update Book's status and other info
  book->setCheckedOutBy(patron);
  book->setDateCheckedOut(currentDate);
  book->setLocation(CHECKED_OUT);

  // add the Book to the list of Books checked out by this
  // Patron
  patron->addBook(book);

  return "check out successful";
}


/*********************************************************************
** Description: Allows a Patron to return a Book to this Library.
**              Returns a string indicating the status of the return
**              attempt.
*********************************************************************/ 
string Library::returnBook(string bID) {
  Book *book = getBook(bID);  // Book to return

  // if Book is not part of Library's holdings, do not accept return
  if (!book) {
    return "book not found";
  }

  // determine Book's status
  Locale status = book->getLocation();

  // only return the Book if it is currently checked out
  if (status != CHECKED_OUT) {
    return "book already in library";
  }

  // figure out who is returning the Book
  Patron *patron = book->getCheckedOutBy();

  // remove it from their list of checked out Books
  patron->removeBook(book);

  // if it was requested by someone else, put it on the hold shelf
  // otherwise put it on the shelf
  if (book->getRequestedBy()) {
    book->setLocation(ON_HOLD_SHELF);
  } else {
    book->setLocation(ON_SHELF);
  }
  
  // no one is currently checking the book out now
  book->setCheckedOutBy(NULL);

  return "return successful";
}


/*********************************************************************
** Description: Allows a Patron to request a Book from this Library
**              given that certain conditions are met.  Returns a
**              string indicating the status of the request attempt.
*********************************************************************/ 
string Library::requestBook(string pID, string bID) {
  Book *book = getBook(bID);        // Book desired
  Patron *patron = getPatron(pID);  // Patron seeking Book

  // if Book is not part of Library's holdings, do not allow request
  if (!book) {
    return "book not found";
  }

  // if Patron is not a member, do not allow request  
  if (!patron) {
    return "patron not found";
  }

  // determine Book's status
  Locale status = book->getLocation();

  // if Book is on hold, check to see if it's by this Patron
  // if not, do not allow request
  if (status == ON_HOLD_SHELF) {
    if (book->getRequestedBy() != patron) {
      return "book on hold by other patron";
    }
  }

  // put the book on hold if it wasn't already
  if (book->getLocation() == ON_SHELF) {
    book->setLocation(ON_HOLD_SHELF);
  }
  book->setRequestedBy(patron);

  return "request successful";
}


/*********************************************************************
** Description: Attempts to pay this Library a fine for the Patron
**              with the given ID number and in the given dollar
**              amount.  The Patron's amount owed is updated.  Returns
**              a string indicating whether the transaction was
**              successful.
*********************************************************************/ 
// takes amount being paid, not negative of that amount
string Library::payFine(string pID, double payment) {
  Patron *patron = getPatron(pID);
  
  // if Patron is not a Library member, does not pay fine
  if (!patron) {
    return "patron not found";
  }

  patron->amendFine(-payment);

  return "payment successful";
}


/*********************************************************************
** Description: Increments the current date.  Also adds 10 cents per
**              overdue book to every Patron member's debt.
*********************************************************************/ 
void Library::incrementCurrentDate() {
  // increment the current date
  ++currentDate;
  
  // number of Books in the Library's holdings
  int numHoldings = holdings.size();

  // if the book is overdue, charge the Patron who has it checked out
  // 10 cents
  for (int i = 0; i < numHoldings; i++) {
    Book *book = holdings.at(i);
    int checkOutLength = book->getCheckOutLength();

    int dateCheckedOut = book->getDateCheckedOut();
    int dueDate = dateCheckedOut + checkOutLength;

    int daysOverdue = currentDate - dueDate;

    if (daysOverdue > 0) {
      Patron *patron = book->getCheckedOutBy();
      if (patron != NULL) {
        patron->amendFine(0.10);
      }
    }
  }
}


/*********************************************************************
** Description: Returns a pointer to the Patron with the given ID
**              number.  Returns NULL if the ID cannot be identified.
*********************************************************************/ 
Patron* Library::getPatron(string pID) {
  int numMembers = members.size();

  // search through all the members
  for (int i = 0; i < numMembers; i++) {
    string curID = members.at(i)->getIdNum();

    // check for equality of strings
    if (pID == curID) {
      return members.at(i);
    }
  }

  // given ID did not match a Patron member
  return NULL;
}


/*********************************************************************
** Description: Returns a pointer to the Book with the given ID code.
**              Returns NULL if the ID does not match a Book.
*********************************************************************/ 
Book* Library::getBook(string bID) {
  int numHoldings = holdings.size();

  // search through the Book holdings
  for (int i = 0; i < numHoldings; i++) {
    string curID = holdings.at(i)->getIdCode();

    // check for equality of strings
    if (bID == curID) {
      return holdings.at(i);
    }
  }

  // given ID did not match a Book in the holdings
  return NULL;
}
