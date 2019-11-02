/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:51:08 by ksean             #+#    #+#             */
/*   Updated: 2019/11/01 23:23:58 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int argc, char **argv)
{
	char *line;
	int fd1;

	if (argc == 2)
	{
		if ((fd1 = open(argv[1], O_RDONLY)) == -1)
		{
			ft_putstr("open fail\n");
			return 1;
		}

		while ((get_next_line(fd1, &line)) > 0)
			{
				ft_putendl(line);
				free(line);
			}
		close(fd1);
	}
	return 0;
}
