#include <stdio.h>
#include <unistd.h>


int main(){

    int n;
    int level = 0;

    printf("Enter the number of fork calls: ");
    scanf("%d" , &n );
    printf("Process ID: %d , Parent Process ID: %d , Level: %d \n" , getpid() , getppid() , level);


    for(int i = 0 ; i < n ; i++){
        fork();
        level++;
        printf("Process ID: %d , Parent Process ID: %d , Level: %d \n" , getpid() , getppid() , level);
    }

    return 0;

}