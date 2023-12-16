#include "shell.h"

/**
 * fetch_line - assigns the buffer variable to custom_getline
 * @line: buffer that stores the string entered by the user
 * @buf: string called to line
 * @line_size: size of the line
 * @buf_size: size of the buffer
 *
 */

void fetch_line(char **line, size_t *line_size, char *buf, size_t buf_size)
{
	if (*line == NULL)
	{
		if (buf_size > BUFSIZE)
			*line_size = buf_size;
		else
			*line_size = BUFSIZE;
		*line = buf;
	}
	else if (*line_size < buf_size)
	{
		if (buf_size > BUFSIZE)
			*line_size = buf_size;
		else
			*line_size = BUFSIZE;
		*line = buf;
	}
	else
	{
		_strcpy(*line, buf);
		free(buf);
	}
}

/**
 * custom_getline - reads input from stdin
 * @line: buffer that stores the string entered by the user
 * @line_size: size of line
 * @stream: stream to read input from
 *
 * Return: number of bytes used
 */
ssize_t custom_getline(char **line, size_t *line_size, FILE *stream)
{
	int s;
	static ssize_t in;
	ssize_t result;
	char *buf, c = 'z';

	if (in == 0)
		fflush(stream);
	else
		return (-1);
	in = 0;
	buf = malloc(sizeof(char) * BUFSIZE);
	if (buf == 0)
		return (-1);
	while (c != '\n')
	{
		s = read(STDIN_FILENO, &c, 1);
		if (s == -1 || (s == 0 && in == 0))
		{
			free(buf);
			return (-1);
		}
		if (s == 0 && in != 0)
		{
			in++;
			break;
		}
		if (in >= BUFSIZE)
			buf = custom_realloc(buf, in, in + 1);
		buf[in] = c;
		in++;
	}
	buf[in] = '\0';
	fetch_line(line, line_size, buf, in);
	result = in;
	if (s != 0)
		in = 0;
	return (result);
}
