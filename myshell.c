#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    char command[256];
    
    while (1) {
        printf("myshell> ");
        fflush(stdout);  // Ensures the prompt is displayed
        
        // Read command from user
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }
        
        command[strcspn(command, "\n")] = 0;
        
        // Check for exit command
        if (strcmp(command, "exit") == 0) {
            break;
        }
        
        // Skips empty commands
        if (strlen(command) == 0) {
            continue;
        }
        
        pid_t pid = fork();
        
        if (pid == 0) {
            char *args[64];  // Support up to 63 arguments + NULL
            char *token;
            int argc = 0;
            
            // Parse command into arguments
            token = strtok(command, " \t");
            while (token != NULL && argc < 63) {
                args[argc++] = token;
                token = strtok(NULL, " \t");
            }
            args[argc] = NULL;
            
            // Execute the command
            if (execvp(args[0], args) == -1) {
                printf("Command execution failed!\n");
                exit(1);
            }
        } else if (pid > 0) {
            // Parent process: wait for child to complete
            int status;
            wait(&status);
        } else {
            // Fork failed
            printf("Fork failed!\n");
            exit(1);
        }
    }
    
    printf("Shell exiting...\n");
    return 0;
}