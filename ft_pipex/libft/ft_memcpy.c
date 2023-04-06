/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:37:20 by dballini          #+#    #+#             */
/*   Updated: 2022/10/04 17:37:21 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*csrc;
	char	*cdest;

	if (!src && !dest)
		return (dest);
	csrc = (char *)src;
	cdest = (char *)dest;
	i = 0;
	while (n > 0)
	{
		cdest[i] = csrc[i];
		n--;
		i++;
	}
	return (dest);
}
