#ifndef DEQUE_H
#define DEQUE_H

#include <string>

const int BLOCK_SIZE = 16;

class Deque {
 private:
  std::string **blockmap;
  int mapSize;
  int dequeSize;
  int frontBlock;
  int frontElement;
  int backBlock;
  int backElement;
  void resizeDeque();
 public:
  Deque();
  ~Deque();
  void push_front(std::string newData);
  void pop_front();
  void push_back(std::string newData);
  void pop_back();
  std::string front();
  std::string back();
  bool empty();
  int size();
  std::string operator[](int index);
};
#endif
