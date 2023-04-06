/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:21:03 by dballini          #+#    #+#             */
/*   Updated: 2022/10/06 18:21:03 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
