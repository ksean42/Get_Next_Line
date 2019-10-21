/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:31:15 by ksean             #+#    #+#             */
/*   Updated: 2019/10/20 22:08:53 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_makestr(char *str)
{
	char *s;
	char *temp;
	int i;

	i = 0;
	while(str[i] != '\n' && str[i] != '\0')
		i++;
	str[i] = '\0';
	s = ft_strdup(str);
	temp = ft_strdup(&str[i + 1]);
	free((void*)str);
	str = ft_strdup(temp);
	return(s);
}

int get_next_line(int fd, char **line)  /* The return value can be 1, 0 or -1 depending on whether a
											line has been read, when the reading has been completed,
											or if an error has happened respectively.*/
{
	int				ret;
	char			buf[BUFF_SIZE+1];
	static char		*out[10240];


	if(out[fd] == NULL)
		out[fd] = ft_strnew(0);
	while(ft_strchr(out[fd], '\n') == NULL)   // return((ret == -1) ? -1 : 0);
	{
		if((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return(-1);
		buf[ret] = '\0';
		if(ret <= 0)
			break ;
		out[fd] = ft_strjoin(out[fd], buf);
	}
	if(ret > 0)
	{
		*line = ft_makestr(out[fd]);
		return (1);
	}


	return(0);
}




// if(ret == -1)
// 			return(-1);
// 		buf[ret] = '\0';
// 		if((i = ft_strnchr(buf, '\n', ret)) > 0)
// 				{
// 					out[fd] = ft_strjoin(out[fd], buf);
// 					*line = ft_strdup(out[fd]);
// 					free(out[fd]);
// 					out[fd] = ft_strsub(buf, i, ret);
// 					return(1);
// 				}
// 			else
// 					out[fd] = ft_strjoin(out[fd], buf);


// {
//  			buf[ret] = '\0';
// 			 if (ft_strnchr(buf, '\n', ret) == 1)
// 			{
// 				out[fd] = ft_strjoin(out[fd],buf);
// 				*line = ft_strdup(out[fd]);
// 				return 0;
// 			}
// 			//printf("%s/////\n", out[fd]);
// 			out[fd] = ft_strjoin(out[fd],buf);
// 		}

// int	ft_strnchr(char *s, char c)
// {
// 	int i;

// 	i = 0;
// 	while(*s)
// 	{
// 		if(*s == c)
// 		{
// 			*s = '\0';
// 			return(1);
// 		}
// 		s++;
// 	}
// 	return(-1);
// }

// void	ft_check(char *out, char **line)
// {
// 	int i;

// 	i = 0;
// 	char *tmp;
// 	while(out[i] != '\0')
// 	{
// 		if (out[i] == '\n')
// 		{
// 			out[i] = '\0';
// 			*line = ft_strdup(out)

// 		}
// 		i++;
// 	}
