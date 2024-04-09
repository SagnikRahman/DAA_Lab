#include <stdio.h>
#include <stdlib.h>
long long mergeAndCount(int a[], int l, int m, int h) {
    int i, j, k;
    long long c = 0;
    int n1 = m - l + 1;
    int n2 = h - m;
    // Create temporary arrays
    int L[n1], R[n2];
    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
    // Merge the temporary arrays back into a[]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
            c += n1 - i; // Count inversions
        }
    }
    // Copy the remaining elements of L[], if any
    while (i < n1) {
        a[k++] = L[i++];
    }
    // Copy the remaining elements of R[], if any
    while (j < n2) {
        a[k++] = R[j++];
    }
    return c;
}
long long mergeSortAndCount(int a[], int l, int h) {
    long long c = 0;
    if (l < h) {
        int m = l + (h - l) / 2;
        // Recursively sort and count inversions in the left and right halves
        c += mergeSortAndCount(a, l, m);
        c += mergeSortAndCount(a, m + 1, h);

        // Merge the two halves and count inversions
        c += mergeAndCount(a, l, m, h);
    }
    return c;
}
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int ac[n];
    for (int i = 0; i < n; i++) {
        ac[i] = a[i];
    }

    long long c = mergeSortAndCount(a, 0, n - 1);
    printf("Inversion count: %lld\n", c);
    printf("Inversion pairs:\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ac[i] > ac[j]) && (i < j)) {
                printf("(%d, %d)\n", ac[i], ac[j]);
            }
        }
    }
    return 0;
}
