/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:51:08 by ksean             #+#    #+#             */
/*   Updated: 2019/10/11 18:39:41 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	char *line;
	int fd;
	int a;

	line = ft_strnew(28348);
	if((fd = open("OUT", O_RDONLY)) == -1)
		{
			ft_putstr("open fail\n");
			return 1;
		}

	get_next_line(fd, &line);
	ft_putstr(line);
	ft_putchar('\n');
	// get_next_line(fd, &line);
	// ft_putstr(line);
	// ft_putchar('\n');
	// printf("%i", a);
	close(fd);
	return 0;
}
