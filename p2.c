#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_SIZE 100
int main(){

    int n;
    __pid_t children[MAX_SIZE];
    int child_no = 1;

    //printf("Enter the number of processes to be benchmarked: ");
    scanf("%d" , &n);

    struct timeval start, end;
    double exec_time;

    gettimeofday(&start, NULL);



    for(int i = 0 ; i < n ; i++){
        children[i] = fork();
        child_no++;
        gettimeofday(&end , NULL);

        exec_time = (end.tv_sec - start.tv_sec)*1000.0;
        exec_time += (end.tv_usec - start.tv_usec)/1000.0;

        printf("Child %d Executed in  %.2f millis \n " , child_no ,  exec_time);
    }
    

    

    


}