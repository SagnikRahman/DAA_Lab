#include<stdio.h> 
#include<stdlib.h>
#include<limits.h> 
double Median(int* a, int n1, int* b, int n2) 
{
if (n1 > n2) return Median(b, n2, a, n1); 
int n = n1 + n2; 
int left = (n1 + n2 + 1) / 2; 
// apply binary search on smaller array 
int low = 0, high = n1; 
while (low <= high) 
 { 
int mid1 = (low + high) /2;
int mid2 = left - mid1;
int left1 = INT_MIN, left2 = INT_MIN, right1 = INT_MAX, right2 = INT_MAX; 
if (mid1 < n1) 
right1 = a[mid1]; 
if (mid2 < n2) 
right2 = b[mid2]; 
if (mid1 - 1 >= 0) 
left1 = a[mid1 - 1]; 
if (mid2 - 1 >= 0) 
left2 = b[mid2 - 1]; 
if (left1 <= right2 && left2 <= right1) 
 {
 if (n % 2 !=0) 
 { 
 if (left1 > left2) 
 return (double)left1; 
 else 
 return (double)left2; 
 } 
 else 
 {
 if (left1 > left2) 
 return ((double)left1+(double)(right1<right2?right1:right2))/2.0; 
 else 
 return ((double)left2+(double)(right1<right2?right1:right2))/2.0; 
 } 
 } 
 else if (left1 > right2) 
 high = mid1 - 1; 
 else 
 low = mid1 + 1; 
 } 
 return 0; 
} 
int main() 
{
 int n1,n2; 
 printf("Enter the size of first array: \n"); 
 scanf("%d",&n1); 
 printf("Enter the size of second array: \n"); 
 scanf("%d",&n2); 
 int *a=(int*)malloc(n1*sizeof(int)); 
 int *b=(int*)malloc(n2*sizeof(int)); 
 int i,j; 
 printf("Enter the first array: \n"); 
 for(i=0;i<n1;i++) 
 scanf("%d",&a[i]);
 printf("Enter the second array: \n"); 
 for(i=0;i<n2;i++) 
 scanf("%d",&b[i]);
 printf("\nMedian: %.2f",Median(a,n1,b,n2)); 
}
