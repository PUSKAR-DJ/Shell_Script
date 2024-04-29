#include <stdio.h>

struct Process {
    int pid; // Process ID
    int arrivalTime; // Arrival time
    int burstTime; // Burst time
    int waitingTime; // Waiting time
    int turnaroundTime; // Turnaround time
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    printf("\nEnter the arrival time and burst time for each process:\n");

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
    }

    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    processes[0].waitingTime = 0;
    processes[0].turnaroundTime = processes[0].burstTime;

    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrivalTime,
               processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime);
        
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);

    return 0;
}





// Output: 
// Enter the number of processes: 3

// Enter the arrival time and burst time for each process:
// Process 1:
// Arrival Time: 0
// Burst Time: 5
// Process 2:
// Arrival Time: 1
// Burst Time: 3
// Process 3:
// Arrival Time: 2
// Burst Time: 6

// Process	Arrival Time	Burst Time	Waiting Time	Turnaround Time
// 1       0           5           0           5
// 2       1           3           5           8
// 3       2           6           8           14

// Average Waiting Time: 4.33
// Average Turnaround Time: 9.00
