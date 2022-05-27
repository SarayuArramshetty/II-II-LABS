#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
char *m1 = "Hello!";
char *m2 = "Welcome to";
char *m3 = "BVRITH";
int main(){
   char buf[20];
   int p[2],i;
   if(pipe(p) == -1){
      printf("pipe is not created");
      return -1;
   }
   write(p[1],m1,sizeof(buf));
   write(p[1],m2,sizeof(buf));
   write(p[1],m3,sizeof(buf));
   printf("reading from pipe:");
   for(i=0;i<3;i++){
      read(p[0],buf,sizeof(buf));
      printf("%s ",buf);
   }
   printf("\n");
   return 0;
}         
