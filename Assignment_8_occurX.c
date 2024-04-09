#include <stdio.h>
int occur(int a[], int low, int high, int x) 
{ 
 if (low == high) 
{
 if(a[low] == x)
 return 1;
 } 
if(low >= high)
{
return 0;
}
 
 int mid = (low + high) / 2;
 return occur(a, low, mid, x) + occur(a, mid + 1, high, x);
}
int main() 
{ 
 printf("Enter the size of the array:\n");
 int n;
 scanf("%d", &n);
 int a[n], i;
 printf("Enter the elements of the array:\n");
 for(i = 0; i < n; i++)
 scanf("%d", &a[i]);
 printf("Enter the element to be searched for:\n");
 int x;
 scanf("%d", &x);
 printf("Element %d occurs %d times.", x, occur(a,0,n-1,x));
}
