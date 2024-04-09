#include <stdio.h>
void countingSort(int arr[], int n) {
 int count[10] = {0};
 int output[n];
 for (int i = 0; i < n; i++) {
 count[arr[i]]++;
 }
 for (int i = 1; i < 10; i++) {
 count[i] += count[i - 1];
 }
 for (int i = n - 1; i >= 0; i--) {
 int digit = arr[i];
 output[count[digit] - 1] = digit;
 count[digit]--;
 }
 for (int i = 0; i < n; i++) {
 arr[i] = output[i];
 }
}
int main() {
 int n;
 printf("Enter the number of elements: ");
 scanf("%d", &n);
 int arr[n];
 printf("Enter the elements: ");
 for (int i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }
 countingSort(arr, n);
 printf("Sorted array: ");
 for (int i = 0; i < n; i++) {
 printf("%d ", arr[i]);
 }
 printf("\n");
 return 0;
}
