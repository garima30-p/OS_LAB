#include <stdio.h>

int main(void)
{
    int pages[100], frames[20], lastUsed[20];
    int n, f;
    int faults = 0;
    int time = 0;

    printf("Enter reference string length: ");

    if (scanf("%d", &n) != 1 || n < 1 || n > 100)
    {
        printf("Enter a length between 1 and 100.\n");
        return 1;
    }

    printf("Enter reference string:\n");

    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &pages[i]) != 1 || pages[i] < 0)
        {
            printf("Enter non-negative page numbers.\n");
            return 1;
        }
    }

    printf("Enter number of frames: ");

    if (scanf("%d", &f) != 1 || f < 1 || f > 20)
    {
        printf("Enter a frame count between 1 and 20.\n");
        return 1;
    }

    for (int i = 0; i < f; i++)
    {
        frames[i] = -1;
        lastUsed[i] = -1;
    }

    printf("\nPage\tFrames\t\tResult\n");

    for (int i = 0; i < n; i++)
    {
        int found = -1;
        time++;

        // Search for the page.
        for (int j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                found = j;
                break;
            }
        }

        if (found != -1)
        {
            // Hit: update its most recent use.
            lastUsed[found] = time;
        }
        else
        {
            int position = -1;

            // Prefer an empty frame.
            for (int j = 0; j < f; j++)
            {
                if (frames[j] == -1)
                {
                    position = j;
                    break;
                }
            }

            // If full, find the least recently used frame.
            if (position == -1)
            {
                position = 0;

                for (int j = 1; j < f; j++)
                {
                    if (lastUsed[j] < lastUsed[position])
                    {
                        position = j;
                    }
                }
            }

            frames[position] = pages[i];
            lastUsed[position] = time;
            faults++;
        }

        printf("%d\t", pages[i]);

        for (int j = 0; j < f; j++)
        {
            if (frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }

        printf("\t\t%s\n", found != -1 ? "Hit" : "Fault");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    printf("Total Page Hits = %d\n", n - faults);

    return 0;
}