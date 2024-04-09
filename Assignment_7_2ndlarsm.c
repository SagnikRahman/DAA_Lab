#include <stdio.h>
void swap(int* a, int* b) 
{
 int temp = *a;
 *a = *b;
 *b = temp;
}
int partition(int arr[], int low, int high) 
{
 int pivot = arr[high];
 int i = low - 1;
 for (int j = low; j < high; j++) 
 {
 if (arr[j] <= pivot) 
 {
 i++;
 swap(&arr[i], &arr[j]);
 }
 }
 swap(&arr[i + 1], &arr[high]);
 return i + 1;
}
int quick_select(int arr[], int low, int high, int k) 
{
 if (low == high) 
 {
 return arr[low];
 }
 int pivot_index = partition(arr, low, high);
 if (k == pivot_index) 
 {
 return arr[k];
 } 
 else if (k < pivot_index) 
 {
 return quick_select(arr, low, pivot_index - 1, k);
 } 
 else 
 {
 return quick_select(arr, pivot_index + 1, high, k);
 }
}
void find_second_largest_and_smallest(int arr[], int n) 
{
 if (n < 2) 
 {
 printf("Array size is too small.\n");
 return;
 }
 int second_smallest = quick_select(arr, 0, n - 1, 1);
 int second_largest = quick_select(arr, 0, n - 1, n - 2);
 printf("Second Smallest: %d\n", second_smallest);
 printf("Second Largest: %d\n", second_largest);
}
int main() 
{
 int n;
 printf("Enter the size of the array: ");
 scanf("%d", &n);
 
 int arr[n];
 printf("Enter the elements of the array: \n");
 for (int i = 0; i < n; i++) 
 {
 scanf("%d", &arr[i]);
 }
 find_second_largest_and_smallest(arr, n);
 return 0;
}
