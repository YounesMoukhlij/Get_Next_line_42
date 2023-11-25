/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:29:24 by youmoukh          #+#    #+#             */
/*   Updated: 2023/11/25 13:51:23 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>

char	*get_next_line(int fd);
char	*ft_strdup(char *s);
int		ft_lookfor_newline(char *s);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif