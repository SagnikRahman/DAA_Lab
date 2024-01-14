#include <stdio.h> 
int main() 
{ 
    int n; 
    printf("Enter the length of array:\n"); 
    scanf("%d",&n); 
    int arr[n]; 
    printf("Enter the elements of the sorted array:\n"); 
    int i,X,left=0,right=n-1,currentSum=0,flag=0; 
    for(i=0;i<n;i++) 
    scanf("%d",&arr[i]); 
    printf("Enter sum value(X):\n"); 
    scanf("%d",&X); 
    printf("\nThe possibilities are:\n");
    while(left<right) 
    { 
        currentSum=arr[left]+arr[right];
        if(currentSum==X) 
        {
            flag=1; 
            printf("%d+%d=%d\n",arr[left],arr[right],X); 
            left++; 
            right--; 
        } 
        else if(currentSum<X) 
        left++; 
        else 
        right--; 
    } 
if(flag==0) 
printf("No such element pair exists"); 
}
