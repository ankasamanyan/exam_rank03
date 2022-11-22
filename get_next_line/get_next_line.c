#include "get_next_line.h"

char	*get_next_line(int fd)
{
    // (void)BUFFER_SIZE;

	char	*ret = malloc(9999);
	char	c;
	int		i = 0;
	int		read_ret = 0;

	if (fd < 0)
		return (NULL);
	while ((read_ret = read(fd, &c, BUFFER_SIZE)) > 0)
	{
		ret[i] = c;
		i++;
		if (c == '\n')
			break ;
	}
	if (i == 0 || read_ret < 0)
	{
		free(ret);
		return (NULL);
	}
	ret[i] = '\0';
	return (ret);
}

int		main(int argc, char **argv)
{
	int 	fd = 0;
	char	*line;

	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("line |%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}