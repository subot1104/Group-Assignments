/**
 * @file library.cpp
 * @author Jose Hipolito
 * @date 2024-11-08
 * @brief library method defintions
 * 
 * contains method definitions for library class
 */

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <iomanip>
#include "library.h"

using namespace std;


Library::~Library(){
  library.clear();
}

void Library::load_library(string filename){
  ifstream newLib;
  newLib.open(filename);

  //clears library when theres something in there
  if(!library.empty())
    library.clear();
  
  book temp;
  
  getline(newLib, temp.title);
  getline(newLib, temp.author);
  getline(newLib, temp.isbn);
  newLib >> temp.pages >> temp.price >> temp.year;
  newLib.ignore();
  insert_sorted(temp);
  
  while(newLib){    
    getline(newLib, temp.title);
    getline(newLib, temp.author);
    getline(newLib, temp.isbn);
    newLib >> temp.pages >> temp.price >> temp.year;
    newLib.ignore();
    if(newLib)//double checks in case of empty line
      insert_sorted(temp);
  }

  newLib.close();
}

void Library::write_library(string filename){
  ofstream newLib;
  newLib.open(filename);
  list<book>::iterator it = library.begin();
  
  while (it != library.end()){
    newLib << it -> title << endl;
    newLib << it -> author << endl;
    newLib << it -> isbn << endl;
    newLib << it -> pages << ' ' << it -> price << ' ' << it -> year << endl;
    it++;
  }
  newLib.close();
}


void Library::insert_sorted(const book &newBook){
  list<book>::iterator it = library.begin();
  string currentLast;
  int cLastPos;
  string newLast;
  int nLastPos;
  //same thing but for new book
  nLastPos = newBook.author.find_last_of(' ') + 1;
  newLast = newBook.author.substr(nLastPos, newBook.author.size());
  if(library.empty()){
    library.push_back(newBook);
    return;
  }
  
  //checks order and updates current book
  while(it != library.end()){
    cLastPos = it -> author.find_last_of(' ') + 1;
    currentLast = it -> author.substr(cLastPos, it -> author.size());
    if (newLast < currentLast){
      library.insert(it, newBook);
      return;
    }
    it++;
  }
  library.push_back(newBook);
}

void Library::add_book(string title, string author, string isbn, int pages, float price, short year){
  book *newBook = new book;
  newBook -> title = title;
  newBook -> author = author;
  newBook -> isbn = isbn;
  newBook -> pages = pages;
  newBook -> price = price;
  newBook -> year = year;

  insert_sorted(*newBook);
}

void Library::find_author(string author){
  list<book> found_books;
  list<book>::iterator it = library.begin();

  //adds found books to a new list
  while(it != library.end()){
    if(author == it -> author)
      found_books.push_back(*it);
    it++;
  }
  //returns if no books found
  if (found_books.empty()){
    cout << "No books found" << endl;
    return;
  }
  else{
    //labels
    cout << setw(30) << "Title" << '|' << setw(15) << "ISBN" << '|' << setw(5)
	 << "Year" << '|' << setw(5) << "Pages" << '|' << setw(8) << "Price" << endl;
    cout << setw(30) << "------------------------------" << '+'
	 << setw(15) << "---------------" << '+'
	 << setw(5) << "-----" << '+' << setw(5) << "-----" << '+'
	 << setw(8) << "--------"<< endl;
    
    //list of found books
    it = found_books.begin();
    while(it != found_books.end()){
      cout << setw(30) << it -> title << '|' << setw(15) << it -> isbn << '|' << setw(5)
	   << it -> year << '|' << setw(5) << it -> pages << '|' << '$' << setw(7) << it -> price << endl;
      it++;
    }
  }
}

void Library::find_album(string title){
  list<book> found_books;
  list<book>::iterator it = library.begin();
  
  //adds found books to a new list
  while(it != library.end()){
    if(title == it -> title)
      found_books.push_back(*it);
    it++;
  }
  if (found_books.size() == 0){
    cout << "No books found" << endl;
    return;
  }
  else{
    //labels
    cout << setw(30) << "Author" << '|' << setw(15) << "ISBN" << '|' << setw(5)
	 << "Year" << '|' << setw(5) << "Pages" << '|' << setw(8) << "Price" << endl;
    cout << setw(30) << "------------------------------" << '+'
	 << setw(15) << "---------------" << '+'
	 << setw(5) << "-----" << '+' << setw(5) << "-----" << '+'
	 << setw(8) << "--------"<< endl;
    
    //list of found books
    it = found_books.begin();
    while(it != found_books.end()){
      cout << setw(30) << it -> author << '|' << setw(15) << it -> isbn << '|' << setw(5)
	   << it -> year << '|' << setw(5) << it -> pages << '|' << '$' << setw(7) << it -> price << endl;
      it++;
    }
  }
}

void Library::del(string author, string title){
  list<book>::iterator it = library.begin();

  while(it != library.end() && (it -> author != author || it -> title != title)){
    it++;
  }
  if(it == library.end()){
    cout << "Book not found" << endl;
    return;
  }
  library.erase(it);
}

void Library::print_library(){
  //labels
  cout << setw(30) << "Title" << '|'
       << setw(30) << "Author" << '|'
       << setw(15) << "ISBN" << '|'
       << setw(5) << "Year" << '|'
       << setw(5) << "Pages" << '|'
       << setw(8) << "Price" << endl;
  cout << setw(30) << "------------------------------" << '+'
       << setw(30) << "------------------------------" << '+'
       << setw(15) << "---------------" << '+'
       << setw(5) << "-----" << '+'
       << setw(5) << "-----" << '+'
       << setw(8) << "--------" << endl;

  //contents
  list<book>::iterator it = library.begin();
  while(it != library.end()){
    cout << setw(30) << it -> title << '|'
	 << setw(30) << it -> author << '|'
	 << setw(15) << it -> isbn << '|'
	 << setw(5) << it -> year << '|'
	 << setw(5) << it -> pages << '|'
	 << '$' << setw(7) << it -> price << endl;
    it++;
  }
}
