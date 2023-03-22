#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {

    int arr[1000];
    int num;
    int index = 0;

    while(scanf("%d" , &num) !=EOF){
        arr[index++] = num;
        if (index >= 1000)
        {
            break;
        }
        
    }
        
}
