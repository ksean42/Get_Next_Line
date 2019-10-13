/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:51:08 by ksean             #+#    #+#             */
/*   Updated: 2019/10/13 18:54:41 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	char *line;
	int fd;
	//int a;

	line = ft_strnew(28348);
	if((fd = open("OUT1", O_RDONLY)) == -1)
		{
			ft_putstr("open fail\n");
			return 1;
		}

	while((get_next_line(fd, &line)) != 1)
		ft_putendl(line);
	// printf("%i", a);
	close(fd);
	return 0;
}
