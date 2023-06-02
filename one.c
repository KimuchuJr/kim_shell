#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 100

/**
 * main - Entry point for the simple shell program
 *
 * Return: Always returns 0
 */
int main(void)
{
	 pid_t pid = fork();

    while (1) {
        char input[MAX_INPUT_LENGTH];

        /* Display prompt and read input */
        printf("$ ");
        fgets(input, MAX_INPUT_LENGTH, stdin);

        /* Check for end of file */
        if (feof(stdin)) {
            break;
        }

        /* Remove trailing newline character */
        input[strcspn(input, "\n")] = '\0';

        /* Fork a child process to execute the command */
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            /* Child process */
            if (execlp(input, input, (char *) NULL) == -1) {
                perror(input);
                exit(EXIT_FAILURE);
            }
        } else {
            /* Parent process */
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return (0);
}

