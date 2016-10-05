// quickSort.c
#include <stdio.h>
#include <stdlib.h>

void quickSort( int[], int, int);
int partition( int[], int, int);
int m1[1000][1000];
int m2[1000][1000];
int m3[1000][1000] = {0};

void main() 
{
	FILE *fp;
	fp = fopen("input.txt", "r");
	int i, j;
	for (i = 0; i < 1000; i++) {
		for (j = 0; j < 1000; j++) {
			fscanf(fp, "%d\n", &(m1[i][j]));
		}
	}
	fclose(fp);

	fp = fopen("input.txt", "r");
	for (i = 0; i < 1000; i++) {
		for (j = 0; j < 1000; j++) {
			fscanf(fp, "%d\n", &(m2[i][j]));
		}
	}
	fclose(fp);
	int k = 0;
	for (i = 0; i < 1000; i++) {
		for (j = 0; j < 1000; j++) {
			for (k = 0; k < 1000; k++) {
				m3[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}



