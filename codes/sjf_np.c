#include <stdio.h>

int main(void)
{
    int n;
    int pid[20], bt[20], wt[20], tat[20];
    float totalWT = 0, totalTAT = 0;

    printf("Enter number of processes: ");

    if (scanf("%d", &n) != 1 || n < 1 || n > 20)
    {
        printf("Enter a number between 1 and 20.\n");
        return 1;
    }

    // Input burst times and assign process IDs.
    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        printf("Enter burst time for P%d: ", pid[i]);

        if (scanf("%d", &bt[i]) != 1 || bt[i] <= 0)
        {
            printf("Burst time must be a positive integer.\n");
            return 1;
        }
    }

    // Sort by burst time.
    // For equal burst times, keep the smaller process ID first.
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (bt[i] > bt[j] ||
                (bt[i] == bt[j] && pid[i] > pid[j]))
            {
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Same calculations as FCFS, now in sorted order.
    wt[0] = 0;

    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];

        totalWT += wt[i];
        totalTAT += tat[i];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");

    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\n",
               pid[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", totalWT / n);
    printf("Average Turnaround Time: %.2f\n", totalTAT / n);

    return 0;
}