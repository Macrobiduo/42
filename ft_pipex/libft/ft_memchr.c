/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:25:41 by dballini          #+#    #+#             */
/*   Updated: 2022/10/12 18:25:45 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	t;
	unsigned char	*p;

	p = (unsigned char *)s;
	t = (unsigned char)c;
	while (n > 0)
	{
		if (*p == t)
			return (p);
		p++;
		n--;
	}
	return (NULL);
}
