nclude <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char *my_getline(void) {
    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    char buffer[BUFFER_SIZE];
    size_t buffer_pos = 0;
    int exit_command = 0;

    while ((linelen = read(STDIN_FILENO, buffer + buffer_pos, BUFFER_SIZE - buffer_pos)) > 0) {
        buffer_pos += linelen;
        if (buffer_pos >= BUFFER_SIZE) {
            printf("Error: input line too long\n");
            exit(1);
        }
        if (buffer[buffer_pos-1] == '\n') {
            break;
        }
    }

    if (linelen == -1) {
        perror("read");
        exit(1);
    }

    if (buffer_pos == 0 && linelen == 0) {
        exit_command = 1;
    }

    if (exit_command) {
        exit(0);
    }

    line = malloc(buffer_pos + 1);
    if (line == NULL) {
        printf("Error: memory allocation failed\n");
        exit(1);
    }

    memcpy(line, buffer, buffer_pos);
    line[buffer_pos] = '\0';

    return line;
}

int main() {
    char *line;

    while (1) {
        printf("Enter a line of text (or type 'exit' to quit): ");
        line = my_getline();

        if (strcmp(line, "exit\n") == 0) {
            printf("Goodbye!\n");
            free(line);
            exit(0);
        }

        printf("You entered: %s", line);
        free(line);
    }

    return 0;
}
