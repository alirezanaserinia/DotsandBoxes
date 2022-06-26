#include <stdio.h>
#include "stdafx.h"

/*This function adds user-defined lines in play*/

char line_adder(char a[11][16], int &counter1, int &Player_A, int &Player_B) {
	/*This section generally takes coordinates from the user and implements them*/
	int x, y, z;
	/*for declare the turn*/
	if (counter1 % 2 == 0) {
		printf("Player A. please enter coordinates :\n");
		scanf("%d %d %d", &x, &y, &z);
	}
	else if (counter1 % 2 == 1) {
		printf("Player B. please enter coordinates :\n");
		scanf("%d %d %d", &x, &y, &z);
	}
	/* check and fix input errors*/
	while (1) {
		if (x == 0 && a[(y - 1) * 2][((z - 1) * 3) + 1] == '-') {
			printf("These coordinates have already been filled \n");
			printf("Please enter new coordinates :\n");
			scanf("%d %d %d", &x, &y, &z);
		}

		if (x == 1 && a[((y - 1) * 2) + 1][(z - 1) * 3] == '|') {
			printf("These coordinates have already been filled \n");
			printf("Please enter new coordinates :\n");
			scanf("%d %d %d", &x, &y, &z);
		}
		if ((x < 0) || (x > 1) || (y < 1) || (y > 6) || (z < 1) || (z > 6)) {
			printf("It's wrong!!\n");
			printf("Please enter correct coordinates :\n");
			scanf("%d %d %d", &x, &y, &z);
		}
		else
			break;
	}
	/*for horizontal lines*/
	if (x == 0) {
		while (1) {
			if (z == 6) {
				printf("coordinates of z is wrong!!\n");
				printf("please choice coordinates between 1 and 5 :\n");
				scanf("%d %d %d", &x, &y, &z);
			}
			else
				break;
		}
		a[(y - 1) * 2][((z - 1) * 3) + 1] = '-';
		a[(y - 1) * 2][((z - 1) * 3) + 2] = '-';
		/*for win one person and his award*/
		if ((a[((y - 1) * 2) + 1][((z - 1) * 3)] == '|') && (a[((y - 1) * 2) + 2][((z - 1) * 3) + 1] == '-') && (a[((y - 1) * 2) + 1][((z - 1) * 3) + 3] == '|')) {

			if (counter1 % 2 == 0) {
				a[((y - 1) * 2) + 1][((z - 1) * 3) + 1] = 'A';
				counter1--;
			}
			else if (counter1 % 2 == 1) {
				a[((y - 1) * 2) + 1][((z - 1) * 3) + 1] = 'B';
				counter1--;
			}
		}
		if ((a[((y - 1) * 2) - 1][((z - 1) * 3)] == '|') && (a[((y - 1) * 2) - 2][((z - 1) * 3) + 1] == '-') && (a[((y - 1) * 2) - 1][((z - 1) * 3) + 3] == '|')) {
			if (counter1 % 2 == 0) {
				a[((y - 1) * 2) - 1][((z - 1) * 3) + 1] = 'A';
				counter1--;
			}
			else if (counter1 % 2 == 1) {
				a[((y - 1) * 2) - 1][((z - 1) * 3) + 1] = 'B';
				counter1--;
			}
		}
	}
	/*special mode of win*/
	if ((a[((y - 1) * 2) + 1][((z - 1) * 3)] == '|') && (a[((y - 1) * 2) + 2][((z - 1) * 3) + 1] == '-') && (a[((y - 1) * 2) + 1][((z - 1) * 3) + 3] == '|') && (a[((y - 1) * 2) - 1][((z - 1) * 3)] == '|') && (a[((y - 1) * 2) - 2][((z - 1) * 3) + 1] == '-') && (a[((y - 1) * 2) - 1][((z - 1) * 3) + 3] == '|')) {
		if (counter1 % 2 == 0) {
			a[((y - 1) * 2) - 1][((z - 1) * 3) + 1] = 'A';
			a[((y - 1) * 2) + 1][((z - 1) * 3) + 1] = 'A';
			counter1--;
		}
		else if (counter1 % 2 == 1) {
			a[((y - 1) * 2) - 1][((z - 1) * 3) + 1] = 'B';
			a[((y - 1) * 2) + 1][((z - 1) * 3) + 1] = 'B';
			counter1--;
		}
	}
	/*for vertical lines*/
	else if (x == 1) {
		while (1) {
			if (y == 6) {
				printf("coordinates of y is wrong!!\n");
				printf("please choice coordinates between 1 and 5 :\n");
				scanf("%d %d %d", &x, &y, &z);
			}
			else
				break;
		}
		a[((y - 1) * 2) + 1][(z - 1) * 3] = '|';
		/*for win one person and his award*/
		if ((a[((y - 1) * 2) + 2][((z - 1) * 3) - 1] == '-') && (a[((y - 1) * 2) + 1][((z - 1) * 3) - 3] == '|') && (a[((y - 1) * 2)][((z - 1) * 3) - 1] == '-')) {
			if (counter1 % 2 == 0) {
				a[((y - 1) * 2) + 1][((z - 1) * 3) - 2] = 'A';
				counter1--;
			}
			else if (counter1 % 2 == 1) {
				a[((y - 1) * 2) + 1][((z - 1) * 3) - 2] = 'B';
				counter1--;
			}
		}
		if ((a[((y - 1) * 2) + 2][((z - 1) * 3) + 1] == '-') && (a[((y - 1) * 2) + 1][((z - 1) * 3) + 3] == '|') && (a[((y - 1) * 2)][((z - 1) * 3) + 1] == '-')) {
			if (counter1 % 2 == 0) {
				a[((y - 1) * 2) + 1][((z - 1) * 3) + 1] = 'A';
				counter1--;
			}
			else if (counter1 % 2 == 1) {
				a[((y - 1) * 2) + 1][((z - 1) * 3) + 1] = 'B';
				counter1--;
			}
		}
		/*special mode of win*/
		if ((a[((y - 1) * 2) + 2][((z - 1) * 3) - 1] == '-') && (a[((y - 1) * 2) + 1][((z - 1) * 3) - 3] == '|') && (a[((y - 1) * 2)][((z - 1) * 3) - 1] == '-') && (a[((y - 1) * 2) + 2][((z - 1) * 3) + 1] == '-') && (a[((y - 1) * 2) + 1][((z - 1) * 3) + 3] == '|') && (a[((y - 1) * 2)][((z - 1) * 3) + 1] == '-')) {
			if (counter1 % 2 == 0) {
				a[((y - 1) * 2) + 1][((z - 1) * 3) - 2] = 'A';
				a[((y - 1) * 2) + 1][((z - 1) * 3) + 1] = 'A';
				counter1--;
			}
			else if (counter1 % 2 == 1) {
				a[((y - 1) * 2) + 1][((z - 1) * 3) - 2] = 'B';
				a[((y - 1) * 2) + 1][((z - 1) * 3) + 1] = 'B';
				counter1--;
			}
		}
	}
	counter1++;

	return a[11][16];
}