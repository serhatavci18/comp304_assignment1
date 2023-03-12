#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    int n; int proc;
    __pid_t children;
    printf("Enter the number of processes to be benchmarked: ");
    scanf("%d" , &n);


    for(int i = 0 ; i < n ; i++){
        children = fork();
    }

}