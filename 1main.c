/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:08:11 by youmoukh          #+#    #+#             */
/*   Updated: 2023/11/24 18:07:26 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void leaks(void)
{
	system("leaks a.out");
}


int	main(void)
{
	int		fd;
	char	*s;

	fd = open("text.txt", O_RDONLY);
	s = get_next_line(fd);

	printf("%s", s);


	free(s);

	atexit(leaks);
}
