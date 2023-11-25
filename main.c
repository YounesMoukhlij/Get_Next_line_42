/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:08:11 by youmoukh          #+#    #+#             */
/*   Updated: 2023/11/25 15:15:02 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void leaks(void)
// {
// 	system("leaks a.out");
// atexit(leaks);
// }


int	main(void)
{
	int		fd;
	char	*s;

	fd = open("text.txt", O_RDONLY);
	s = get_next_line(fd);

	printf("%s", s);

	s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);

	printf("%s", s);

	free(s);
}
