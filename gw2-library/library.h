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


/**
 * contains class variables and methods for Library class
 *
 * @class Library{ library.h "gw2-library/library.h"
 * @brief Library class
 *
 */
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

/**
 * destructor that delete the library from memory.
 *
 * @pre library object is created
 * @post library is deleted
 * 
 */
  ~Library();

/**
 * loads library into memory using an inputted file
 *
 * @param std::string filename file's name
 * @pre library object is created
 * @return void 
 * @post loads library file into memory
 * 
 */
  void load_library(std::string filename);

/**
 * writes library loaded in memory into a file
 *
 * @param std::string filename file that is being written to
 * @pre a library is loaded into memory.
 * @return void 
 * @post creates a library file
 * 
 */
  void write_library(std::string filename);

/**
 * prints loaded library onto command line
 *
 * @pre a library is loaded into memory
 * @return void 
 * @post library is printed in a table
 * 
 */
  void print_library();

/**
 * inserts a new book into the library by order of last name.
 *
 * @param const book &newBook book being added
 * @pre library object is called
 * @return void 
 * @post new book is inserted in proper order
 * 
 */
  void insert_sorted(const book &newBook);

/**
 * finds all books by an author and prints it onto the command line
 *
 * @param std::string author author being searched
 * @pre at least 1 book by the author is loaded into memory
 * @return void 
 * @post prints all book found
 * 
 */
  void find_author(std::string author);

/**
 * finds all books with a given name
 *
 * @param std::string title title of the book
 * @pre there is at least 1 book in memory with the given title
 * @return void 
 * @post prints all book with the given title to command line
 * 
 */
  void find_album(std::string title);

/**
 * deletes a book from the library given an author and title
 *
 * @param std::string author author of the book
 * @param std::string title title of the book
 * @pre the book is loaded into memory
 * @return void 
 * @post book is deleted
 * 
 */
  void del(std::string author, std::string title);
};
#endif
