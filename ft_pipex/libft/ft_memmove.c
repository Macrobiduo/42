/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:33:01 by dballini          #+#    #+#             */
/*   Updated: 2022/10/05 12:33:02 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dest;
	i = 0;
	if (!dest && !src)
		return (dest);
	if (d > s)
		while (n-- > 0)
			d[n] = s[n];
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
