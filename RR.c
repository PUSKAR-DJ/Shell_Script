/*Write a program in C to implement CPU scheduling using Round Robin Scheduling algorithm*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10

struct Process {
    int process_id;
    int burst_time;
    int remaining_time;
};

void roundRobin(struct Process processes[], int n, int time_quantum) {
    int remaining_processes = n;
    int current_time = 0;
    int current_process = 0;
    int time_counter = 0;

    while (remaining_processes > 0) {
        if (processes[current_process].remaining_time <= time_quantum && processes[current_process].remaining_time > 0) {
            time_counter += processes[current_process].remaining_time;
            processes[current_process].remaining_time = 0;
            printf("Process %d executed from time %d to %d\n", processes[current_process].process_id, current_time, current_time + processes[current_process].burst_time);
            current_time += processes[current_process].burst_time;
            remaining_processes--;
        } else if (processes[current_process].remaining_time > 0) {
            time_counter += time_quantum;
            processes[current_process].remaining_time -= time_quantum;
            printf("Process %d executed from time %d to %d\n", processes[current_process].process_id, current_time, current_time + time_quantum);
            current_time += time_quantum;
        }

        current_process = (current_process + 1) % n;

        if (time_counter >= n * time_quantum)
            break;
    }
}

int main() {
    int n, time_quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_PROCESS) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    struct Process processes[MAX_PROCESS];

    printf("Enter time quantum for Round Robin: ");
    scanf("%d", &time_quantum);

    if (time_quantum <= 0) {
        printf("Invalid time quantum.\n");
        return 1;
    }

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].process_id = i + 1;
    }

    roundRobin(processes, n, time_quantum);

    return 0;
}
