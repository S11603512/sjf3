#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
int bt[35],p[35],pr[35],wt[35],tat[35],total_wt=0,total_tat=0,flag,min,n;
float avg_wt,avg_tat;
void sortbt()
{
int i;
for( i=0;i<n;i++)
  {
	min=i;
	int j;
	for(j=i+1;j<n;j++)
	{
		if(bt[j]<bt[min])
		 {
min=j;
		 }
	}
	flag=bt[i];
	bt[i]=bt[min];
	bt[min]=flag ;
            flag=p[i];
	p[i]=p[min];
	p[min]=flag;
	
  }
}
//waiting time
void wat()
{
int i;
for(i=1;i<n;i++)
  {  
	wt[i]=0;
	int j;
	for( j=0;j<i;j++)
	 {
wt[i]+=bt[j];
	 }
	 total_wt+=wt[i];
  } 

}
//turn around time
void turnat()
{
int i;
for( i=0;i<n;i++)
  {
   tat[i]=bt[i]+wt[i];  //calculating turn around time
   total_tat+=tat[i];
 
  }
}
//creating an array of priority
void pr_array()
{
int i;
	for( i=1;i<n;i++)
	  {
	  	pr[i]=1+wt[i]/bt[i];
	  }
}
//sorting according to priority
void pr_sort()
{
int i;
for( i=1;i<n;i++)
  {
	min=i;
	int j; 
	for(j=i+1;j<n;j++)
	{
		if(pr[j]<pr[min])
		 {min=j;
		 }
	}
	flag=bt[i];
	bt[i]=bt[min];
	bt[min]=flag;
	flag=p[i];
	p[i]=p[min];
	p[min]=flag ;
  }}
int main()
{
int i;
printf("enter no . of processes : ");
scanf("%d",&n);
printf("\n enter burst time  :\n");
for(i=0;i<n;i++)
{
 printf("p%d:",i+1);
 scanf("%d",&bt[i]);
 p[i]=i+1;//contains process number
}	
//sorting burst time
sortbt();
wt[0]=0; //waiting time of first process will be zero
//calculating waiting time
wat();
avg_wt=(float)total_wt/n;
//turn aroung time
turnat();
avg_tat=(float) total_tat/n;  //average turnaround time
//display
printf("\nProcess\t     Burst time \tWaiting time\tTurnaround time\t   priority");
for( i=0;i<n;i++)
{
  if(i==0)
     {
	 printf("\np%d\t\t  %d\t\t    %d\t\t\t%d\t\t---",p[i],bt[i],wt[i],tat[i]);
     }
  else
     {
pr_array();
 pr_sort();
      printf("\n p %d \t  %d\t    %d\t%d\t%d",p[i],bt[i],wt[i],tat[i],pr[i]);
	 } }
printf("\n Average waiting time is:%f\n",avg_wt);
printf("\n Average turn around time is :%f\n",avg_tat);
}
