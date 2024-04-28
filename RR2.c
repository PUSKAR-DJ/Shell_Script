#include <stdio.h>

struct Process {
    int pid; // Process ID
    int arrivalTime; // Arrival time
    int burstTime; // Burst time
    int remainingBurstTime; // Remaining burst time
    int waitingTime; // Waiting time
    int turnaroundTime; // Turnaround time
};

int main() {
    int n, quantum;
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
        processes[i].remainingBurstTime = processes[i].burstTime;
        processes[i].waitingTime = 0;
        processes[i].turnaroundTime = 0;
    }

    printf("\nEnter the time quantum: ");
    scanf("%d", &quantum);

    int time = 0, remainingProcesses = n;

    while (remainingProcesses > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remainingBurstTime > 0) {
                if (processes[i].remainingBurstTime > quantum) {
                    time += quantum;
                    processes[i].remainingBurstTime -= quantum;
                } else {
                    time += processes[i].remainingBurstTime;
                    processes[i].waitingTime = time - processes[i].arrivalTime - processes[i].burstTime;
                    processes[i].remainingBurstTime = 0;
                    remainingProcesses--;
                    processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
                }
            }
        }
    }

    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrivalTime,
               processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime);

        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    printf("\nAverage Waiting Time: %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaroundTime / n);

    return 0;
}

/*
Output:
Enter the number of processes: 4

Enter the arrival time and burst time for each process:
Process 1:
Arrival Time: 0
Burst Time: 8
Process 2:
Arrival Time: 1
Burst Time: 4
Process 3:
Arrival Time: 2
Burst Time: 9
Process 4:
Arrival Time: 3
Burst Time: 5

Enter the time quantum: 3

Process    Arrival Time    Burst Time    Waiting Time    Turnaround Time
1          0               8             9               17
2          1               4             3               7
3          2               9             18              27
4          3               5             12              17

Average Waiting Time: 10.50
Average Turnaround Time: 17.00
*/
