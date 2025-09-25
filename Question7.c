#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) { 
        close(STDOUT_FILENO);
        printf("This won't show up\n");
    } else { 
        printf("Parent still prints fine\n");
    }
    return 0;
}
