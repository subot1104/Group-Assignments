#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <iomanip>

class Library{
  struct book{
    std::string title;
    std::string author;
    int pages;
    std::string isbn;
    float price;
    short year;
  };
  private:
  list<book> library;

  public:
  Library();
  ~Library();
  void load_library(string filename);
  void insert_sorted(book newBook);
  void find_author(string author);
  void find_album(string title);
  void del(string author, string title);


};
#endif
