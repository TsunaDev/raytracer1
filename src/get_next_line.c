/*
** EPITECH PROJECT, 2017
** raytracer1
** File description:
** get next line of fd
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"get_next_line.h"

int		check(int i, int bytes, char *buffer)
{
	if (i != bytes || (i == bytes && bytes < READ_SIZE) ||
	    buffer[i - 1] == '\n')
		return (1);
	else
		return (0);
}

int		get_return(char *buffer)
{
	int		i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (i != READ_SIZE)
		i++;
	return (i);
}

int		my_strcpy(char *line, int i, char *buff, int bytes)
{
	int		j;

	j = 0;
	while (i < bytes && buff[i] != '\n') {
		line[j] = buff[i];
		j++;
		i++;
	}
	line[j] = '\0';
	return (i);
}

char		*my_realloc(char *line, char *buffer, int len, int j)
{
	int		base_len = 0;
	char		*tmp;
	int		i = 0;


	while (line[base_len] != '\0')
		base_len++;
	if ((tmp = malloc(sizeof(char) * (base_len + len + 1))) == NULL)
		return (NULL);
	for (i = 0; line[i]; i++)
		tmp[i] = line[i];
	while (buffer[j] != '\n' && buffer[j] != '\0') {
		tmp[i] = buffer[j];
		i++;
		j++;
	}
	free(line);
	tmp[i] = '\0';
	return (tmp);
}

char				*get_next_line(const int fd)
{
	static t_next_line	gline;
	char			*line = malloc(sizeof(char) * (READ_SIZE + 1));

	if (!line)
		return (NULL);
	line[0] = 0;
	if (fd >= 0 && gline.buff[0] != '\0' && gline.i < gline.bytes) {
		gline.i = my_strcpy(line, gline.i, gline.buff, gline.bytes);
		if ((gline.buff[gline.i] == '\n' || gline.buff[gline.i] == '\0') &&
		(gline.i < gline.bytes || gline.bytes < READ_SIZE) &&
		gline.i++ >= 0)
			return (line);
	}
	gline.i = 0;
	while (fd >= 0 && (gline.bytes = read(fd, gline.buff, READ_SIZE)) > 0) {
		gline.buff[gline.bytes] = '\0';
		gline.i = get_return(gline.buff);
		line = my_realloc(line, gline.buff, gline.i, 0);
		if (check(gline.i, gline.bytes, gline.buff) || gline.buff[0] == '\n')
			return (line);
	}
	return ((gline.i != 0) ? (line) : (NULL));
}
