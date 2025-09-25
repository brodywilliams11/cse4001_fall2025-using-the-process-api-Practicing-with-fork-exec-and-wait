#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child1 = fork();

    if (child1 == 0) {
        printf("Child 1 running\n");
        return 0;
    } else {
        pid_t child2 = fork();
        if (child2 == 0) {
            printf("Child 2 running\n");
            return 0;
        } else {
            waitpid(child1, NULL, 0);  
            printf("Parent waited for Child 1 first\n");
            waitpid(child2, NULL, 0); 
            printf("Parent waited for Child 2 next\n");
        }
    }
    return 0;
}
