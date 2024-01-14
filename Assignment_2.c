#include <stdio.h>
int main() 
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the sorted array elements:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    int sea;
    printf("Enter the element to search: ");
    scanf("%d", &sea);
    int low = 0;
    int high = n - 1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == sea) 
        {  
            printf("Element %d found at index %d\n", sea, mid); 
            return 0;
        } else if (arr[mid] < sea) 
        {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Element %d not found in the array\n", sea);
    return 0;
}
