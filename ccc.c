/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:29:02 by youmoukh          #+#    #+#             */
/*   Updated: 2023/11/20 15:14:51 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    ft_free(char str, char buff)
{
    free (str);
    free (buff);
}

static    char    ft_read(int fd, char str)
{   
    char    *buff;
    int        br;

    br = 1;
    while (!ft_strchr(str, '\n') && (br != 0))
    {
        buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!buff)
            return (NULL);
        br = read(fd, buff, BUFFER_SIZE);
        if (br == -1)
        {
            ft_free (str, buff);
            return (NULL);
        }
        buff[br] = '\0';
        str = ft_strjoin(str, buff);
        free(buff);
    }
    if (!ft_strlen(str))
    {
        free (str);
        return (NULL);
    }
    return (str);
}

static char    ft_get_line(char str)
{
    int        len;
    int        i;
    char    s;

    i = 0;
    len = 0;
    if (!str[i])
        return (NULL);
    while (str[len] && str[len] != '\n')
        len++;
    s = malloc(sizeof(char) (len + 2));
    if (!s)
        return (NULL);
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

char    *get_next_line(int fd)
{
    static char    *string;
    char        *line;  
    
    char        *s;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!string)
        string = ft_strdup("");
    string = ft_read(fd, string);
    if (!string)
        return (NULL);
    line = ft_get_line(string);
    if (!line)
        return (NULL);
    s = string;
    string = ft_strdup(string + ft_strlen(line));
    free(s);
    return (line);
}

