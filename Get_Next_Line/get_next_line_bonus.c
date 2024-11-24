/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:24:42 by youmoukh          #+#    #+#             */
/*   Updated: 2023/11/27 15:43:07 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_the_rest(char *str)
{
	int		i;
	int		j;
	char	*rest_of;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	rest_of = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!rest_of)
		return (free(str), str = NULL, NULL);
	i++;
	while (str[i])
		rest_of[j++] = str[i++];
	rest_of[j] = '\0';
	free(str);
	return (rest_of);
}

char	*ft_get_the_line(char *s)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	new_str = malloc(i + 1);
	if (!new_str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_str[j] = s[j];
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

char	*ft_read_from_fd(char *str, int fd, int i)
{
	char	*my_buffer;

	while (ft_lookfor_newline(str) && i > 0)
	{
		my_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!my_buffer)
			return (free(str), str = NULL, NULL);
		i = read(fd, my_buffer, BUFFER_SIZE);
		if (i < 0)
			return (free(str), free(my_buffer), NULL);
		if (i == 0)
		{
			free(my_buffer);
			break ;
		}
		my_buffer[i] = '\0';
		str = ft_strjoin(str, my_buffer);
		if (!str)
			return (free(my_buffer), NULL);
		free(my_buffer);
	}
	if (!ft_strlen(str))
		return (free(str), NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*get_line;
	int			indice;

	indice = 1;
	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE >= INT_MAX || fd >= OPEN_MAX)
		return (NULL);
	if (!str[fd])
	{
		str[fd] = ft_strdup("");
		if (!str[fd])
		{
			return (free(str[fd]), NULL);
		}
	}
	str[fd] = ft_read_from_fd(str[fd], fd, indice);
	if (!str[fd])
		return (free(str[fd]), str[fd] = NULL, NULL);
	get_line = ft_get_the_line(str[fd]);
	if (!get_line)
		return (free(str[fd]), str[fd] = NULL, NULL);
	str[fd] = ft_get_the_rest(str[fd]);
	return (get_line);
}
