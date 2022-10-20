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
	char	temp[50];
	size_t	i;

	i = 0;
	while (i < n)
	{
		temp[i] = ((char *)src)[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = temp[i];
		i++;
	}
	return (dest);
}
/*int	main()
{
	char	s[] = "oh asjkfnajnfajs";
	char	t[] = "comadasd";
	
	ft_memmove(s, t, 2);
	printf ("%s\n", s);
	puts(memmove(s, t, 2));
	return (0);
}*/
