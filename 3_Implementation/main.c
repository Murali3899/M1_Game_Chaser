                                                               // CHASER_GAME
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int i, j, height = 20, width = 20;
int gameover, score;
int x, y, cherryx, fruity, flag;

                                           
void setup()                           // Function to generate the fruit
                                           // within the boundary
{
	gameover = 0;

	                                       
	x = height / 2;                   // Stores height and width
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

                                           
void draw()                        // Function to draw the boundaries
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

	                                              
	                                              
	printf("score = %d", score);                  // Print the score after the game ends
	printf("\n");
	printf("press X to quit the game");
}

                                                
void input()                                   // Function to take the input
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

                                
                                 
void logic()                    // Function for the logic behind each moment
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

                                            	
	if (x < 0 || x > height                   // If the game is over
		|| y < 0 || y > width)
		gameover = 1;

                                          	
                                          	 
	if (x == cherryx && y == fruity) {        // If Chaser reaches the fruit then update the score
	label3:
		cherryx = rand() % 20;
		if (cherryx == 0)
			goto label3;

	                                         
	label4:                                  // After eating the above fruit // generate new fruit
	  fruity = rand() % 20;
		if (fruity == 0)
			goto label4;
		score += 10;
	}
}


void main()                                   // Driver Code
{
	int m, n;

                                          
	setup();                                  // Generate boundary                          
 
	                                        
	while (!gameover) {                      // Until the game is over

		                                       // Function Call
		draw();
		input();
		logic();
	}
}

