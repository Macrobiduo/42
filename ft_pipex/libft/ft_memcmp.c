/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:54:12 by dballini          #+#    #+#             */
/*   Updated: 2022/10/05 16:54:13 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*p;
	unsigned char		*s;

	i = 0;
	p = (unsigned char *)s1;
	s = (unsigned char *)s2;
	while (i < n)
	{
		if (p[i] > s[i])
			return (1);
		else if (p[i] < s[i])
			return (-1);
		i++;
	}
	return (0);
}
/*int	main()
{
	printf("%d\n", ft_memcmp("t\200", "t\0", 2));
	printf("%d", memcmp("t\200", "t\0", 2));
}*/
