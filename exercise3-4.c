#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) is executing 'ls -l'\n", getpid());
        execlp("ls", "ls", "-l", NULL);
        perror("execlp failed");
    } else {
        // Parent process
        wait(NULL);  // Wait for child to finish
        printf("Parent process (PID: %d) has finished waiting.\n", getpid());
    }

    return 0;
}