#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child running\n");
    } else {
        int status;
        pid_t cpid = wait(&status);
        printf("Parent waited for child PID %d\n", cpid);
    }
    return 0;
}
