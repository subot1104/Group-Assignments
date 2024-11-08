/**
 * @file library.h
 * @author Jose Hipolito
 * @date 2024-11-08
 * @brief Header for library class
 * 
 * contains all method prototypes, private variables and book struct
 */

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
  std::list<book> library;

  public:
  ~Library();
  void load_library(std::string filename);
  void write_library(std::string filename);
  void print_library();
  void insert_sorted(const book &newBook);
  void find_author(std::string author);
  void find_album(std::string title);
  void del(std::string author, std::string title);
};
#endif
