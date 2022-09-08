#include "monty.h"
glo_t glo;
/**
 * parse_line - tokenizes the line
 * @line: the line
 * Return: an array of strings that holds the line and an argument if necessary
 */

char **parse_line()
{
	char **big_buff = malloc(10 * (sizeof(char *)));
	char *token;
	int i = 0;

	if (!big_buff)
	{
		dprintf(2, "Error: malloc failed\n");
		free(glo.line_buff);
		fclose(glo.fp);
		exit(EXIT_FAILURE);
	}

	while (glo.line_buff[i])
		i++;

	if (glo.line_buff[i - 1] == '\n')
		glo.line_buff[i - 1] = '\0';

	token = strtok(glo.line_buff, " \t");
	i = 0;
	while (token)
	{
		big_buff[i] = token;
		i++;
		token = strtok(NULL, " \t");
	}
	big_buff[i] = NULL;
	return (big_buff);
}
