#include <stdio.h>
#include <stdlib.h>

#define START 3

char *read_line(char c){
	char *parola, input, size=START;
	int i=0;
	parola = malloc(START * sizeof(int));
	if(parola==NULL){
		return NULL;
	}
	while(1){
		scanf("%c", &input);
		if(input == c ){
			return parola;		
		}
		if(i>=size){
			size += size;
			parola = realloc(parola, START*sizeof(char));
		}
		parola[i++] = input;
	}
	return parola;
}

int main(void){
	int i;
	char c = '!';
	char *a = read_line(c);
}
