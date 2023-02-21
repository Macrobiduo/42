/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:38:17 by dballini          #+#    #+#             */
/*   Updated: 2022/10/10 15:38:17 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_counter(char const *s, char c)
{
	int		i;

	i = 0;
	if (*s && *s != c)
		i++;
	while (*s && *(s + 1))
	{
		if (*s == c && *(s + 1) != c)
			i++;
		s++;
	}
	return (i + 1);
}

int	leng(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i + 1);
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*p;

	if (nelem == 0 || elsize == 0)
	{
		p = malloc (1);
		return (p);
	}
	else
	{
		p = malloc (nelem * elsize);
		if (!p)
			return (NULL);
		ft_bzero(p, nelem * elsize);
		return (p);
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		total;
	int		len;
	int		i;

	i = 0;
	total = ft_counter(s, c);
	arr = ft_calloc(total * sizeof(char *), 1);
	if (!arr)
		return (NULL);
	while (*s && i < total - 1 && total != 1)
	{
		while (*s == c)
			s++;
		len = leng(s, c);
		arr[i] = malloc(len);
		if (!arr[i])
			return (NULL);
		ft_strlcpy(arr[i], s, len);
		i++;
		s += len - 1;
	}
	return (arr);
}
