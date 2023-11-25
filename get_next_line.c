/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:56:15 by youmoukh          #+#    #+#             */
/*   Updated: 2023/11/25 14:19:46 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_the_rest_helper(char *rest_of, char *str, int i)
{
	int	j;

	j = 0;
	while (str[i])
	{
		rest_of[j] = str[i];
		i++;
		j++;
	}
	rest_of[j] = '\0';
	free(str);
	return (rest_of);
}

static char	*ft_get_the_rest(char *str)
{
	int		i;
	char	*rest_of;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	rest_of = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!rest_of)
		return (free(str),str = NULL, NULL);
	return (get_the_rest_helper(rest_of, str, i + 1));
}

static char	*ft_get_the_line(char *s)
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
		//return (free(s), s = NULL, NULL);
	j = 0;
	while (j < i)
	{
		new_str[j] = s[j];
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

static char	*ft_read_from_fd(char *str, int fd)
{
	char	*my_buffer;
	int		i;

	i = 1;
	while (ft_lookfor_newline(str) && i > 0)
	{
		my_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!my_buffer)
			return (free(str) , str = NULL, NULL);
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
	{
		free (str);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*get_line;

	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE > INT_MAX || fd >= OPEN_MAX)
		return (NULL);
	if (!str)
	{
		str = malloc(1);
		if (!str)
		{
			return (free(str) ,NULL);
		}
		str[0] = '\0';
	}
	str = ft_read_from_fd(str, fd);
	if (!str)
		return (free(str), str = NULL, NULL);
	get_line = ft_get_the_line(str);
	if (!get_line)
		return (free(str), str = NULL, NULL);
	str = ft_get_the_rest(str);
	return (get_line);
}
