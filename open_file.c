#include "raise.h"

/**
 * open_file - Function that opens a file
 * @map: grid struct
 * @str: String
 */
void open_file(grid **map, char *str)
{
	char *line_buf = NULL, *token = NULL;
	size_t line_buf_size = 0, i;
	ssize_t line_size = 0;
	FILE *fp = fopen(str, "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", str);
		exit(EXIT_FAILURE);
	}
	(*map)->alt = malloc(sizeof(int) * 64);
	line_size = getline(&line_buf, &line_buf_size, fp);
	token = strtok(line_buf, " ");

	for (i = 0; token; i++)
	{
		(*map)->alt[i] = atoi(token);
		token = strtok(NULL, " ");
	}

	while (line_size >= 0)
	{
		for (; token; i++)
			(*map)->alt[i] = atoi(token), token = strtok(NULL, " ");

		line_size = getline(&line_buf, &line_buf_size, fp);
		token = strtok(line_buf, " ");
	}

	free(line_buf), line_buf = NULL, fclose(fp);
}
