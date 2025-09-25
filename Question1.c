#include <stdio.h>
#include <unistd.h>

int main() {
   int x = 100;
   pid_t pid = fork();

   if (pid == 0) {
      printf("Child: x = %d\n", x);
      x = 200;
      printf("Child changed x = %d\n", x);
   }
   else {
      printf("Parent: x = %d\n", x);
      x = 300;
      printf("Parent changed x = %d\n", x);
   }
   return 0;
}
