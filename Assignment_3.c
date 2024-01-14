#include <stdio.h> 
#include <stdlib.h> 
int binarySearch1D(int arr[], int K, int N) 
{
    int low = 0; 
    int high = N - 1; 
    while (low <= high) 
    {
        int mid = low + (high - low) / 2; 
        if (arr[mid] == K)
        return mid; 
        if (arr[mid] < K) 
        low = mid + 1; 
        else 
        high = mid - 1; 
    } 
    return -1; 
} 
int main() 
{
    int N,M,K; 
    printf("Enter the number of rows(N):\n"); 
    scanf("%d", &N); 
    printf("Enter the number of columns(M):\n"); 
    scanf("%d", &M); 
    int A[N][M]; 
    int i, j, row = -1, col = -1;
    for (i = 0; i < N; i++) 
    {
        for (j = 0; j < M; j++) 
        {
            printf("Enter element at index(%d,%d):\n", i, j); 
            scanf("%d", &A[i][j]); 
        }
    } 
    printf("The 2D Array is:\n");
    for (i = 0; i < N; i++) 
    {
        for (j = 0; j < M; j++)
        {
            printf("%d ", A[i][j]); 
        }
        printf("\n");
    }  
    printf("Enter the element to be searched:\n"); 
    scanf("%d", &K); 
    int low = 0,high = N - 1; 
    while (low <= high) 
    {
        int mid = low + (high - low) / 2; 
        if (K >= A[mid][0] && K <= A[mid][M - 1]) 
        {
            row = mid; 
            col = binarySearch1D(A[mid], K, M); 
            break; 
        } 
        else if (K < A[mid][0]) 
        high = mid - 1; 
        else 
        low = mid + 1;
    } 
    if (col != -1) 
    printf("Element found at index(%d,%d)\n", row, col); 
    else 
    printf("Not found\n"); 
    return 0; 
}
