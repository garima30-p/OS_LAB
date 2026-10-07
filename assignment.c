#include <stdio.h>
#include <math.h>

int main()
{
    int n, levels;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of levels: ");
    scanf("%d", &levels);

    int bt[n], rem[n];
    int at[n], st[n], et[n];
    int rt[n], wt[n], tat[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter burst time of P%d: ", i);
        scanf("%d", &bt[i]);

        rem[i] = bt[i];
        at[i] = 0;
        st[i] = -1;
        et[i] = 0;
        rt[i] = 0;
        wt[i] = 0;
        tat[i] = 0;
    }

    int time = 0;

    for (int level = 1; level < levels; level++)
    {
        int tq = (int)pow(2, level);

        for (int i = 0; i < n; i++)
        {
            if (rem[i] > 0)
            {
                if (st[i] == -1)
                {
                    st[i] = time;
                    rt[i] = time - at[i];
                }

                int run;

                if (rem[i] < tq)
                    run = rem[i];
                else
                    run = tq;

                time += run;
                rem[i] -= run;

                if (rem[i] == 0)
                    et[i] = time;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (rem[i] > 0)
        {
            if (st[i] == -1)
            {
                st[i] = time;
                rt[i] = time - at[i];
            }

            time += rem[i];
            rem[i] = 0;

            et[i] = time;
        }
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = et[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nProcess\tBT\tAT\tST\tET\tRT\tWT\tTAT\n");

    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i, bt[i], at[i], st[i], et[i],
               rt[i], wt[i], tat[i]);
    }

    return 0;
}