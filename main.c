#include<stdio.h>

void mergeSort(int *a, int n); //This function will split the array
void merge(int *a,int *b, int *c,int n, int m);  //this function will merge

int main()
{
  int a[10] = {9,6,3,5,8,1,2,4,7,0};
  int i=0;
  for(i=0;i<10;i++)
    printf("%d ", c[i]);
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
