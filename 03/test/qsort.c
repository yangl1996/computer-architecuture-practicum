#include<stdio.h>
#include<stdlib.h>
#define SIZE 15
int a[SIZE];
int partition(int l, int r);
void quicksort(int l,int r);
int main(){
	//struct timeval start, end;
	for(int i = 0;i < SIZE;i++){
		scanf("%d",&a[i]);
	}
	//gettimeofday(&start, NULL);
	quicksort(0, SIZE-1);
	//gettimeofday(&end, NULL);
	for(int i = 0;i < SIZE; i++)
	 	printf("%d ",a[i]);
	printf("\n");
	//int timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec -start.tv_usec;
        //printf("time: %d us\n", timeuse);
	return 0;
}
void quicksort(int l,int r){
	int pos;
	if(l < r){
		pos = partition(l,r);
		quicksort(l,pos-1);
		quicksort(pos+1,r);
	}
}
int partition(int l, int r){
	int i, j, tmp;
	tmp = a[l];
	i = l;
	j = r;
	while(i < j){
		while(i < j && tmp < a[j])
			j--;
		if(i < j)
			a[i++] = a[j];
		while(i < j && tmp > a[i])
			i++;
		if(i < j)
			a[j--] = a[i];
	}
	a[i] = tmp;
	return i;
}
