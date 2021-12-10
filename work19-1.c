#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
    mkfifo("work19pipe1", 0644);
    mkfifo("work19pipe2", 0644);

    int fd1 = open("work19pipe1", O_WRONLY);
    int fd2 = open("work19pipe2", O_RDONLY);
    while (1) {
        char input[200];
        printf("input a string: ");
        fgets(input, 200, stdin);
        write(fd1, input, strlen(input));
        char output[200];
        read(fd2, output, 200);
        printf("output: %s\n", output);
    }
	return 0;
}