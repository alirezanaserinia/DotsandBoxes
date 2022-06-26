// noqte_bazi.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include "stdafx.h"
#include "Header.h"

int main() {
	char a[11][16];
	int Player_A = 0, Player_B = 0, counter1 = 0, sum = 0;
	play_map(a, 11, 16);
	while (sum != 25) {
		Player_A = 0;
		Player_B = 0;
		a[11][16] = line_adder(a, counter1, Player_A, Player_B);
		print(a, 11, 16);
		/*for show result and announcing the winner of the game*/
		for (int i = 0; i<11; i++) {
			for (int j = 0; j<16; j++) {
				if (a[i][j] == 'A') {
					Player_A++;
				}
				else if (a[i][j] == 'B') {
					Player_B++;
				}
			}
		}
		sum = Player_A + Player_B;
	}
	printf("Player A: %d\n", Player_A);
	printf("Player B: %d\n", Player_B);
	if (Player_A > Player_B)
		printf("Player A won the game !\n");
	else
		printf("Player B won the game !\n");
	return 0;
}

