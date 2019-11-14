#include <stdio.h>
#include <stdlib.h>

#define LEN 5

char *read_word( void ){
	int conta = 0, len = LEN;
	char c, *parola;
	parola = malloc(len*sizeof(char));;
	while( 1 ){
		c = getchar();
		if(isalpha(c)==0){
			*(parola + conta) = '\0';
			return parola;
		}
		if(conta>len){
				len += len;
				parola = realloc(parola, len * sizeof(char));
		}
		*(parola + conta) = c;
		conta++;
	}
}

int main(void){
	char *res;
	int i;
	res = read_word();
	printf("%s", res);
}
