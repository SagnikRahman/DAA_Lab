#include <stdio.h>
#include <limits.h>
int minCoins(int coins[], int m, int V) 
{
 
 int dp[V + 1];
 dp[0] = 0;
 for (int i = 1; i <= V; i++)
 dp[i] = INT_MAX;
 for (int i = 0; i < m; i++) {
 for (int j = coins[i]; j <= V; j++) {
 if (dp[j - coins[i]] != INT_MAX) {
 dp[j] = dp[j] < dp[j - coins[i]] + 1 ? dp[j] : dp[j - coins[i]] + 1;
 }
 }
 }
 return dp[V];
}
int main() 
{
 int coins[] = {1, 2, 5}; // Denominations of coins
 int m = sizeof(coins) / sizeof(coins[0]); // Number of denominations
 int V = 14; // Value for which change is to be made
 printf("Minimum number of coins needed: %d\n", minCoins(coins, m, V));
 return 0;
}
