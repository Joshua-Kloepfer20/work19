#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main() {
    int fd1 = open("work19pipe1", O_RDONLY);
    int fd2 = open("work19pipe2", O_WRONLY);
    while (1) {
        char input[200];
        int x = read(fd1, input, 200);
        input[x-1] = '\0';
        int i;
        for (i = 0; i < strlen(input); i++) {
            input[i] = input[i] + 1;
        }
        write(fd2, input, 200);
    }
	return 0;
}