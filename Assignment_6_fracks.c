#include<stdio.h>
#include<stdlib.h>
int main() {
 int n;
 printf("Enter the number of items: ");
 scanf("%d", &n);
 int items[n+1];
 int profit[n+1];
 int weight[n+1];
 double pw[n+1]; 
 int W;
 double P = 0; 
 double x[n+1];
 int i,j;
 printf("Enter the profits for each item: ");
 for (i = 1; i <= n; i++) {
 scanf("%d", &profit[i]);
 }
 printf("Enter the weights for each item: ");
 for (i = 1; i <= n; i++) {
 scanf("%d", &weight[i]);
 }
 printf("Enter the maximum weight allowed (W): ");
 scanf("%d", &W);
 for (i = 1; i <= n; i++) {
 pw[i] = (double) profit[i] / weight[i];
 items[i] = i;
 }
 for (i = 1; i <= n; i++) {
 for (j = i+1; j <= n; j++) {
 if (pw[i] < pw[j]) {
 double temp = pw[i];
 pw[i] = pw[j];
 pw[j] = temp;
 int tempInt = items[i];
 items[i] = items[j];
 items[j] = tempInt;
 tempInt = profit[i];
 profit[i] = profit[j];
 profit[j] = tempInt;
 tempInt = weight[i];
 weight[i] = weight[j];
 weight[j] = tempInt;
 }
 }
 }
 printf("SORTED AS PER PROFIT/WEIGHT:\n");
 for (i = 1; i <= n; i++) {
 printf("Item=%d Weight=%d Profit=%d Profit/Weight=%.2lf\n", items[i], 
weight[i], profit[i], pw[i]);
 }
 for (i = 1; i <= n; i++) {
 if (weight[i] <= W && W > 0) { 
 W -= weight[i];
 P += profit[i];
 x[i] = 1.0;
 } else {
 break;
 }
 }
 if (i <= n && W > 0) { 
 x[i] = (double) W / weight[i]; 
 P += x[i] * profit[i];
 }
 printf("Maximum Profit: %.2lf", P); 
 return 0;
}
