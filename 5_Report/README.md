                                                                      CHASER_GAME

REQUIREMENTS:
HEADER FILES : #include <conio.h> #include <stdio.h> #include <stdlib.h> #include <unistd.h>
TOOLS : MS EXCEL, MS WORD, VISUAL STUDIO CODE.

DESIGN:
![CHASER_FLOWCHART](https://user-images.githubusercontent.com/94359739/143215890-d34b8ea3-f202-4e98-92e8-199aad9d5e6c.png)

IMPLEMENTATION:
// CHASER_GAME
	#include <conio.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	
	int i, j, height = 20, width = 20;
	int gameover, score;
	int x, y, cherryx, fruity, flag;
	
	
	void setup() // Function to generate the fruit
	// within the boundary
	{
	gameover = 0;
	
	
	x = height / 2; // Stores height and width
	y = width / 2;
	label1:
	cherryx = rand() % 20;
	if (cherryx == 0)
	goto label1;
	label2:
	fruity = rand() % 20;
	if (fruity == 0)
	goto label2;
	score = 0;
	}
	
	
	void draw() // Function to draw the boundaries
	{
	system("cls");
	for (i = 0; i < height; i++) {
	for (j = 0; j < width; j++) {
	if (i == 0 || i == width - 1
	|| j == 0
	|| j == height - 1) {
	printf("#");
	}
	else {
	if (i == x && j == y)
	printf("0");
	else if (i == cherryx
	&& j == fruity)
	printf("*");
	else
	printf(" ");
	}
	}
	printf("\n");
	}
	
	
	
	printf("score = %d", score); // Print the score after the game ends
	printf("\n");
	printf("press X to quit the game");
	}
	
	
	void input() // Function to take the input
	{
	if (kbhit()) {
	switch (getch()) {
	case 'M':
	flag = 1;
	break;
	case 'O':
	flag = 2;
	break;
	case 'V':
	flag = 3;
	break;
	case 'E':
	flag = 4;
	break;
	case 'x':
	gameover = 1;
	break;
	}
	}
	}
	
	
	
	void logic() // Function for the logic behind each moment
	{
	sleep(0.01);
	switch (flag) {
	case 1:
	y--;
	break;
	case 2:
	x++;
	break;
	case 3:
	y++;
	break;
	case 4:
	x--;
	break;
	default:
	break;
	}
	
	
	if (x < 0 || x > height // If the game is over
	|| y < 0 || y > width)
	gameover = 1;
	
	
	
	if (x == cherryx && y == fruity) { // If Chaser reaches the fruit then update the score
	label3:
	cherryx = rand() % 20;
	if (cherryx == 0)
	goto label3;
	
	
	label4: // After eating the above fruit // generate new fruit
	fruity = rand() % 20;
	if (fruity == 0)
	goto label4;
	score += 10;
	}
	}
	
	
	void main() // Driver Code
	{
	int m, n;
	
	
	setup(); // Generate boundary 
	
	
	while (!gameover) { // Until the game is over
	
	// Function Call
	draw();
	input();
	logic();
	}
	}


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

OUTPUT:
![chaser_game](https://user-images.githubusercontent.com/94359739/143216261-979b980c-8ac1-49c3-83ce-e6c793dc93f1.jpg)
