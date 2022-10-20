/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:27:37 by dballini          #+#    #+#             */
/*   Updated: 2022/10/05 14:54:22 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	c;
	size_t	d;

	c = 0;
	d = 0;
	while (dest[c] && c < size)
		c++;
	while (src[d] && (c + d + 1) < size)
	{
		dest[c + d] = src[d];
		d++;
	}
	if (c < size)
		dest[c + d] = '\0';
	d = 0;
	while (src[d])
		d++;
	return (c + d);
}
