# ShapeCalculator-with-unit-tests

## A program built to mainly practice to write unit testing.
The program is to be executed through the makefile. Before runnig it you might need to change the directory folders to match your computer.
To build the program first enter "mingw-32 make" into the terminal, this will build a debug version of the program. 
To run it. Enter .\InlamningCI-debug.exe" into the terminal.
To build the "release" version, instead enter "mingw-32 make DEBUG=0" and then run ".\InlamningCI.exe"

It consists of three parts:

**A circumference and area calculator for shapes**

**A calculator**

**A Rock, paper, scissors game**




### Circumference and area calculator:

The program will promt you to choose a shape to calculate on and input one, two or three parameters in cm depending on the shape. 
It will use those parameters to calculate the circumference and area of the chosen shape and print the result to the terminal. 
Error handling is implemented in alla menus and inputs. It handles wrongfull input and issues of overflow. 



### Calculator
A basic calculator that lets the user choose which operator to use and input operands. It will calculate the result and print it to the terminal.
As above,  error handling is implemented in alla menus and inputs. It handles wrongfull input and issues of overflow. 

### Rock, Paper, Scissors game
A version of the classic game. The user types in which of the three options he or she chooses, then the computer will choose one option on random. There after it will be detrmined if the user won, lost or if it is a tie. The date of the game and the result will be printed to a binary file. 
When the user decides to exit the game, all results of games played will be read from the binary file and the total win percentage will be calculated and printed to te terminal.


### Unit Tests
There are three suites of unit tests, one for each part of the program of a total of 22 tests. 
The google test framework is used and follow the ARRANGE-ACT-ASSRET method. 
The unit tests focuses on testing the logic of the shapes, the calculator and game mechanics. 

To run the unit tests enter "mingw-32 make test" into the terminal and the test suits will run. 
