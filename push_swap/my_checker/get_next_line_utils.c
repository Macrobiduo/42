/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:15:54 by dballini          #+#    #+#             */
/*   Updated: 2023/02/22 14:57:42 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_ordered(t_list *a)
{
	while (a->next)
	{
		if (a->number > a->next->number)
			return (0);
		a = a->next;
	}
	return (1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
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

char	*ft_strjoin(char *s1, char *s2)
{
	char		*dst;
	int			i;
	int			j;

	i = -1;
	j = -1;
	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (dst && s1 && s2)
	{
		while (s1[++i])
			dst[i] = s1[i];
		while (s2[++j])
			dst[i + j] = s2[j];
		dst[i + j] = '\0';
	}
	else
		return (NULL);
	free (s1);
	free (s2);
	return (dst);
}

char	*ft_cut(char *src)
{
	int			i;
	char		*p;

	i = 0;
	if (ft_strchr(src, '\n') == NULL)
		return (src);
	while (src[i] && src[i] != '\n')
		i++;
	if (src[i] == '\n')
		i++;
	p = malloc (i + 1);
	if (!p)
		return (NULL);
	i = -1;
	while (src[++i])
	{
		p[i] = src[i];
		if (src[i] == '\n')
			break ;
	}
	i++;
	p[i] = '\0';
	free (src);
	return (p);
}
