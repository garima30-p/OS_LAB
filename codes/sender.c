#include <stdio.h>
#include <string.h>
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

    msg.type = 1;

    printf("Enter message: ");
    fflush(stdout);

    if (fgets(msg.text, sizeof(msg.text), stdin) == NULL)
        return 1;

    if (msgsnd(msgid, &msg, strlen(msg.text) + 1, 0) == -1)
    {
        perror("msgsnd");
        return 1;
    }

    printf("Message sent.\n");

    return 0;
}