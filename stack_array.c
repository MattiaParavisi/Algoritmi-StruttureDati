#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int a[100];
int top = 0;

void make_empty( void ){
	for(int i = 0; i < 100; i++){
		a[i] = 0;
	}
	top = 0;
	return;
}

int is_empty( void ){
	if(a[top] = 0){
		return 1;
	}
	return 0;
}

int topp( void ){
	if(a[top] != 0){
		return a[top];
	}else if(a[top] == 0){
		printf("la pila è vuota");
		exit(0);
	} 	
}

int pop( void ){
int ins;
	if(a[top] != 0){
		ins = a[0];
		a[top] = 0;
		top--;
		return a[top];
	}else if(a[top] == 0){
		printf("la pila è vuota, non posso poppare");
		exit(0);
	} 	
}

void push( int n ){
	if(a[top] != 0){
		top++;
		a[top] = n;
	}else{
		a[top] = n;
	}
}

void print_stack( void ){
    printf("top: %d \n", top);
	for(int i = top; i>0; i--){
		printf("%d \n",a[i]);
	}
	printf("%d \n",a[0]);
}

