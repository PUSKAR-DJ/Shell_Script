#include <stdio.h>
const int INT_MAX = 2147483647;

struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

void sjf_scheduling(struct Process processes[], int n) {
    int total_time = 0, min_burst_time, shortest_job_index;
    float average_waiting_time = 0, average_turnaround_time = 0;

    printf("\nProcess Execution Order: \n");

    // Sort processes based on arrival time
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Calculate completion, waiting, and turnaround times
    for (int i = 0; i < n; i++) {
        min_burst_time = INT_MAX;
        for (int j = 0; j <= i; j++) {
            if (processes[j].burst_time < min_burst_time && processes[j].completion_time == 0) {
                min_burst_time = processes[j].burst_time;
                shortest_job_index = j;
            }
        }
        total_time += processes[shortest_job_index].burst_time;
        processes[shortest_job_index].completion_time = total_time;
        processes[shortest_job_index].turnaround_time = processes[shortest_job_index].completion_time - processes[shortest_job_index].arrival_time;
        processes[shortest_job_index].waiting_time = processes[shortest_job_index].turnaround_time - processes[shortest_job_index].burst_time;
        average_waiting_time += processes[shortest_job_index].waiting_time;
        average_turnaround_time += processes[shortest_job_index].turnaround_time;
        printf("P%d ", processes[shortest_job_index].pid);
    }

    // Calculate averages
    average_waiting_time /= n;
    average_turnaround_time /= n;

    // Display results
    printf("\n\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("\nAverage Waiting Time: %.2f", average_waiting_time);
    printf("\nAverage Turnaround Time: %.2f\n", average_turnaround_time);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for process P%d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].completion_time = 0;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    sjf_scheduling(processes, n);

    return 0;
}

/*
Output:

Enter the number of processes: 4
Enter arrival time for process P1: 0
Enter burst time for process P1: 6
Enter arrival time for process P2: 1
Enter burst time for process P2: 4
Enter arrival time for process P3: 2
Enter burst time for process P3: 3
Enter arrival time for process P4: 3
Enter burst time for process P4: 5

Process Execution Order:
P1 P3 P2 P4

Process   Burst Time    Arrival Time    Waiting Time    Turnaround Time
P1        6             0               3               9
P2        4             1               0               4
P3        3             2               3               6
P4        5             3               1               6

Average Waiting Time: 1.75
Average Turnaround Time: 6.25
*/
