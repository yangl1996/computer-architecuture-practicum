// quickSort.c
#include <stdio.h>
#include <stdlib.h>

void quickSort( int[], int, int);
int partition( int[], int, int);
int testlist[1000000];

void main() 
{
	FILE *fp;
	fp = fopen("input.txt", "r");
	int i;
	for (i = 0; i < 1000000; i++) {
		fscanf(fp, "%d\n", testlist + i);
	}

	quickSort(testlist , 0, 1000000);

	fclose(fp);

}



void quickSort( int a[], int l, int r)
{
   int j;

   if( l < r ) 
   {
   	// divide and conquer
        j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }
	
}



int partition( int a[], int l, int r) {
   int pivot, i, j, t;
   pivot = a[l];
   i = l; j = r+1;
		
   while( 1)
   {
   	do ++i; while( a[i] <= pivot && i <= r );
   	do --j; while( a[j] > pivot );
   	if( i >= j ) break;
   	t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}

