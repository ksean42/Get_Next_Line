/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:31:15 by ksean             #+#    #+#             */
/*   Updated: 2019/10/11 18:58:11 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE+1];
	static char		*out[10000];
	size_t i = 0;

	out[fd] = ft_strnew(1);
	while((ret = read(fd,buf,BUFF_SIZE)) > 0)
		{
			while(i != BUFF_SIZE)
				{
					if(buf[i] == '\n')
						{
							buf[i] = '\0';
							break ;
						}
					i++;
				}
				buf[ret] = '\0';
			out[fd] = ft_strjoin(out[fd], buf);

			i = 0;
		}
		*line = ft_strjoin(*line,out[fd]);
	return(-1);
}
