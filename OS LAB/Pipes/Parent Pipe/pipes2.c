#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main(){
   int p[2],i,j;
   int rtstatus,pid;
   char wmsg[3][20];
   for(j=0;j<3;j++){
      scanf("%s",wmsg[j]);
     }
   char rdmsg[20];
   rtstatus = pipe(p);
   if(rtstatus == -1){
      printf("pipe is not created");
      return -1;
    }
    pid = fork();
    if(pid!=0){
    for(i=0;i<3;i++){
       write(p[1],wmsg[i],sizeof(wmsg[i]));
       printf("writing into pipe:%s\n",wmsg[i]);
     }     
     }
     return 0;
     } 
