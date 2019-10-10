/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:51:08 by ksean             #+#    #+#             */
/*   Updated: 2019/10/10 22:41:09 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	char *line;
	int fd;
	int a;

	line = ft_strnew(28348);
	if((fd = open("itoa", O_RDONLY)) == -1)
		ft_putstr("open fail\n");
	// while((a = get_next_line(fd, &line)) != 0)
	// 	{
	// 		get_next_line(fd,&line);
	// 		if(a == -1)
	// 			{
	// 				ft_putstr("ERROR");
	// 				return (-1);
	// 			}
	// 	}
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	ft_putstr(line);
	//printf("%i", a);
	close(fd);
	return 0;
}
