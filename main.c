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
  int a[10] = {9,6,3,5,8,1,2,4,7,0};
  mergeSort(a,10);
  int i=0;
  for(i=0;i<10;i++)
    printf("%d ", a[i]);
  return 0;
}

void merge(int *a, int *b,int *c,int m,int n) //merge function tested
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
  while (j<n) //when a is exhausted
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
  int l1 = n/2,l2;
  if(n % 2 != 0)
    l2 = l1 + 1;
  else
    l2 = l1;
  int *left = malloc(4*l1);
  int *right = malloc(4*l2);
  int i = 0;
  for(;i<l1;i++)
    *(left+i) = *(a+i);
  for(;i<n;i++)
    *(right+(i-l1)) = *(a+i);
  mergeSort(left,l1);
  mergeSort(right,l2);
  merge(left,right,a,l1,l2);
  free(left);
  free(right);
}//some error related to the odd even case is occuring
