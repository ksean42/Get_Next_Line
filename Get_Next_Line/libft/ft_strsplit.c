/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:37:11 by ksean             #+#    #+#             */
/*   Updated: 2019/10/08 20:05:26 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_outwords(char *s, char **dest, char c, int j)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (s[i] != c && s[i] != '\0')
	{
		a++;
		i++;
	}
	if (!(dest[j] = (char*)malloc(sizeof(char) * a + 1)))
		return (0);
	i = 0;
	while (*s != c && *s)
	{
		dest[j][i] = *s;
		s++;
		i++;
	}
	dest[j][i] = '\0';
	return (1);
}

static int				ft_words(char *s, char c)
{
	int i;
	int w;

	i = 0;
	w = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			w++;
		}
	}
	return (w);
}

static void				ft_free(char **dest, int j)
{
	while (j--)
		free(dest[j]);
	free(dest);
}

static int				ft_check(const char *s, char **dest, char c, int j)
{
	if (ft_outwords((char *)s, dest, c, j) == 0)
	{
		ft_free(dest, j);
		return (1);
	}
	return (0);
}

char					**ft_strsplit(char const *s, char c)
{
	char	**dest;
	int		j;
	int		w;

	if (s == NULL)
		return (NULL);
	w = ft_words((char*)s, c);
	j = 0;
	if (!(dest = (char**)malloc(sizeof(char*) * w + 1)))
		return (NULL);
	while (*s && j < w)
	{
		if (*s != c)
		{
			if (ft_check(s, dest, c, j) == 1)
				return (NULL);
			j++;
			while (*s != c && *s != '\0')
				s++;
		}
		s++;
	}
	dest[j] = NULL;
	return (dest);
}
