#include <stdio.h>
int findBitonicPoint(int a[], int l, int h) {
    while (l <= h) {
        int m = l + (h - l) / 2;
        if (a[m - 1] < a[m] && a[m] > a[m + 1]) {
            return m;
        } else if (a[m - 1] < a[m] && a[m] < a[m + 1]) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
     return -1;
}
int main() {
    int n;
    printf("Enter the size of the bitonic sequence: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the bitonic sequence:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int bp = findBitonicPoint(a, 0, n - 1);
    if (bp != -1) {
        printf("Bitonic point found at index %d, value: %d\n", bp, a[bp]);
    } else {
        printf("Bitonic point not found\n");
    }
    return 0;
}
