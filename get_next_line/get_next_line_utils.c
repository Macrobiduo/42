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
	memory =(char *)malloc(count * size);
	if (memory == NULL)
		return (0);
	while (i < count * size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}

char		*ft_strjoin(char *s1, char *s2)
 {
 	char	*dst;
 	char	*cpy;
 
 	dst = (char *)malloc(sizeof(dst) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst && s1 && s2)
	{
		cpy = dst;
		while (*s1 != '\0')
			*dst++ = *s1++;
		while (*s2 != '\0')
			*dst++ = *s2++;
		*dst = '\0';
	}
	else
		return (NULL);
	return (cpy);
}

char	*ft_cut(char *src)
{
	int		i;
	char		*p;

	i = 0;
	if (ft_strchr(src, '\n') == NULL)
		return (src);
	while (src[i] && src[i] != '\n')
		i++;
	p = malloc (i + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (src[i])
	{
		p[i] = src[i];
		if (src[i] == '\n')
			break ;
		i++;
	}
	return (p);
}
