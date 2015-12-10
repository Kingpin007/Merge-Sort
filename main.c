#include<stdio.h>
#include<stdlib.h>

void mergeSort(int *a, int n); //This function will split the array
void merge(int *a,int *b, int *c,int n, int m);  //this function will merge
void print(int *a,int n,char *s)
{
    int i=0;
    printf("\n---------------\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }
    printf("\n%s\n---------------\n",s);
}
int main()
{
  int a[8] = {9,6,3,5,8,1,2,4};
  mergeSort(a,8);
  int i=0;
  for(i=0;i<8;i++)
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
  if(n<2)
    return;
  int mid = n/2;
  int *left = malloc(4*mid);
  int *right = malloc(4*(n-mid));
  int i=0;
  while(i<mid)
  {
    *(left+i) = *(a+i);
    i++;
  }
  while(i<n)
  {
    *(right+(i-mid)) = *(a+i);
    i++;
  }
  print(left,mid,"before mergeSort()\n");
  mergeSort(left,mid);
  print(left,mid,"after mergeSort()\n");
  print(right,mid,"before mergeSort()\n");
  mergeSort(right,n-mid);
  print(right,mid,"after mergeSort()\n");
  print(a,n,"before merge()\n");
  merge(left,right,a,mid,n-mid);
  print(a,n,"after merge()\n");
}//some error related to the odd even case is occuring
