#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("hello\n");
    } else {
        sleep(1); 
        printf("goodbye\n");
    }
    return 0;
}
