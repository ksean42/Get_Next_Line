/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:31:15 by ksean             #+#    #+#             */
/*   Updated: 2019/10/10 19:21:37 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE+1];
	static char		*out[1200];
	size_t i = 0;

	if((ret = read(fd,buf,BUFF_SIZE)) != -1)
		{
			while(i != BUFF_SIZE+1)
				{
					if(buf[i] == '\n' || buf[i] == '\0')
						break ;
					i++;
				}
			buf[i] = '\0';
			out[fd] = ft_strnew(i);
			ft_strcpy(out[fd], &buf[0]);
			*line = ft_strjoin(*line,out[fd]);
			return(0);
		}
	return(-1);
}
