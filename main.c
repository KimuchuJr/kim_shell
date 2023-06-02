include "main.h"

/**
 *  * main- entry point
 *   * @argc: argument count
 *    * @argv: argument vector
 *     * Return: 0 (success) always
 *      */

int main(int argc, char **argv)
{
	char *input = NULL;
	char **commands = NULL;
	int status, line_no, mode;

	status = 1;
	line_no = 1;
	mode = 0;
	(void)argc;
	signal(SIGINT, signal_handler);
	while (status)
	{
		mode = print_prompt();
		input = get_input();
		commands = split_tokens(input);

		if (!commands || !*commands || **commands == '\0')
		{
			free(input);
			/* free_bufs(commands); */
			line_no++;
			continue;
		}
		free(input);
		status = execute_commands(commands, line_no, argv[0]);

		/* if wrong command is entered in non-interactive mode */
		if (status == 127 && mode == 0)
			break;
		free_bufs(commands);
		line_no++;
	}

	if (status == 127)
	{
		free_bufs(commands);
		exit(127);
	}

	return (0);
}
