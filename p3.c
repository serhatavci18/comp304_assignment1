#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_NUMBERS 1000

int numbers[MAX_NUMBERS];
int num_numbers;

int main(int argc, char *argv[]) {
    int x = atoi(argv[1]);
    int n = atoi(argv[2]);

    char buffer[1024];
    char *token;
    int i = 0;
    while (fgets(buffer, 1024, stdin) != NULL && i < MAX_NUMBERS) {
        token = strtok(buffer, "\n");
        while (token != NULL) {
            numbers[i++] = atoi(token);
            token = strtok(NULL, "\n");
        }
    }
    num_numbers = i;

    int range_size = num_numbers / n;
    int last_range_size = num_numbers - (n - 1) * range_size;
    int pid;
    int found = 0;

    for (int i = 0; i < n; i++) {
        pid = fork();
        if (pid < 0) {
            printf("Failed to fork\n");
            exit(1);
        } else if (pid == 0) {
            int start = i * range_size;
            int end = (i == n - 1) ? num_numbers : start + range_size;
            for (int j = start; j < end; j++) {
                if (numbers[j] == x) {
                    printf("%d\n", j);
                    exit(0);
                }
            }
            exit(1);
        }
    }

    int status;
    while (wait(&status) > 0) {
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (int i = 0; i < n; i++) {
            if (i != pid) {
                kill(i, SIGTERM);
            }
        }
    } else {
        printf("%d not found\n", x);
    }

    return 0;
}
