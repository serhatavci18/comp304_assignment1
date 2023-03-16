#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main(){

    int n; int status;
    __pid_t children;

    printf("Enter the number of processes to be benchmarked: ");
    scanf("%d" , &n);

    struct timeval start, end;
    double exec_time;

    gettimeofday(&start, NULL);



    for(int i = 0 ; i < n ; i++){
        children = fork();
        printf("Child pid: %d \n " , getpid());
    }
    /*
    for (int i = 0; i < status; i++)
    {
        wait(&status);
    }
    */
    

    gettimeofday(&end , NULL);

    exec_time = (end.tv_sec - start.tv_sec)*1000.0;
    exec_time += (end.tv_usec - start.tv_usec)/1000.0;

    printf("Time of execution: %.2f ms \n " , exec_time);


}