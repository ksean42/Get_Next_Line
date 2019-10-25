/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:31:15 by ksean             #+#    #+#             */
/*   Updated: 2019/10/24 18:07:22 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_makestr(char *str)
{
	char *s;
	int i = 0;

	while(str[i] != '\n')
		i++;
	s = ft_strsub(str, 0, i);
	return (s);

}

char	*ft_sub(char *str)
{
	char *s;
	int i = 0;

	while(str[i] != '\n')
		i++;
	s = ft_strsub(str, (i+1), ft_strlen(&str[i + 1]));
	return (s);

}

int get_next_line(int fd, char **line)  /* The return value can be 1, 0 or -1 depending on whether a
											line has been read, when the reading has been completed,
											or if an error has happened respectively.*/
{
	int				ret;
	char			buf[BUFF_SIZE+1];
	static char		*out[OPEN_MAX];
	char *tmp;

	if(fd < 0)
		return(-1);
	if(out[fd] == NULL)
		out[fd] = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if(ret < 0)
			return(-1);
		buf[ret] = '\0';
		tmp = out[fd];
		out[fd] = ft_strjoin(tmp, buf);
		free(tmp);
		if(ft_strchr(buf, '\n') != NULL)
			break ;
	}
	if(ret > 0 || ft_strlen(out[fd]))
	{
		*line = ft_makestr(out[fd]);
		tmp = ft_sub(out[fd]);
		free((void*)out[fd]);
		out[fd] = tmp;
		return (1);
	}
	// free(tmp);
	free(out[fd]);
	return(0);
}
