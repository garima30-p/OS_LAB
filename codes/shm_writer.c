#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
    key_t key;
    int shmid;
    char *shared;

    key = ftok(".", 'S');

    if (key == (key_t)-1)
    {
        perror("ftok");
        return 1;
    }

    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    if (shmid == -1)
    {
        perror("shmget");
        return 1;
    }

    shared = shmat(shmid, NULL, 0);

    if (shared == (void *)-1)
    {
        perror("shmat");
        return 1;
    }

    printf("Enter data: ");
    fflush(stdout);

    if (fgets(shared, 1024, stdin) == NULL)
    {
        shmdt(shared);
        return 1;
    }

    printf("Data written to shared memory.\n");

    if (shmdt(shared) == -1)
    {
        perror("shmdt");
        return 1;
    }

    return 0;
}