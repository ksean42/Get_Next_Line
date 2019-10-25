/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:51:08 by ksean             #+#    #+#             */
/*   Updated: 2019/10/25 21:25:53 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	char *line;
	int fd1;
	int fd2 = 0;
	//int a;

	//line = ft_strnew(28348);
	if((fd1 = open("gnl7_2.txt", O_RDONLY)) == -1)
		{
			ft_putstr("open fail\n");
			return 1;
		}
	// if((fd2 = open("itoa", O_RDONLY)) == -1)
	// 	{
	// 		ft_putstr("open fail\n");
	// 		return 1;
	// 	}
	// int fd3 = -1;
 	while((get_next_line(fd1, &line)) > 0)
		{
			fd2++;
			ft_putendl(line);
			free(line);

		}
	ft_putnbr(fd2);
	// while((get_next_line(fd2, &line)) != 0)
	// 	{
	// 		ft_putendl(line);
	// 		free(line);
	// 	}

	// get_next_line(fd1, &line);
	// 	ft_putendl(line);
	// get_next_line(fd2, &line);
	// 	ft_putendl(line);
	// get_next_line(fd1, &line);
	// 	ft_putendl(line);
	// get_next_line(fd1, &line);
	// 	ft_putendl(line);
	// get_next_line(fd1, &line);
	// 	ft_putendl(line);
	// get_next_line(fd2, &line);
	// 	ft_putendl(line);
	// get_next_line(fd2, &line);
	// 	ft_putendl(line);
	// get_next_line(fd2, &line);
	// 	ft_putendl(line);
	// get_next_line(-3, &line);
	// 	ft_putendl(line);
	// get_next_line(fd, &line);
	// 	ft_putendl(line);
	// get_next_line(fd, &line);
	// 	ft_putendl(line);
	// get_next_line(fd, &line);
	// 	ft_putendl(line);
	// get_next_line(fd, &line);
	// 	ft_putendl(line);
	// get_next_line(fd, &line);
	// 	ft_putendl(line);
	// get_next_line(fd, &line);
	// 	ft_putendl(line);
	// printf("%i", a);
	close(fd1);
	close(fd2);
	return 0;
}
