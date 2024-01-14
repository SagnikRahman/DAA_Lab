#include <stdio.h>

int main() {
    int n, X;
    printf("Enter the size of the sorted array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the sorted array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target sum (X): ");
    scanf("%d", &X);

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (currentSum == X) {
            printf("Pair found: %d and %d\n", arr[left], arr[right]);
            return 0;
        } else if (currentSum < X) {
            left++;
        } else {
            right--;
        }
    }

    printf("Pair not found\n");

    return 0;
}
