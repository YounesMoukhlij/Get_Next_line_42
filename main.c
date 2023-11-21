#include "get_next_line.h"

#include <stdio.h>

int main()
{
	int		fd;
	char	*result;

	fd = open("text.txt", O_RDONLY);

		result = get_next_line(fd);
		printf("%s\n", result);


}
