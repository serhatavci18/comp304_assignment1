#include <stdio.h>
#include <unistd.h>

int main(){
   __pid_t child_pid;

   child_pid = fork();

   if(child_pid == 0){
      printf("Child process ID: %d " , getpid());
      sleep(5);
   }

}