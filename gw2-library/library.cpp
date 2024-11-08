#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <iomanip>
#include "library.h"

using namespace std;

Library::Library(){
  //remove if not needed
}

Library::~Library(){
  list<book>::iterator it;
  for(it = library.begin();it != library.end(); it++){
      del(it -> author, it -> title);
      }
}

void Library::load_library(string filename){
  ifstream newLib;
  newLib.open(filename);
  
  list<book>::iterator it;
  it = library.begin();
  
  while(newLib){
    book *temp = new book;
    
    getline(newLib, temp -> title);
    getline(newLib, temp -> author);
    getline(newLib, temp -> isbn);
    newLib >> temp -> pages >> temp -> price >> temp -> year;
    newLib.get();

    insert_sorted(*temp);
    it++;
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
  //get last name for current book
  cLastPos = it -> author.find_last_of(' ') + 1;
  currentLast = it -> author.substr(cLastPos);

  //same thing but for new book
  nLastPos = newBook.author.find_last_of(' ') + 1;
  newLast = newBook.author.substr(nLastPos);
  
  //checks order and updates current book
  while(it != library.end() && newLast > currentLast){
    it++;
    if(it = library.end()){
      cLastPos = it -> author.find_last_of(' ') + 1;
      currentLast = it -> author.substr(cLastPos);
    }
  }
  library.insert(it, newBook);
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
  }
cout << setw(30) << "------------------------------" << '+'
     << setw(15) << "-------------" << '+'
     << setw(5) << "-----" << '+' << setw(5) << "-----" << '+'
     << setw(8) << "--------" << endl;
  
}

void Library::find_album(string title){
//insert search here
}

void Library::del(string author, string title){
//insert delete here
}

