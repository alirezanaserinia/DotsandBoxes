
#include <stdio.h>
#include "stdafx.h"
/*This function prints arrays*/

void print(char a[11][16], int m, int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			printf("%c", a[i][j]);
		printf("\n");
	}
}
