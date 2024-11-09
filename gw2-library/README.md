Welcome to the library. Book information can be can be loaded by file in the following format:


File Format:
Title
Author
ISBN
Pages Price Year

example:
The Art of War
Sun Tzu
9781599869773
68 4.99 2007

note: this doesn't seem to be showing up right on github. please download the repository to see the file format.

The program gives a menu to choose from a list of options.
1: Load a library from a file.
2: Write loaded library to a file
3: Prints library on screen
4: Search books by a certain author
5: Search books with a given title
6: Delete a book from the database
7: Add a book to the database
q: Quits program.

The biggest problem I faced is getting file reads to work, especially since a new empty line always gets added at the end. Besides this, I didn't have many problems.