
#include "get_next_line.h"

char	*ft_get_lines(int fd)
{

}

char	*ft_read_lines(char *str, int fd)
{
	char	*buffer;
	int		i;

	i = 1;
	while (!ft_strchr(str, '\n') && !i)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (0);
		str = ft_strjoin(str, buffer);
	}

}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*get_line;
	int			line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	if (!str)
		str = ft_strdup("");
	str = ft_read_lines(str, fd);
	if (!str)
		return (ft_free(str));
	get_line = ft_get_lines(str);
	if (!get_line)
		return (ft_free(get_line));

}
