#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void){
	push(5);
	push(6);
	print_stack();
	pop();
	print_stack();
	return 0;
}
