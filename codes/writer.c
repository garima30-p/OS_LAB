#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>  

int main(void)
{
    int fd;
    char message[100];

    
    if (mkfifo("myfifo", 0666) == -1 && errno != EEXIST)
    {
        perror("mkfifo");
        return 1;
    }

    
    fd = open("myfifo", O_WRONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    printf("Enter message: ");
    fflush(stdout);

    if (fgets(message, sizeof(message), stdin) == NULL)
    {
        close(fd);
        return 1;
    }

    if (write(fd, message, strlen(message) + 1) == -1)
    {
        perror("write");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}