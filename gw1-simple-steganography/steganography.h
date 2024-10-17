/**
 * @file steganography.h
 * @author Jose Hipolito
 * @date 2024-10-16
 * @brief header file for steganography class
 * 
 * creates a steganography object that encodes and decodes text imbedded in pmm images
 */

#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

/**
 * Contains variables and methods to encode, decode, read and print text from/to an image.
 *
 * @class steganography{ steganography.h "gw1-simple-steganography/steganography.h"
 * @brief Steganography class
 *
 */
class steganography{
 private:
  string magicNumber;
  int width;
  int height;
  int maxColor;
  vector<int> colorData;
  string cipherText;

/**
 * helper method that returns the nth bit from a character
 *
 * @param char cipherChar character being manipulated
 * @param int n the amount of bits being shifted
 * @pre 
 * @return int bit value
 * @post 
 * 
 */
  int getNthBit(char cipherChar, int n);


/**
 * gets a power of two
 *
 * @param int n the exponent
 * @pre 
 * @return int a positive nth power of 2
 * @post 
 * 
 */
  int getTwoPower(int n);

 public:

/**
 * Reads image data and  stores it in member variables.
 *
 * @param string fileName name of the file the image is stored
 * @pre 
 * @return void 
 * @post image data is stored in member variables
 * 
 */
  void readImage(string fileName);

/**
 * takes the data from the member variables and prints them in an output file.
 *
 * @param string fileName name of output image file
 * @pre image data is loaded
 * @return void 
 * @post creates a new output file
 * 
 */
  void printImage(string fileName);

/**
 * reads cipher text and saves it in the cipherText member variable
 *
 * @param string fileName file containing text
 * @pre 
 * @return void 
 * @post text is saved in sipherText variable
 * 
 */
  void readCipherText(string fileName);

/**
 * writes cipherText into an output file
 *
 * @param string fileName name of the output file
 * @pre text is in cipherText file
 * @return void 
 * @post output file is created
 * 
 */
  void printCipherText(string fileName);

/**
 * zeros out the least significant bit of each color value in colorData
 *
 * @pre there are Values in colorData
 * @return void 
 * @post the least significant bit of all color data is 0
 * 
 */
  void cleanImage();

/**
 * stores data from cipherText into the colorData
 *
 * @pre both image data and text data are loaded
 * @return void 
 * @post text is encoded into color data
 * 
 */
  void encipher();

/**
 * stores encoded message from the image to the cipherText variable
 *
 * @pre image is loaded
 * @return void 
 * @post text is added to cipherText
 * 
 */
  void decipher();
};
#endif
