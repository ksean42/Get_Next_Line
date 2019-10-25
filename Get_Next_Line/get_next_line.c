/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:31:15 by ksean             #+#    #+#             */
/*   Updated: 2019/10/25 21:36:06 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_makestr(char *str)
{
	char	*s;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	s = ft_strsub(str, 0, i);
	return (s);
}

char	*ft_sub(char *str)
{
	char	*s;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if(str[i] == '\n')
		s = ft_strsub(str, (i + 1), ft_strlen(&(str[i + 1])));
	else
		return NULL;
	return (s);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static char		*out[10240];
	char			*tmp;

	if (fd < 0)
		return (-1);
	if (out[fd] == NULL)
		out[fd] = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{

		buf[ret] = '\0';
		tmp = out[fd];
		out[fd] = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_strchr(buf, '\n') != NULL)
			break ;
	}
	if (ret < 0)
			return (-1);
	if (ret > 0 || ft_strlen(out[fd]))
	{
		*line = ft_makestr(out[fd]);
		tmp = ft_sub(out[fd]);
		free((void*)out[fd]);
		out[fd] = tmp;
		return (1);
	}
	free(out[fd]);
	out[fd] = NULL;
	return (0);
}
