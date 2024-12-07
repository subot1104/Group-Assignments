/**
 * @file deque.h
 * @author Jose Hipolito
 * @date 2024-12-06
 * @brief deque clas
 * 
 * contains method and members for deque classs
 */

#ifndef DEQUE_H
#define DEQUE_H

#include <string>


/**
 * contains methods and definitions for deque class
 *
 * @class Deque deque.h "gw3-deque/deque.h"
 * @brief deque class
 *
 */
class Deque {
 private:
  std::string **blockmap;
  const int BLOCK_SIZE = 8;
  int mapSize;
  int dequeSize;
  int frontBlock;
  int frontElement;
  int backBlock;
  int backElement;

/**
 * resizes deque, adding 1 block to both ends and shifting values accordingly
 *
 * @pre 
 * @return void 
 * @post adds 2 blocks
 * 
 */
  void resizeDeque();
 public:

/**
 * constuctor for deque
 *
 * @pre 
 * @post creates deque object
 * 
 */
  Deque();

/**
 * destuctor for deque
 *
 * @pre 
 * @post destroys deque object
 * 
 */
  ~Deque();

/**
 * pushes data to the front of the deque and resizes when needed
 *
 * @param std::string newData data being added
 * @pre 
 * @return void 
 * @post new data at front of deque
 * 
 */
  void push_front(std::string newData);

/**
 * makes front data previous to funciton call become unaccessable
 *
 * @pre 
 * @return void 
 * @post shifts front element to the next element
 * 
 */
  void pop_front();

/**
 * adds data to the back of the deck, reallocating memory when neccessary
 *
 * @param std::string newData data being added
 * @pre 
 * @return void 
 * @post new data is added
 * 
 */
  void push_back(std::string newData);

/**
 * shift back forwards, making the previous back unaccessable
 *
 * @pre 
 * @return void 
 * @post new back
 * 
 */
  void pop_back();

/**
 * returns the current front of deque
 *
 * @pre 
 * @return std::string returns the front of the deque
 * @post 
 * 
 */
  std::string front();

/**
 * returns the current back of the deque
 *
 * @pre 
 * @return std::string back of deque
 * @post 
 * 
 */
  std::string back();

/**
 * checks if the deque is empty
 *
 * @pre 
 * @return bool returns either true or false
 * @post 
 * 
 */
  bool empty();

/**
 * returns current size of deque
 *
 * @pre 
 * @return int deque size
 * @post 
 * 
 */
  int size();

/**
 * impliments interface commonly used in arrays
 *
 * @param int index index of the deque
 * @pre 
 * @return std::string returns what is stored in that location
 * @post 
 * 
 */
  std::string operator[](int index);
};
#endif
