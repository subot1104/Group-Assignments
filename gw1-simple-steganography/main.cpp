/**
 * @file main.cpp
 * @author Jose Hipolito
 * @date 2024-10-18
 * @brief simple steganography
 * 
 * program that allows the user to encipher, decipher, read, and print messages to and from an image
 */


#include <iostream>
#include "steganography.h"

using namespace std;


/**
 * interface that allows the user to manipulate images and messages
 *
 * @param steganography& steg steganography object
 * @pre "sampleinputs" and "outputs" are folders in this directory. A preferably plain image is entered inputted
 * @return void 
 * @post carries operations that the user wants based on commands
 * 
 */
void menu(steganography& steg);

const string INPUTPATH = "inputs/";
const string OUTPUTPATH = "outputs/";

int main() {
  steganography steg;
  string inFile;
  
  cout << "Welcome to simple steganography." << endl;
  cout << "Please enter an image in a .ppm format that is located in the sampleinputs folder." << endl;
  cin >> inFile;
  cout << "Loading file..." << endl;
  steg.readImage(INPUTPATH + inFile);
  menu(steg);
      
  return 0;
}

void menu(steganography& steg)
{
  char choice = 0;//initialize choice as null character
  string inputCipher;
  string outputCipher;
  string outputImage;

  while (choice != 'q')
    {  
      cout << endl << "What would you like to do? (you can type h for list of commands)" << endl;
      
      cin >> choice;
      
      switch (choice)
	{
	case 'h':
	  cout << endl << "Heres a list of commands:" << endl;
	  cout << "p: prints image into outputs folder." << endl;
	  cout << "r: reads cipher message." << endl;
	  cout << "o: prints cipher message into outputs folder." << endl;
	  cout << "e: enciphers text into image." << endl;
	  cout << "d: deciphers text from image." << endl;
	  cout << "q: quits program." << endl;
	  break;

	  //refer to the 'h' case for simple explanation of each command
	case 'q':
	  cout << endl << "quitting..." << endl;
	  break;
	  
	case 'p':
	  cout << endl << "Please enter a name for the image file." << endl;
	  cin >> outputImage;
	  cout << "Making file " << outputImage << '.' << endl;
	  steg.printImage(OUTPUTPATH + outputImage);
	  cout << "File " << outputImage << " created." << endl;
	  break;

	case 'r':
	  cout << endl << "Please enter a name for the file with the message." << endl;
	  cin >> inputCipher;
	  cout << "loading message..." << endl;
	  steg.readCipherText(INPUTPATH + inputCipher);
	  cout << inputCipher << " is loaded." << endl;
	  break;
	  
	case 'o':
	  cout << endl << "Please enter a name for the message file." << endl;
	  cin >> outputCipher;
	  cout << "creating " << outputCipher << "..." << endl;
	  steg.printCipherText(OUTPUTPATH + outputCipher);
	  cout << outputCipher << " was created" << endl;
	  break;

	case 'e':
	  cout << endl << "cleaning image..."  << endl;
	  steg.cleanImage();
	  cout << "enciphering message..." << endl;
	  steg.encipher();
	  cout << "message enciphered." << endl;
	  break;
	  
	case 'd':
	  cout << endl << "deciphering message." << endl;
	  steg.decipher();
	  cout << "message deciphered." << endl;
	  break;
	}
    }
}

