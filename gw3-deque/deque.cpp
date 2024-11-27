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
