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

char	*ft_strjoin(char *s1, char *s2)
{
	char		*dest;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dest = (char*)malloc(sizeof(*dest) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	
	while (s2[++j])
		dest[i++] = s2[j];
	dest[i] = '\0';
	free (s1);
	free (s2);
	return (dest);
}

char	*ft_cut(char *src)
{
	int		i;
	char		*t;

	i = 0;
	if (ft_strchr(src, '\n') == NULL)
		return (src);
	while (src[i] != '\n')
		i++;
	t = (char *)malloc(i + 2);
	i = 0;
	while(src[i])
	{
		t[i] = src[i];
		if(src[i] == '\n')
			break ;
		i++;
	}
	i++;
	t[i] = '\0';
	free (src);
	return (t);
}
