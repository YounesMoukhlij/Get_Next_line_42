/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:06:53 by youmoukh          #+#    #+#             */
/*   Updated: 2023/11/21 21:29:09 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char *s)
{
	free(s);
	return (NULL);
}

static char	*ft_get_lines(char *str)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	s = malloc(sizeof(char) * (len + 2));
	if (!s)
		return (0);
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*ft_read_lines(char *str, int fd)
{
	char	*buffer;
	int		i;

	i = 1;
	while (!ft_lookfor_newline(str) && !i)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (0);
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
		free(buffer);
		// if (!ft_strlen(str))
		// {
		// 	free (str);
		// 	return (NULL);
		// }
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*get_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	str = ft_read_lines(str, fd);
	if (!str)
		return (ft_free(str));
	get_line = ft_get_lines(str);
	if (!get_line)
		return (ft_free(get_line));
	get_line = ft_strdup(str + ft_strlen(get_line));
	return (get_line);
}
