/**
 * @file main.cpp
 * @author Jose Hipolito
 * @date 2024-11-08
 * @brief library driver
 * 
 * driver for the library class
 */

#include <iostream>
#include "deque.h"
#include <fstream>

using namespace std;

void load(string filename, Deque &deq);
void save(string filename, Deque &deq);
void print(Deque deq);
void Delete(char dir, Deque &deq);
void add(char dir, Deque &deq, string word);

int main() {
  char choice = 0;
  string filename;
  Deque wordDeq;
  string front;
  string back;
  string temp;
  
  while(choice != '8'){
    switch(choice){
    case '1': //load
      cout << endl << "Please enter file name here:  ";
      cin >> filename;
      cout << "loading file..." << endl;
      load(filename, wordDeq);
      cout << "file loaded. Please press enter to continue." << endl;
      cin.ignore();
      cin.get();
      choice = 0;
      break;
    case '2': //save
      cout << endl << "Please enter file name here:  ";
      cin >> filename;
      cout << "writing file..." << endl;
      save(filename, wordDeq);
      cout << "File written. Please press enter to continue." << endl;
      cin.ignore();
      cin.get();
      choice = 0;
      break;
    case '3': //print
      cout << endl;
      print(wordDeq);
      cout << endl << "Please press enter to continue." << endl;
      cin.ignore();
      cin.get();
      choice = 0;
      break;
    case '4': //print front
      cout << endl << "Here's the front of the deque:  ";
      front = wordDeq.front();
      cout << front << endl;
      cout << endl << "Please press enter to continue." << endl;
      cin.ignore();
      cin.get();
      choice = 0;      
      break;
    case '5': //print back
      cout << endl << "Here's the back of the deque:  ";
      back = wordDeq.back();
      cout << back << endl;
      cout << endl << "Please press enter to continue." << endl;
      cin.ignore();
      cin.get();
      choice = 0;
      break;
    case '6': //Delete
      cout << "Please enter which place to delete:" << endl << endl;
      cout << "1:front" << endl;
      cout << "2:back" << endl;
      cout << "Enter choice here:  ";
      cin >> choice;
      cin.ignore();
      Delete(choice, wordDeq);
      cout << endl << "Please press enter to continue." << endl;
      cin.ignore();
      cin.get();
      choice = 0;
      break;
    case '7': //add
      cout << "Please enter a word to add." << endl;
      cin >> temp;
      cin.ignore();
      cout << "Please enter a direction:" << endl;
      cout << endl << "1:front" << endl;
      cout << "2:back" << endl;
      cin >> choice;
      add(choice, wordDeq, temp);
      cout << endl << "Please press enter to continue." << endl;
      cin.ignore();
      cin.get();
      choice = 0;
      break;
    case '8':
      cout << "Bye" << endl;
      break;
      
    default:
      cout << "Welcome to the word deque" << endl;
      cout << "1: Load words from file." << endl;
      cout << "2: Write words into file." << endl;
      cout << "3: Print deque." << endl;
      cout << "4: Print the front of the deque." << endl;
      cout << "5: Print the back of the deque." << endl;
      cout << "6: Delete a word." << endl;
      cout << "7: Add word." << endl;
      cout << "8: quit program." << endl;

      cout << endl << "Please enter option here:  ";
      cin >> choice;
    }
  }
  return 0;
}

void load(string filename, Deque &deq){
  ifstream lddeq;
  lddeq.open(filename);
  string temp;

  while(lddeq >> temp){
    deq.push_back(temp);
  }

  lddeq.close();
}

void save(string filename, Deque &deq){
  ofstream wrdeq;
  wrdeq.open(filename);
  string temp;
  
  for(int i = 0; i < deq.size(); i++){
    temp = deq[i];
    wrdeq << temp << endl;
  }
  
  wrdeq.close();
}

void print(Deque deq){
  int count = 0;

  for(int i = 0; i < deq.size(); i++){
    cout << deq[i] << ' ';
    count++;
    
    if(count == 8){
      cout << endl;
      count = 0;
    }
  }
}

void add(char dir, Deque &deq, string word){
  if(dir == '1')
    deq.push_front(word);
  else if(dir == '2')
    deq.push_back(word);
  else{
    char newChoice;
    cout << "Please enter the following:" << endl << endl;;
    cout << "1: Add word to front of deque" << endl;
    cout << "2: Add word to back of deque" << endl;
    cin >> newChoice;
    add(newChoice, deq, word);
  }
}
void Delete(char dir, Deque &deq){
  if(dir == '1')
    deq.pop_front();
  else if(dir == '2')
    deq.pop_back();
  else{
    char newChoice;
    cout << "Please enter the following:" << endl << endl;;
    cout << "1: Delete a word at the front of deque" << endl;
    cout << "2: Delete a word at the back of deque" << endl;
    cin >> newChoice;
    Delete(newChoice, deq);
  }
}
