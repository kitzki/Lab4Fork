#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        // Parent
        printf("I am the parent, PID: %d\n", getpid());
    } else if (pid == 0) {
        // Child
        printf("I am the child, PID: %d\n", getpid());

        pid_t grandchild_pid = fork();

        if (grandchild_pid > 0) {
        } else if (grandchild_pid == 0) {
            // Grandchild process
            printf("I am the grandchild, PID: %d\n", getpid());
        } else {
            // Fork failed for grandchild
            printf("Grandchild fork failed!\n");
        }
    } else {
        // Fork failed for child
        printf("Fork failed!\n");
    }

    return 0;
}