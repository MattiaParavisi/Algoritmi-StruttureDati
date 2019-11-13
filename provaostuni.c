#include <stdio.h>

int main(void){
	int n, max=0,newmax=0,nbackup,iciclo;
	scanf("%d", &n);
	int a[n], i, input;
	for(i=0;i<n;i++){
		scanf("%d", &input);
		a[i]=input;
	}
	for(i=0;i<n;i++){
		max += a[i]; 
	}
	nbackup = n;
	
	while(n>0){
		for(i=0;i<n-1;i++){
			newmax += a[i];
		}
		if(newmax>max){
			max = newmax;
		}
		newmax=0;
		n--;
	}
	newmax=0;
	n = nbackup;
	iciclo = 0;
	while(iciclo<n){
		for(i=iciclo;i<n;i++){
			newmax += a[i];
		}
		if(newmax>max){
			max = newmax;
		}
		newmax=0;
		iciclo++;
	}
	newmax = 0;
	iciclo = 1;
	nbackup = n-1;
	while(iciclo<nbackup){
		for(i=iciclo; i<nbackup; i++){
			newmax += a[i];
		}
		if(newmax>max){
			max = newmax;
		}
		iciclo++;
		nbackup--;
		newmax=0;
	}
	printf("%d",max);
}
