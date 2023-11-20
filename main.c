#include "get_next_line.h"

int main()
{
	int		fd;
	char	buff[20];
	char	*result;


	fd = open("text.txt", O_RDWR | O_APPEND);

	get_next_line(fd);

}
