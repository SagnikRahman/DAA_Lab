#include <stdio.h>
#define MAX 100
typedef struct Job {
 char id[5];
 int deadline;
 int profit;
} Job;
void jobSequencingWithDeadline(Job jobs[], int n);
int minValue(int x, int y) {
 if (x < y) return x;
 return y;
}
int main() {
 int i, j;
 int n;
 printf("Enter the number of jobs: ");
 scanf("%d", &n);
 Job jobs[MAX];
 for (i = 0; i < n; i++) {
 sprintf(jobs[i].id, "J%d", i + 1); // Assign default job ID
 printf("Enter deadline and profit for job %s:\n", jobs[i].id);
 printf("Deadline: ");
 scanf("%d", &jobs[i].deadline);
 printf("Profit: ");
 scanf("%d", &jobs[i].profit);
 }
 Job temp;
 for (i = 1; i < n; i++) {
 for (j = 0; j < n - i; j++) {
 if (jobs[j + 1].profit > jobs[j].profit) {
 temp = jobs[j + 1];
 jobs[j + 1] = jobs[j];
 jobs[j] = temp;
 }
 }
 }
 printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
 for (i = 0; i < n; i++) {
 printf("%10s %10i %10i\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
 }
 jobSequencingWithDeadline(jobs, n);
 return 0;
}
void jobSequencingWithDeadline(Job jobs[], int n) {
 int i, j, k, maxprofit;
 int timeslot[MAX];
 int filledTimeSlot = 0;
 int dmax = 0;
 for (i = 0; i < n; i++) {
 if (jobs[i].deadline > dmax) {
 dmax = jobs[i].deadline;
 }
 }
 for (i = 1; i <= dmax; i++) {
 timeslot[i] = -1;
 }
 printf("Maximum Deadline: %d\n", dmax);
 for (i = 1; i <= n; i++) {
 k = minValue(dmax, jobs[i - 1].deadline);
 while (k >= 1) {
 if (timeslot[k] == -1) {
 timeslot[k] = i - 1;
 filledTimeSlot++;
 break;
 }
 k--;
 }
 if (filledTimeSlot == dmax) {
 break;
 }
 }
 printf("\nRequired Jobs: ");
 for (i = 1; i <= dmax; i++) {
 printf("%s", jobs[timeslot[i]].id);
 if (i < dmax) {
 printf(" -> ");
 }
 }
 maxprofit = 0;
 for (i = 1; i <= dmax; i++) {
 maxprofit += jobs[timeslot[i]].profit;
 }
 printf("\nMaximum Profit: %d\n", maxprofit);
}


//another
#include<stdio.h>
#include<stdlib.h>


int main()
{ int n=5;
  int d[5]={2,1,2,1,3};//deadlines
  int p[5]={100,19,27,25,15};//profit
  int job[5]={10,20,30,40,50}; //job 
  int temp;
  int dmax=d[0];
  int P=0;
  int i,j;
//finding maximum deadline
  for(i=1;i<n;i++)
  {
    if(d[i]>dmax)
     dmax=d[i];
   }
int s[dmax];

 for (i = 0; i < dmax; i++)
  {
        s[i] = -1;
    }


for(i=0;i<n;i++)
{
  for(j=0;j<n-i-1;j++)
  {
    if(p[j]<p[j+1])
     {
      temp=p[j];
      p[j]=p[j+1];
      p[j+1]=temp;
      
      temp=d[j];
      d[j]=d[j+1];
      d[j+1]=temp;
      
      temp=job[j];
      job[j]=job[j+1];
      job[j+1]=temp;
      
      }
   
  }

}//for i
for(i=0;i<n;i++)
{ printf("Dead line-%d  Job no.%d   Profit -%d\n",d[i],job[i],p[i]);
}
for(i=0;i<n;i++)
{
  if(s[d[i]-1]==-1)//slot empty
   s[d[i]-1]=i;//i th index job scheduled
  else
   for(j=d[i]-1;j>=0;j--)
    {if(s[j]==-1)
       s[j]=i;
    }
  
}
//note:s[] stores job indices and not job numbers
for(i=0;i<dmax ;i++)
 {  if(s[i]!=-1)
    {
	 P+=p[s[i]];//proft associated with s[i] th job
     printf("Slot =%d -->Job no. %d\n",i+1,job[s[i]]);
    }
 }
 printf("Total profit-%d",P);

}
