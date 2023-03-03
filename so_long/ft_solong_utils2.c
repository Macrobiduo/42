/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solong_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:01:51 by dballini          #+#    #+#             */
/*   Updated: 2023/03/03 13:08:58 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
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

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;

	len = 0;
	while (s[len])
		len++;
	str = (char *) malloc (len);
	if (!str)
		return (NULL);
	while (*s)
		*str++ = *s++;
	*str = '\0';
	return (str - len);
}
