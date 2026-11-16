#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message
{
    long type;
    char text[100];
};

int main(void)
{
    key_t key;
    int msgid;
    struct message msg;

    key = ftok(".", 'A');

    if (key == (key_t)-1)
    {
        perror("ftok");
        return 1;
    }

    msgid = msgget(key, 0666 | IPC_CREAT);

    if (msgid == -1)
    {
        perror("msgget");
        return 1;
    }

    if (msgrcv(msgid, &msg, sizeof(msg.text), 1, 0) == -1)
    {
        perror("msgrcv");
        return 1;
    }

    printf("Received: %s", msg.text);

    if (msgctl(msgid, IPC_RMID, NULL) == -1)
    {
        perror("msgctl");
        return 1;
    }

    return 0;
}