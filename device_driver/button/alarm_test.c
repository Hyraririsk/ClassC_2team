#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int fd;
    char buf[10];
    int ret;

    fd = open("/dev/mydev", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    printf("Waiting for button interrupt... (press key)\n");

    while (1) {
        ret = read(fd, buf, sizeof(buf));
        if (ret < 0) {
            perror("read");
            break;
        }

        printf("read() returned! ret=%d, value=%d\n", ret, buf[0]);
    }

    close(fd);
    return 0;
}
