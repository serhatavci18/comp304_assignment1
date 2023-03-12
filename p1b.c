#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
   
   __pid_t child_pid = -1;

   child_pid = fork();

   if(child_pid == 0){
      printf("Child process ID: %d " , getpid());
      exit(0);
      
   }else{
      sleep(5);
   }

}