/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:08:11 by youmoukh          #+#    #+#             */
/*   Updated: 2023/11/25 18:34:51 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <stdio.h>
# include <fcntl.h>

// void leaks(void)
// {
// 	system("leaks a.out");
// atexit(leaks);
// }


int	main(void)
{
	int		fd;
	int		fd1;
	char	*s = "";
	char	*d = "";

	fd = open("text.txt", O_RDONLY);
	
	fd1 = open("dra.txt", O_RDONLY);


	while (s)
	{
		s = get_next_line(fd);
		printf("%s", s);
	}
	while (d)
	{
		d = get_next_line(fd1);
		printf("%s", d);
	}

}
