#include "stdafx.h"
#include "Header.h"

/*This function prints play map for user*/
void play_map(char a[11][16], int i, int j) {
	for (i = 0; i < 11; i++) {
		for (j = 0; j < 16; j++) {
			if ((i % 2 == 0) && (j % 3 == 0))
				a[i][j] = '*';
			else
				a[i][j] = ' ';
		}
	}
	print(a, 11, 16);
}