/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 10:41:52 by youmoukh          #+#    #+#             */
/*   Updated: 2023/11/24 15:58:02 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_lookfor_newline(char *s)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*r;

	i = 0;
	if (!s)
		return (NULL);
	r = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!r)
		return (NULL);
	while (s[i])
	{
		r[i] = s[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

char	*ft_join_the_strings(char *r, char *s, char *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		r[i] = s[j];
		j++;
		i++;
	}
	j = 0;
	while (d[j])
	{
		r[i] = d[j];
		j++;
		i++;
	}
	r[i] = '\0';
	free (s);
	return (r);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*r;


	r = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!r)
		return (NULL);
	return (ft_join_the_strings(r, s1, s2));
}
