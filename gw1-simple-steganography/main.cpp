
#include <iostream>
#include "steganography.h"

using namespace std;

void menu(steganography& steg);

const string INPUTPATH = "sampleinputs/";
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
  char choice = 0;
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
	  
	case 'q':
	  cout << "quitting..." << endl;
	  break;
	  
	case 'p':
	  cout << "Please enter a name for the image file." << endl;
	  cin >> outputImage;
	  cout << "Making file " << outputImage << '.' << endl;
	  steg.printImage(OUTPUTPATH + outputImage);
	  cout << "File " << outputImage << " created." << endl;
	  break;

	case 'r':
	  cout << "Please enter a name for the file with the message." << endl;
	  cin >> inputCipher;
	  cout << "loading message..." << endl;
	  steg.readCipherText(INPUTPATH + inputCipher);
	  cout << inputCipher << "is loaded." << endl;
	  break;
	  
	case 'o':
	  cout << "Please enter a name for the message file." << endl;
	  cin >> outputCipher;
	  cout << "creating " << outputCipher << "..." << endl;
	  
	}
    }
}

