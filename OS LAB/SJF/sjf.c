#include <stdio.h>

int main(){
   int n;
   printf("enter the no of processes:");
   scanf("%d",&n);
   printf("enter the burst times:");
   int bt[n],wt[n],tat[n],p[n],i,j,pos,t;
   float tt=0,wat=0;
   for(i=0;i<n;i++){
      scanf("%d",&bt[i]);
      p[i]=i+1;
    }
    for(i=0;i<n;i++){
       pos=i;
       for(j=i+1;j<n;j++){
          if(bt[j]<bt[pos]){
             pos=j;
           }
        }
        t=bt[i];
        bt[i]=bt[pos];
        bt[pos]=t;
        
        t=p[i];
        p[i]=p[pos];
        p[pos]=t;
     }
     wt[0]=0;
     float awat,atat;
     for(i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        wt[i+1]=tat[i];
      }
      printf("Processes  |  Burst Times  |   Waiting times  |   Turn around time\n");
      for(i=0;i<n;i++){
         tt += tat[i];
         wat += wt[i];
         printf("%d\t\t  %d\t\t   %d\t\t  %d\n",p[i],bt[i],wt[i],tat[i]);
      }
      awat = wat/n;
      atat = tt/n;
      printf("Average waiting time = %f\nAverage turn-around time = %f",awat,atat);
      
      return 0;
      }  
           
        
        
               
