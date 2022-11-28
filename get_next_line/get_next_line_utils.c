/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:15:54 by dballini          #+#    #+#             */
/*   Updated: 2022/11/25 16:15:54 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*memory;
	size_t	i;

	i = 0;
	memory = malloc(count * size);
	if (memory == NULL)
		return (0);
	while (i < count * size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	j = -1;
	i = -1;
	p = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (p == 0)
		return (NULL);
	while (s1[++i])
		p[i] = s1[i];
	while (s2[++j])
	{
		p[i] = s2[j];
		i++;
	}
	p[i] = '\0';
	free((char *)s1);
	free((char *)s2);
	return (p);
}

char	*ft_cut(char *extra)
{
	char		*ret;
	int			i;

	i = 0;
	ret = (char *)ft_calloc(ft_strlen(extra) + 1, 1);
	if (!ret)
		return (NULL);
	while (*extra)
	{
		if (*extra != '\n')
		{
			ret[i] = *extra;
			i++;
		}
		else
		{
			ret[i] = *extra;
			break ;
		}
		extra++;
	}
	i++;
	ret[i] = '\0';
	return (ret);
}
