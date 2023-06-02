#include "main.h"

/**
 *  * cd_error_message - Prints an error message to stderr.
 *   * @message: Error message.
 *    */

void cd_error_message(const char *message)
{
	size_t message_len;

	message_len = my_strlen(message);
	write(STDERR_FILENO, message, message_len);
}

/**
 *  * command_error - Generates an error message for a command.
 *   * @line_no: The line number where the error occurred.
 *    * @p_name: The program name.
 *     * @cmd: The command that caused the error.
 *      *
 *       * Return: A pointer to the generated error message,
 *        *         or NULL if memory allocation fails or if num_str is NULL.
 *         */

char *command_error(int line_no, char *p_name, char *cmd)
{
	char *error_msg, num_str[12];
	int len;

	my_itoa(num_str, line_no);

	if (num_str == NULL)
	{
		return (NULL);
	}

	len = my_strlen(p_name) + my_strlen(cmd) + my_strlen(num_str) + 18;

	error_msg = malloc(sizeof(char) * (len + 1));
	if (error_msg == NULL)
		return (NULL);

	my_strcpy(error_msg, p_name);
	my_strcat(error_msg, ": ");
	my_strcat(error_msg, num_str);
	my_strcat(error_msg, ": ");
	my_strcat(error_msg, cmd);
	my_strcat(error_msg, ": not found\n");

	return (error_msg);
}

/**
 *  * print_error_message - Prints an error message to stderr.
 *   * @line_no: The line number where the error occurred.
 *    * @p_name: The program name.
 *     * @cmd: The command that caused the error.
 *      */

void print_error_message(int line_no, char *p_name, char *cmd)
{
	char *error;
	int length;

	error = command_error(line_no, p_name, cmd);
	if (error)
	{
		length = my_strlen(error);
		write(STDERR_FILENO, error, length);
		free(error);
	}
}
