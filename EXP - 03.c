#include <stdio.h>

int main()
{
    int n, i;
    int burst[20], waiting[20], turnaround[20];
    float avg_waiting = 0, avg_turnaround = 0;

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input burst times
    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &burst[i]);
    }

    // Waiting time for first process
    waiting[0] = 0;

    // Calculate waiting time
    for (i = 1; i < n; i++)
    {
        waiting[i] = waiting[i - 1] + burst[i - 1];
    }

    // Calculate turnaround time
    for (i = 0; i < n; i++)
    {
        turnaround[i] = waiting[i] + burst[i];
        avg_waiting += waiting[i];
        avg_turnaround += turnaround[i];
    }

    // Calculate averages
    avg_waiting /= n;
    avg_turnaround /= n;

    // Display results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\n",
               i + 1, burst[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_waiting);
    printf("\nAverage Turnaround Time = %.2f\n", avg_turnaround);

    return 0;
}

