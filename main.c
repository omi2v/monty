#include "monty.h"
glo_t glo;
/**
* main - reads a monty file and executes line by line
* @argc: argument counter
* @argv: argument vector
* Return: 0
*/

int main(int argc, char **argv)
{
	stack_t *head = NULL;
	ssize_t lines;
	int check;
	size_t line_buff_size = 0;
	unsigned int counter = 0;

	glo.line_buff = NULL;
	glo.bigb = NULL;

	argc_check(argc);

	glo.fp = fopen(argv[1], "r");
	open_check(argv);

	lines = getline(&glo.line_buff, &line_buff_size, glo.fp);
	line_check(lines);

	while (lines >= 0)
	{
		glo.bigb = NULL;
		counter++;
		glo.bigb = parse_line();
		if (glo.bigb[1] != NULL)
			glo.node_data = atoi(glo.bigb[1]);
		check = get_opcode(&head, counter);

		op_check(check, counter);
		lines = getline(&glo.line_buff, &line_buff_size, glo.fp);
	}
	free(glo.bigb);
	free(glo.line_buff);
	fclose(glo.fp);
	free(head);
	return (0);
}
