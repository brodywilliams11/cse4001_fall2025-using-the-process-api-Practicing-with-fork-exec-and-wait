#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        execl("/bin/ls", "ls", "-l", NULL);
        printf("Exec failed!\n"); 
    } else {
        wait(NULL);
        printf("Parent finished waiting\n");
    }
    return 0;
}
