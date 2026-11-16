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

   
    shmid = shmget(key, 1024, 0666);

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

    printf("Data received: %s", shared);

    if (shmdt(shared) == -1)
    {
        perror("shmdt");
        return 1;
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("shmctl");
        return 1;
    }

    return 0;
}