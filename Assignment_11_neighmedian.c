#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b) {
 int temp = *a;
 *a = *b;
 *b = temp;
}
// Function to partition the array and return the index of the pivot element
int partition(int arr[], int low, int high) {
 int pivot = arr[high]; // pivot
 int i = (low - 1); 
 for (int j = low; j <= high - 1; j++) {
 if (arr[j] < pivot) {
 i++;
 swap(&arr[i], &arr[j]);
 }
 }
 swap(&arr[i + 1], &arr[high]);
 return (i + 1);
}
void quickSort(int arr[], int low, int high) {
 if (low < high) {
 int pi = partition(arr, low, high);
 quickSort(arr, low, pi - 1);
 quickSort(arr, pi + 1, high);
 }
}
// Function to find neighbors of the median element
void findMedianNeighbors(int arr[], int n) {
 quickSort(arr, 0, n - 1);
 double median;
 if (n % 2 == 0) {
 median = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
 } else {
 median = arr[n / 2];
 }
 int leftNeighbor, rightNeighbor;
 if (n % 2 == 0) {
 leftNeighbor = arr[n / 2 - 1];
 rightNeighbor = arr[n / 2];
 } else {
 leftNeighbor = arr[n / 2 - 1];
 rightNeighbor = arr[n / 2 + 1];
 }
 printf("Median: %.2lf\n", median);
 printf("Left Neighbor: %d\n", leftNeighbor);
 printf("Right Neighbor: %d\n", rightNeighbor);
}
int main() {
 int n;
Sagnik Rahman
 printf("Enter the size of the array: ");
 scanf("%d", &n);
 int *arr = (int *)malloc(n * sizeof(int));
 printf("Enter the elements of the array: ");
 for (int i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }
 findMedianNeighbors(arr, n);
 printf("Sorted Array: ");
 for (int i = 0; i < n; i++) {
 printf("%d ", arr[i]);
 }
 printf("\n");
 free(arr);
 return 0;
}
