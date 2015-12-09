#include<stdio.h>
#include<stdlib.h>

void mergeSort(int *a, int n); //This function will split the array
void merge(int *a,int *b, int *c,int n, int m);  //this function will merge
void print(int *a,int n)
{
    int i=0;
    printf("\n---------------\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }
    printf("\n---------------\n");
}
int main()
{
  int a[10] = {9,6,3,5,8,1,2,4,7,10};
  mergeSort(a,10);
  int i=0;
  for(i=0;i<10;i++)
    printf("%d ", a[i]);
  return 0;
}

void merge(int *a, int *b,int *c,int n,int m) //merge function tested
{
  //n = length of a, m = length of b
  int i=0,j=0,k=0;
  while(i<m && j<n) //while neither arrays are exhausted
  {
    if(*(a+i) <= *(b+j))
    {
      *(c+k) = *(a+i);
      i++;
    }
    else
    {
      *(c+k) = *(b+j);
      j++;
    }
    k++;
  }
  while(i<m)  //when b is exhausted
  {
    *(c+k)=*(a+i);
    i++;
    k++;
  }
  while (j<m) //when a is exhausted
  {
    *(c+k)=*(b+j);
    j++;
    k++;
  }
}

void mergeSort(int *a,int n)  // n is the length of a
{
  //basic login - split arrays into smaller arrays recursively
  if(n<2)
    return;
  int i=0;
  int *x = malloc(2*n);
  int *y = malloc(2*n);
  for(i=0;i<n/2;i++)
  {
    *(x+i) = *(a+i);
  }
  int j=0;
  while(i<n)
  {
    *(y+j) = *(a+i);
    i++;
    j++;
  }
  print(x,n/2);
  mergeSort(x,n/2);
  print(x,n/2);
  print(y,n/2);
  mergeSort(y,n/2);
  print(y,n/2);
  print(a,n);
  merge(x,y,a,n/2,n/2);
  print(a,n);
  free(x);
  free(y);
}//some error related to the odd even case is occuring
