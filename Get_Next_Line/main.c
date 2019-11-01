/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:51:08 by ksean             #+#    #+#             */
/*   Updated: 2019/11/01 18:34:05 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	char *line;
	int fd1;
	int fd2;

	if ((fd1 = open("OUT", O_RDONLY)) == -1)
		{
			ft_putstr("open fail\n");
			return 1;
		}
	if ((fd2 = open("itoa", O_RDONLY)) == -1)
		{
			ft_putstr("open fail\n");
			return 1;
		}
 	while ((get_next_line(fd1, &line)) > 0)
		{
			ft_putendl(line);
			free(line);
		}
	while ((get_next_line(fd2, &line)) != 0)
		{
			ft_putendl(line);
			free(line);
		}
	close(fd1);
	close(fd2);
	return 0;
}
