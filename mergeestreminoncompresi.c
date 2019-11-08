#include <stdio.h>

void merge(int a[], int sx, int m, int dx){
  int l1=sx, l2=m, b[dx], i;
  for(i=0; l1<m && l2<dx; i++){
    if(a[l1]<a[l2]){
      b[i]=a[l1];
      l1++;
    }else {
      b[i]=a[l2];
      l2++;
    }
  }
  if(l1<m){
    while(l1<m){
      b[i++]=a[l1++];
    }
  }
  if(l2<dx){
    while(l2<dx){
      b[i++]=a[l2++];
    }
  }
  for(i=sx; i<dx; i++ ){ 
    //printf("copio in posizione %d il valore %d \n", i, b[i-sx]);
    a[i]=b[i-sx];
    //printf("a[sx] = %d \n", a[sx]);
  }
  return;
}

void mergesort(int a[], int sx, int dx){
	int m;
	if(sx<dx-1){
		m = (sx+dx)/2;
		mergesort(a, sx, m);
		mergesort(a, m, dx);
		merge(a, sx, m, dx);
	}
	return;
}

int main(void){
  int a[]={15,22,33,54,1,2,66,78,15,99,100}, i;
  mergesort(a, 0, 11);
  for(i=0; i<11; i++){
    printf("%d \n", a[i] );
  }
}
