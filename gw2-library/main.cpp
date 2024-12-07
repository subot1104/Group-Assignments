/**
 * @file main.cpp
 * @author Jose Hipolito
 * @date 2024-11-08
 * @brief library driver
 * 
 * driver for the library class
 */

#include <iostream>
#include "library.h"

using namespace std;

int main() {
  char choice = 0;
  while(choice != 'q'){
    switch(choice){
    case '1':
      cout << endl << "Please enter file name here:  ";
      cin >> filename;
      cout << "loading file..." << endl;
      lib.load_library(filename);
      cout << "file loaded. Please press enter to continue." << endl;
      cin.ignore();
      cin.get();
      choice = 0;
      break;
    case '2':
      cout << endl << "Please enter file name here:  ";
      cin >> filename;
      cout << "writing file..." << endl;
      lib.write_library(filename);
      cout << "File written. Please press enter to continue." << endl;
      cin.ignore();
      cin.get();
      choice = 0;
      break;
    case '3':
      cout << endl;
      lib.print_library();
      cout << endl << "Please press enter to continue." << endl;
      cin.ignore();
      cin.get();
      choice = 0;
      break;
    case '4':
      cout << endl << "Please enter author's name here:  ";
      cin.ignore();
      getline(cin, author);
      cout << endl << "Here's all books by " << author << endl;
      lib.find_author(author);
      cout << endl << "Press enter to continue." << endl;
      cin.get();
      choice = 0;
      break;
    case '5':
      cout << endl << "Please enter book title here:  ";
      cin.ignore();
      getline(cin,title);
      cout << endl << "Here's " << title << '.' << endl;
      lib.find_album(title);
      cout << endl << "Press enter to continue." << endl;
      cin.get();
      choice = 0;
      break;
    case '6':
      cout << endl << "Please enter the title of the book:  ";
      cin.ignore();
      getline(cin, title);
      cout << "Please enter the author of the book:  ";
      getline(cin, author);
      cout << endl << "Deleting book..." << endl;
      lib.del(author, title);
      cout << endl << "Book deleted. Please press enter to continue." << endl;
      cin.get();
      choice = 0;
      break;
    case '7':
      cout << endl << "Please enter the title:  ";
      cin.ignore();
      getline(cin, title);
      cout << "Please enter the author:  ";
      getline(cin, author);
      cout << "Please enter the ISBN:  ";
      getline(cin, isbn);
      cout << "Please enter the number of pages:  ";
      cin >> pages;
      cout << "Please enter the price of the book:  ";
      cin >> price;
      cout << "Please enter the publish year:  ";
      cin >> year;

      cout << endl << "Adding book..." << endl;
      lib.add_book(title, author, isbn, pages, price, year);
      cout << endl << "Book added. Please press enter to continue." << endl;
      cin.ignore();
      cin.get();
      choice = 0;
      break;
    case 'q':
      cout << "Bye" << endl;
      break;
      
    default:
      cout << "Welcome to the UTM library. Please select from one of the following options." << endl;
      cout << "1: Load library from file." << endl;
      cout << "2: Write library into file." << endl;
      cout << "3: Print library." << endl;
      cout << "4: Search by author." << endl;
      cout << "5: Search by title." << endl;
      cout << "6: Delete book." << endl;
      cout << "7: Add book." << endl;
      cout << "q: quit program." << endl;

      cout << endl << "Please enter option here:  ";
      cin >> choice;
    }
  }
  return 0;
}
