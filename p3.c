#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {

    int arr[1000];
    int num;
    int index = 0;
    int n;

    scanf("%d" , &n);

    while(scanf("%d" , &num) !=EOF){
        arr[index++] = num;
        if (index >= 1000)
        {
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        __pid_t procs[n];
        procs[i] = fork();
    }

    
    
       
}
