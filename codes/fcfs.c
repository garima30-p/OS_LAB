#include <stdio.h>

int main(void)
{
    int n;
    int bt[20], wt[20], tat[20];
    float totalWT = 0, totalTAT = 0;

    printf("Enter number of processes: ");

    if (scanf("%d", &n) != 1 || n < 1 || n > 20)
    {
        printf("Enter a number between 1 and 20.\n");
        return 1;
    }

    // Input burst times
    for (int i = 0; i < n; i++)
    {
        printf("Enter burst time for P%d: ", i + 1);

        if (scanf("%d", &bt[i]) != 1 || bt[i] <= 0)
        {
            printf("Burst time must be a positive integer.\n");
            return 1;
        }
    }

    // The first process starts immediately
    wt[0] = 0;

    // Calculate waiting times
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate turnaround times and totals
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
               i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", totalWT / n);
    printf("Average Turnaround Time: %.2f\n", totalTAT / n);

    return 0;
}