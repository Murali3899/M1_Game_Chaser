
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int i, j, height = 20, width = 20;
int gameover, score;
int x, y, cherryx, fruity, flag;


void setup()                                 // Function to generate the fruit

{
	gameover = 0;

	// Stores height and width
	x = height / 2;
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

void draw()                // Function to draw the boundaries

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

	// Print the score after the
	// game ends
	printf("score = %d", score);
	printf("\n");
	printf("press X to quit the game");
}

void input()
{
	if (kbhit()) {
		switch (getch()) {
		case 'o':
			flag = 1;
			break;
		case 'v':
			flag = 2;
			break;
		case 'e':
			flag = 3;
			break;
		case 'm':
			flag = 4;
			break;
		case 'x':
			gameover = 1;
			break;
		}
	}
}



void logic()           // Function for the logic behind each movement
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

	
	if (x < 0 || x > height        // If the game is over
		|| y < 0 || y > width)
		gameover = 1;

	// If chaser reaches the fruit
	// then update the score
	if (x == cherryx && y == fruity) {
	label3:
		cherryx = rand() % 20;
		if (cherryx == 0)
			goto label3;

	// After eating the above fruit
	// generate new fruit
	label4:
		fruity = rand() % 20;
		if (fruity == 0)
			goto label4;
		score += 10;
	}
}

// Driver Code
void main()
{
	int m, n;

	
	setup();                 // Generate boundary

	
	while (!gameover) {      // Until the game is over

		
		draw();                // Function Call
		input();
		logic();
	}
}

