
#include<stdio.h>
 
int main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],a[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        printf("Arrival time:");
        scanf("%d",&a[i]);
        p[i]=i+1;           //contains process number
    }
 
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
        
        temp=a[i];
        a[i]=a[pos];
        a[pos]=temp;
    }

    wt[0]=0;
     float awat,atat;
     for(i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        wt[i+1]=tat[i];
      }
      printf("Processes  |  Arrival Times  | burst times   | priority    |  Waiting times  |   Turn around time\n");
      int tt=0,wat=0;
      for(i=0;i<n;i++){
         tt += tat[i];
         wat += wt[i];
         printf("%d\t\t  %d\t\t   %d\t\t  %d\t\t   %d\t\t   %d\n",p[i],a[i],bt[i],pr[i],wt[i],tat[i]);
      }
      awat = wat/n;
      atat = tt/n;
      printf("Average waiting time = %f\nAverage turn-around time = %f",awat,atat);
      
      return 0;
      }  
           
        
        
               




