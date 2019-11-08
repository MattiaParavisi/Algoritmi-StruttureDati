#include <stdio.h>

void merge(int a[], int sx, int dx, int m){
  int l1, l2, i=0, b[dx], j;
  l1=sx;
  l2=m+1;
  while(l1<=m && l2<=dx){
    if(a[l1]<a[l2]){
      b[i]=a[l1];
      l1++;
    }else {
      b[i]=a[l2];
      l2++;
    }
    i++;
  }
  while(l1<=m){
    b[i]=a[l1];
    l1++;
    i++;
  }
  while(l2<=dx){
    b[i]=a[l2];
    l2++;
    i++;
  }
  for(i=sx; i<=dx; i++){
    a[i]=b[i-sx];         //dipende dall'sx di a, non posso assumere che ogni a che mi passino parta da 0
  }
}

void mergesort(int a[], int sx, int dx){
  int m;
  if(sx<dx){
    m=(sx+dx)/2;
    mergesort(a, sx, m);
    mergesort(a, m+1, dx);
    merge(a,sx,dx,m);
  }else{
    return;
  }
}


int main(void){
  int a[]={95,96,97,98,99,100,90,91,92,93,94}, i;
  mergesort(a,0,10);
  for(i=0; i<11; i++){
    printf("%d \n", a[i]);
  }
}
