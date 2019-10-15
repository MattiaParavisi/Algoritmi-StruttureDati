#include<stdio.h>
#include<limits.h>

int main(void){
	char char1, char2, char3, char4;
	short short1, short2, short3;
	int int1, int2, int3; 
	long long1, long2, long3;

	char1= SCHAR_MIN;
	char2= SCHAR_MAX;
	char3= UCHAR_MAX;
	printf("le dimensioni massime e minime per i char sono: %ld, %ld, %ld, %ld \n", sizeof(char1), sizeof(char2), sizeof(char3), sizeof(char4));
	
	short1= SHRT_MIN;
	short2= SHRT_MAX;
	short3= USHRT_MAX;
	printf("le dimensioni massime e minime per gli short sono: %ld, %ld, %ld \n", sizeof(short1), sizeof(short2), sizeof(short3));

	int1= INT_MIN;
	int2= INT_MAX;
	int3= UINT_MAX;
	printf("le dimensioni massime e minime per gli int sono: %ld, %ld, %ld \n", sizeof(int1), sizeof(int2), sizeof(int3));

	long1= LONG_MIN;
	long2= LONG_MAX;
	long3= ULONG_MAX;
	printf("le dimensioni massime e minime per i long sono: %ld, %ld, %ld \n", sizeof(long1), sizeof(long2), sizeof(long3));
	

}
