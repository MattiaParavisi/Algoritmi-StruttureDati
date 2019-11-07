#include <stdio.h>

void stampa(int a[],int lung ){
	int i;
	for(i=0; i<lung; i++){
		printf("%d ",a[i]);	
	}
	return;
}

void scambia(int a[],int i,int j){
	int temp;
	temp = *(a+i);
	*(a+i) = *(a+j);
	*(a+j) = temp;
	return;
}

void selectionsort(int a[],int n ){
	int max, i, imax=0;
	max = *a; 
	if(n==1){
		scambia(a,0,n-1);
		return;	
	}
	for(i=0; i<n; i++){
		if(*(a+i)>max){
			imax = i; 
			max = *(a+i);
		}
	}
	scambia(a,imax,n-1);
	selectionsort(a, n-1);
}

void merge(int a[], int sx, int dx, int m ){
	int lentot, i=0, j=0; 
	lentot = sx + dx;
	int x[lentot];
	if(a[i]<a[m]){
		x[j] = a[i];
	}
}

void mergesort(int a[],int sx,int dx ){
	int m;
	if(sx-dx == 1){
		return;
	}
	m = (sx+dx)/2;
	mergesort(a, sx, m );
	merge(a, 
	mergesort(a, m, dx);
	merge(a, 
}


int main(void){
	int a[] = {5, 1, 0, 3, 2, 4};
	printf("pre-sorting: ");
	stampa(a, 6);
	printf("\npost-sorting: ");
	selectionsort(a, 6);
	stampa(a,6);
	printf("\n");
	return 0;
}
