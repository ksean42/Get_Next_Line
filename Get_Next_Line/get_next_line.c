/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:31:15 by ksean             #+#    #+#             */
/*   Updated: 2019/10/12 22:13:56 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strnchr(char *s, char c, size_t n)
{
	while(n > 0)
		{
			if(*s == c)
				{
					*s = '\0';
					return (1);
				}
			// if (*s == '\0')
			// 	return 	(0);
			s++;
			n--;
		}
		return (-1);
}

// int	ft_makestr(char *buf, char **line)
// {
// 	char *i;

// 	i = ft_strchr(buf, '\n');
// 	i = '\0';
// 	ft_strcpy(*line, buf);
// 	return 1;
// }

int get_next_line(int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE+1];
	static char		*out[10240];


	if(!(out[fd] = ft_strnew(0)))
		return (-1);
	while ((ret = read(fd,buf, BUFF_SIZE)) > 0)
		{
 			buf[ret] = '\0';
			 if (ft_strnchr(buf, '\n', ret) == 1)
			{
				out[fd] = ft_strjoin(out[fd],buf);
				*line = ft_strdup(out[fd]);
				return 0;
			}
			//printf("%s/////\n", out[fd]);
			out[fd] = ft_strjoin(out[fd],buf);
		}


	return(1);
}
// if(ft_strnchr(buf, '\n', ret) == 1)
// 					ft_strcpy(*line,buf);
// 			else
// 				ft_strcpy(*line,buf);
// 			return(1);































// int get_next_line(int fd, char **line)
// {
// 	int				ret;
// 	char			buf[BUFF_SIZE+1];
// 	static char		*out[10000];
// 	size_t i = 0;

// 	out[fd] = ft_strnew(1);
// 	while((ret = read(fd,buf,BUFF_SIZE)) > 0)
// 		{
// 			while(i != ret)
// 				{
// 					if(buf[i] == '\n')
// 						{
// 							buf[i] = '\0';
// 							break ;
// 						}
// 					i++;
// 				}
// 				buf[ret] = '\0';
// 			out[fd] = ft_strjoin(out[fd], buf);

// 			i = 0;
// 		}
// 		*line = ft_strjoin(*line,out[fd]);
// 	return(-1);
// }
