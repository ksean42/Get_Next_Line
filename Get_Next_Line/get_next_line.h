/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:48:50 by ksean             #+#    #+#             */
/*   Updated: 2019/10/11 17:39:39 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
# define BUFF_SIZE 40
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

int	get_next_line(const int fd, char **line);

#endif
/*TODO 1)REPLACE HEADER*/
