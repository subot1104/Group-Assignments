#include "deque.h"

using namespace std;

Deque::Deque(){
  blockmap = NULL;
  mapSize = 0;
  dequeSize = 0;
}

Deque::~Deque(){
  for(int i = 0; i < mapSize ; i++)
    delete[] blockmap[i];
  
  delete[] blockmap;
}

void Deque::resizeDeque(){
  //case1 empty deque
  if(blockmap == NULL){
    mapSize = 3;
    blockmap = new std::string*[mapSize];
    for(int i = 0; i < mapSize; i++)
      blockmap[i] = NULL;
  }
  //case2 deque is initialized
  else{
    mapSize = mapSize + 2;
    std::string **newBlockmap = new std::string*[mapSize];
    for(int i = 0; i < mapSize; i++)
      newBlockmap[i] = NULL;
    for(int i = 0; i < mapSize - 2; i++)
      newBlockmap[i + 1] = blockmap[i];
    frontBlock += 1;

    delete[] blockmap;
    blockmap = newBlockmap;
    //NOTE: allocating new block memory will be handled by push methods
  }
}

std::string Deque::operator[](int index){
  int block;
  int element;

  block = frontBlock + ((front_element + index) / BLOCK_SIZE);
  element (frontElement + index) % BLOCK_SIZE;

  return blockmap[block][element];
}

void Deque::push_front(std::string newData){
  //case 1: empty blockmap
  if(blockmap == NULL){
    resizeDeque();
    frontBlock = 1;
    backBlock = 1
    frontElement = BLOCK_SIZE / 2;
    backElement = BLOCK_SIZE / 2;
    *blockmap[frontBlock] = new std::string[BLOCK_SIZE];
    blockmap[frontBlock][frontElement] = newData;
  }
  //case 2: at the front end of the block
  else if(frontElement - 1 < 0){
    //check if the previous block is initialized
    if(blockmap[frontBlock - 1] == NULL)
      resizeDeque();

    frontBlock = frontBlock - 1;
    frontElement = BLOCK_SIZE - 1;
    blockmap[frontBlock][frontElement] = newData;
  }
  //case 3: in the middle of a block
  else{
    frontElement = frontElement - 1;
    blockmap[frontBlock][frontElement] = newData;
  }
  dequeSize++;
}

void Deque::pop_front(){
  //another case: empty
  if(dequeSize == 0)
    return;
  //case 1: at back end of block
  else if(frontElement == BLOCK_SIZE - 1){
    frontBlock = frontBlock + 1;
    frontElement = 0;
  }
  //case 2: middle of block
  else{
    frontElement = frontElement + 1;
  }
  dequeSize--;
}

void Deque::push_back(int newData){
  //case 1: empty block
  if(blockmap == NULL){
    resizeDeque();
    frontBlock = 1;
    frontElement = BLOCK_SIZE / 2;
    *blockmap[frontBlock] = new std::string[BLOCK_SIZE];
    blockmap[frontBlock][frontElement] = newData;
  }    
  //case 2: at the back end of block
  else if(lastElement == BLOCK_SIZE - 1){
    if(blockmap[backBlock + 1] == NULL)
      resizeDeque();
    backBlock = backBlock + 1;
    backElement = 0;
    blockmap[backBlock][backElement] = newData;
  }
  //case 3: middle of block
  else{
    backElement = backElement + 1;
    blockmap[backBlock][backBlock] = newData;
  }
  dequeSize++;
}

void Deque::pop_back(){
  //another case: empty
  if(dequeSize == 0)
    return;
  //case 1: at the front end of a block
  else if(backElement == 0){
    backBlock = backBlock - 1;
    backElement = BLOCK_SIZE - 1;
  }
  //case 2: middle of block
  else{
    backElement = backElement - 1;
  }
  dequeSize--;
}

bool Deque::empty(){
  if (dequeSize == 0){
    return true;
  }
  else
    return false;
}

int Deque::size(){
  return dequeSize;
}
