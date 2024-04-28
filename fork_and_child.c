/*Write a C Program that will create a child process. Then print the process id & parent process id both from the child as well as from the parent.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid, parent_pid;

    // Create a child process
    child_pid = fork();

    if (child_pid < 0) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (child_pid == 0) {
        // Child process
        child_pid = getpid();
        parent_pid = getppid();
        printf("Child Process:\n");
        printf("PID: %d\n", child_pid);
        printf("PPID: %d\n", parent_pid);
    } else {
        // Parent process
        parent_pid = getpid();
        printf("Parent Process:\n");
        printf("PID: %d\n", parent_pid);
        printf("Child PID: %d\n", child_pid);
    }

    return 0;
}
