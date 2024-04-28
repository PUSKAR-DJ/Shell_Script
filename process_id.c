/*Write a C program that will create a child process. Then modify the value of a globally defined variable from the child process and print the value of the variable from the parent process*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Global variable
int global_var = 10;

int main() {
    pid_t child_pid;

    // Create a child process
    child_pid = fork();

    if (child_pid < 0) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (child_pid == 0) {
        // Child process
        printf("Child Process - Before Modification: Global Variable = %d\n", global_var);
        global_var = 20; // Modify the global variable in the child process
        printf("Child Process - After Modification: Global Variable = %d\n", global_var);
    } else {
        // Parent process
        printf("Parent Process - Before Modification: Global Variable = %d\n", global_var);
        // Wait for the child process to finish
        wait(NULL);
        printf("Parent Process - After Modification by Child: Global Variable = %d\n", global_var);
    }

    return 0;
}
