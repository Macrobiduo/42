/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:34:40 by dballini          #+#    #+#             */
/*   Updated: 2022/05/19 17:34:41 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*p;
	unsigned char	*z;

	p = (unsigned char *) s1;
	z = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (p[i] != '\0' && p[i] == z[i] && i < n - 1)
	{
		i++;
	}
	return (p[i] - z[i]);
}
/*int	main()
{
	int	res;
	res = ft_strncmp("", "fsjdf", 2);
	printf("%d\n", res);
}*/
