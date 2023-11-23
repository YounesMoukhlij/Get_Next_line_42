/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:56:15 by youmoukh          #+#    #+#             */
/*   Updated: 2023/11/23 18:56:50 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_the_line(char *s)
{
	char	*new_str;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	new_str = malloc(i + 2);
	if (!new_str)
		return (NULL);
	while (*s && *s != '\n')
		*(new_str++) = *(s++);
	if (*s == '\n')
	{
		*new_str = *s;
		new_str++;
	}
	*new_str = '\0';
	return (new_str);
}

char	*ft_read_from_fd(char *str, int fd)
{
	char	*my_buffer;
	int		i;

	i = 1;
	while (ft_lookfor_newline(str) == 1 && i != 0)
	{
		my_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!my_buffer)
			return (NULL);
		i = read(fd, my_buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(my_buffer);
			free(str);
			return (NULL);
		}
		str = ft_strjoin(str, my_buffer);
		free(my_buffer);
		if (!str)
		{
			free(str);
			return (NULL);
		}
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*get_line;
	char		*s;

	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	str = ft_read_from_fd(str, fd);
	if (!str)
		return (NULL);
	get_line = ft_get_the_line(str);
	if (!get_line)
		return (NULL);
	s = str;
	str = ft_strdup(str + ft_strlen(get_line));
	free(s);
	return (get_line);
}
