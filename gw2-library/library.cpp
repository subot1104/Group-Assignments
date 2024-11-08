#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <iomanip>
#include "Library.h"

using namespace std;

Library::Library()
{
  library.begin() = NULL;
}

Library::~Library(){
  library<book>::iterator it;
  for(it = library.begin(); it != library.end(); it++){
      del(it -> author, it -> title);
      }
}

void Library::load_library(string filename){
  ifstream newLib;
  newLib.open(filename);
  
  library<book>::iterator it;
  it = library.begin();
  
  while(newLib){
  it++;
  book *temp = new book;
  
  getline(newLib, temp -> title);
  getline(newLib, temp -> author);
  getline(newLib, it -> isbn);
  newLib >> pages >> price >> year;
  newLib.get();
  }

  newLib.close();

void Library::insert_sorted(book newBook){
//insert sort here
}

void Library::find_author(string author){
//insert search here
}

void Library::find_album(string title){
//insert search here
}

void Library::del(string author, string title){
//insert delete here
}

