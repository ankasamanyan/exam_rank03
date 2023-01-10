#include "stdio.h"
#include "unistd.h"
#include <fcntl.h>
#include <stdlib.h>


char *get_next_line(int fd)
{
	// (void)	BUFFER_SIZE;
	size_t	BUFFER_SIZE = 1;
	char *string = malloc(100000);
	char *copy = string;
	while(read(fd, copy, BUFFER_SIZE) > 0 && *copy++ != '\n');
	if (copy != string)
	{
		*copy = 0;
		return string;
	}
	free(string);
	return (NULL);
}


int main()
{
	int fd = open("testy.txt", R_OK);
	if (fd == -1)
		return 1;
	char *stringy = get_next_line(fd);
	while(stringy != NULL)
	{
		printf("%s", stringy);
		stringy = get_next_line(fd);

	}
}