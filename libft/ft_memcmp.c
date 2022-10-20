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
	int	res;

	res = 0;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		res = res + *(unsigned char *)s1 - *(unsigned char *)s2;
		if (*(unsigned char *)s1 != '\0')
			s1++;
		if (*(unsigned char *)s2 != '\0')
			s2++;
		n--;
		if (*(unsigned char *)s1 == '\0' && *(unsigned char *)s2 == '\0')
			return (res);
	}
	return (res);
}
/*int	main()
{
	printf("%d\n", ft_memcmp("t\200", "t\0", 2));
	printf("%d", memcmp("t\200", "t\0", 2));
}*/
