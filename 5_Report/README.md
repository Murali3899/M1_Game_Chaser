CHASER_GAME

Functionalities of this game:
The chaser is represented with a 0 (zero) symbol.
The fruit is represented with an *(asterisk) symbol.
The chaser can move in any direction according to the user with the help of the keyboard (M, O, V, E keys).  
When the chaser eats a fruit the score will increase by 10 points.
The fruit will generate automatically within the boundaries.
Whenever the chaser will touch the boundary the game is over.

Steps to create this game:
There will be four user-defined functions.
Build a boundary within which the game will be played.
The fruits are generated randomly.
Then increase the score whenever the chaser eats a fruit.

The user-defined functions created in this program are given below:
Draw(): This function creates the boundary in which the game will be played.
Setup(): This function will set the position of the fruit within the boundary.
Input(): This function will take the input from the keyboard.
Logic(): This function will set the movement of the chaser.

Built-in functions used:
kbhit(): This function in C is used to determine if a key has been pressed or not. To use this function in a program include the header file conio.h. If a key has been pressed, then it returns a non-zero value otherwise it returns zero.
rand(): The rand() function is declared in stdlib.h. It returns a random integer value every time it is called.

Header files and variables:
The header files and variables used in this program are:
Here include the <unistd.h> header file for the sleep() function.

Draw(): This function is responsible to build the boundary within which the game will be played.
setup(): This function is used to write the code to generate the fruit within the boundary using rand() function.
Using rand()%20 because the size of the boundary is length = 20 and width = 20 so the fruit will generate within the boundary.

Input(): In this function, the programmer writes the code to take the input from the keyboard (M, O, V, E, X keys).
logic(): Here, write all the logic for this program like for the movement of the chaser, for increasing the score, when the chaser will touch the boundary the game will be over, to exit the game and the random generation of the fruit once the chaser will eat the fruit.
sleep(): This function in C is a function that delays the program execution for the given number of seconds. In this code sleep() is used to slow down the movement of the chaser so it will be easy for the user to play.
main(): From the main() function the execution of the program starts. It calls all the functions.
