#include<stdio.h>
int max(int a, int b) 
{ 
 return (a > b)? a : b; 
}
int knapSack(int W, int wt[], int val[], int n) 
{
 int i, w;
 int K[n+1][W+1];
 for (i = 0; i <= n; i++) {
 for (w = 0; w <= W; w++) {
 if (i==0 || w==0)
 K[i][w] = 0;
 else if (wt[i-1] <= w)
 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
 else
 K[i][w] = K[i-1][w];
 }
 }
 return K[n][W];
}
int main() 
{
 int val[] = {60, 100, 120};
 int wt[] = {10, 20, 30};
 int W = 50;
 int n = sizeof(val)/sizeof(val[0]);
 printf("Maximum value in knapsack: %d\n", knapSack(W, wt, val, n));
 return 0;
}


//another 
#include<stdio.h>
#include<stdlib.h>

int max(int a,int b)
{ return a>b?a:b;
}

int main()
{
	int W=10;
	//weight of knapsack
	int n=4;
	//no of items

	int B[n+1][W+1];

	int items[5]={0,1,2,3,4};
	int p[5]={0,10,42,9,5};
	int w[5]={0,4,19,12,5};
        int i,j;
	for(i=0;i<=n;i++)
	{ for(j=0;j<=W;j++)
	  {  if(i==0||j==0)
	       B[i][j]=0;
	     else
	       { if(w[i]<=j)
	        B[i][j]=max(B[i-1][j] , B[i-1][j-w[i]]+p[i]);      
	         else 
	         B[i][j]=B[i-1][j]; 
	       } 
	  }  
	  //for j
     }//for i	
     
     for(i=0;i<=n;i++)
	{ for(j=0;j<=W;j++)
	   { printf("%d \t",B[i][j]);}
	   printf("\n");
	}
       
	printf("max profit-%d",B[n][W]);  
	
}
