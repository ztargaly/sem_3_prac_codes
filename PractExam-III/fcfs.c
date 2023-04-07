#include <stdio.h>

// Function to calculate waiting time and turnaround time
void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[]) {
    int service_time[n];
    service_time[0] = 0;
    wt[0] = 0;

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++) {
        // Waiting time for the current process is the sum of burst time of previous processes
        wt[i] = bt[i - 1] + wt[i - 1] - at[i];
        // If the waiting time is negative, make it 0
        if (wt[i] < 0) {
            wt[i] = 0;
        }
    }
}

// Function to calculate turnaround time
void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

// Function to calculate average waiting time and average turnaround time
void findAvgTime(int processes[], int n, int bt[], int at[]) {
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    // Calculate waiting time and turnaround time
    findWaitingTime(processes, n, bt, wt, at);
    findTurnaroundTime(processes, n, bt, wt, tat);

    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");

    // Display process details and calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], at[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Calculate average waiting time and average turnaround time
    float avg_wt = (float) total_wt / n;
    float avg_tat = (float) total_tat / n;

    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
}

int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n]; // Array to store process IDs
    int burst_time[n]; // Array to store burst time of processes
    int arrival_time[n]; // Array to store arrival time of processes

    printf("Enter the burst time and arrival time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
        printf("Arrival Time: ");
        scanf("%d", &arrival_time[i]);
        processes[i] = i + 1;
    }

    findAvgTime(processes, n, burst_time, arrival_time);

    return 0;
}
