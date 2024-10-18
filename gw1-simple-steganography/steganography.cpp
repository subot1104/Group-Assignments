/**
 * @file steganography.cpp
 * @author Jose Hipolito
 * @date 2024-10-16
 * @brief steganography method definitions
 * 
 * contains method definitions for steganography class
 */

#include "steganography.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int steganography::getNthBit(char cipherChar, int n)
{
  int bit;
  bit = (int(cipherChar) >> n) % 2; //calculates bit being read
  return bit;
}

void steganography::readImage(string fileName)
{
  //input file stream
  int pixelCount;
  ifstream image;
  image.open(fileName);

  //header
  image >> magicNumber;
  image >> width >> height;
  image >> maxColor;
  pixelCount = width * height;
  
  //colordata
  colorData.reserve(3 * pixelCount);//rgb * pixel count
  for (int i = 0; i < (3 * pixelCount); i++)
    {
      image >> colorData[i];
    }
  image.close();
}

void steganography::printImage(string fileName)
{
  //output file stream
  int pixelCount = width * height;
  ofstream image;
  image.open(fileName);

  //header
  image << magicNumber << ' ' << endl;
  image << width << ' ' << height << ' ' << endl;
  image << maxColor << ' ';

  //color data
  unsigned int count = 0;//count added to avoid goofy math
  for (int i = 0; i < pixelCount; i++)
    {
      if (count % 4 == 0)//prints endline after 4 pixels
	image << endl;
      image << colorData[count] << ' '
	    << colorData[count + 1] << ' '
	    << colorData[count + 2] << "  ";
      count = count + 3;
    }
  image.close();
}

void steganography::readCipherText(string fileName)
{
  string input;
  
  //input file stream
  ifstream cipher;
  cipher.open(fileName);

  //input
  cipherText = ""; //sets cipherText as an empty string
  while(cipher)
    {
      getline(cipher,input);
      cipherText += input;
    }
  cipher.close();
}

void steganography::printCipherText(string fileName)
{
  //output file stream
  ofstream cipher;
  cipher.open(fileName);

  //output
  cipher << cipherText;
  
  cipher.close();
}

void steganography::cleanImage()
{
  int pixelCount = width * height;
  for (int i = 0; i < 3 * pixelCount; i++)
    {
      colorData[i] = colorData[i] - (colorData[i] % 2); //clears the first digit in binary
    }
}

void steganography::encipher()
{
  unsigned int pixelCount = width * height;
  if (pixelCount * 3 < cipherText.size()* 8)
    {
      cout << "Not enough data to encipher message" << endl;
      return;
    }

  //encipher loop
  unsigned int count = 0;
  for (unsigned int j = 0; j < cipherText.size(); j++)
    {
      for (int i = 0; i < 8; i++)
	{
	  colorData[count] = colorData[count] + (getNthBit(cipherText[j], 7 - i));
	  count++;
	  if (count == colorData.size())
	    return;
	}
    }
}

void steganography::decipher()
{
  cipherText = ""; //initializes cipherText as an empty string
  int pixelCount = width * height;
  char newChar;

  //decipher loop
  int count = 0;
  for (int j = 0; j < (3 * pixelCount) / 8; j++)
    {
      newChar = 0;// initializes the new character as the 0th ascii character
      //decipher character loop
      for (int i = 0; i < 8; i++)
	{
	  newChar = newChar + ((colorData[count] % 2) * getTwoPower(7 - i));
	}
    }
}

int steganography::getTwoPower(int n)
{
  if (n == 0)
    return 1;
  else
    {
      int power = 1;
      for (int i = 1; i <= n; i++)
	power = power * 2;
      return power;
    }
}
