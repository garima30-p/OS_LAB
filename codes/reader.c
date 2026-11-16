#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>   

int main(void)
{
    int fd;
    char buffer[100];
    ssize_t n;

    fd = open("myfifo", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    n = read(fd, buffer, sizeof(buffer) - 1);

    if (n == -1)
    {
        perror("read");
        close(fd);
        return 1;
    }

    buffer[n] = '\0';
    printf("Received: %s", buffer);

    close(fd);
    unlink("myfifo");

    return 0;
}