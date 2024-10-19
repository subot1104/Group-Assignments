There is no partner for this project sadly.

How to use:
Drop any P3 .ppm file and messages in the inputs file.

Open the program and tell the program to open the desired image from the inputs file.

Enter commands.

List of commands:

h: -lists all commands

p: -prompts user to enter output file name
   -stores image into the output file in outputs folder
   
r: -prompts user to enter a message file
   -stores text in the program

o: -prompts user to enter a file name for the text output
   -stores the text in an output file in the output folder

e: -clears 1st bit of all the color data in the image
   -stores text in the image

d: -pulls text from image

q: -quits program

   note: This program can only handle 1 image. It needs to restart every time you want to use another image.

This program was designed to give the user as much control as possible while still having usablity.

There were two major issues when creating this project

1. Figuring out how to read and write in the ppm format

While the format was simple, I initailly overcomplicated it by taking into account whitespace when reading when all I needed was extraction operators.

2. enciphering and deciphering

It was unsual for me to manipulate data in this way. Running into wrong numbers and symbols was the difficult part, but I did have a moment of realization when reading the
ascii table and finding that 0 was null, which was what the output was trying to print. luckily I was easily able to put a check for a null symbol.

Also the files in the inputs and outputs folders are there just as placeholders so that the folders will show up in github since they are required for the program to work
properly. Feel free to remove them. They are small files anyways and hold no substantial significance.